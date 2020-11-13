#include <signal.h>
#include <time.h>
#include "graphics.h"
#include "game.h"


static int btn_pressed = 0;
static int highscore = 0;
FILE* fp_gp;


int init_gp()
{
	fp_gp = fopen("/dev/gamepad", "rb");
	if (!fp_gp){
		printf("error fp_gp\n");
	}
	signal(SIGIO, &sigio_handler);
	fcntl(fileno(fp_gp), F_SETOWN, getpid());
	long fileaccess = fcntl(fileno(fp_gp), F_GETFL);
	fcntl(fileno(fp_gp), F_SETFL, fileaccess | FASYNC);
	return EXIT_SUCCESS;
}

void cleanup_gp()
{
	fclose(fp_gp);
}

void initgame(gamestate *gs, settings *set) {
  // init gamestate
  gs->bird_y = ROW/2;
  gs->bird_x = COL/3;
  gs->prev_bird_y = ROW/2;
  gs->velocity = 0;
  gs->score = 0;

  obstacle *ob = malloc(sizeof(obstacle));
  ob->x = COL;
  ob->y = rand() % (ROW - OB_GAP);
  ob->speed = 1; // way to fast 

  gs->ob = ob;

  // init settings
  set->power = 3;
  set->timestep = 1;

  // set background
  paint_rect(0, 0, ROW, COL, BACKGROUND_COLOR);
}

void sigio_handler(gamestate *gs, settings *set)
{
  switch (fgetc(fp_gp)) {
    case BUTTON2:
      btn_pressed = 1;
      break;
    default:
      break;
  }
}


void gameloop(gamestate *gs, settings *set)
{
  clock_t start = CLOCKS_PER_SEC;
   while (1) {
    if (difftime(clock(), start)/CLOCKS_PER_SEC > TIMESTEP){
      start = clock();
      if (!isalive(gs)) {
        break;
      }
      physics(gs, set);
      printgame(gs, set);
    }
  }
}

void physics(gamestate *gs, settings *set)
{
  // flapping
  if (btn_pressed){
    gs->velocity = -set->power;
    btn_pressed = 0;
  }
  
  // gravity
	gs->velocity += 12*TIMESTEP;
  
  // integrate to bird_y
  gs->prev_bird_y = gs->bird_y;
  gs->bird_y += gs->velocity; 
}


int isalive(gamestate *gs) {
  obstacle *ob = gs->ob;
  if ((gs->bird_x > (ob->x - BIRD_W)) && (gs->bird_x < (ob->x + OB_W))) {
	  int bottom = ob->y + OB_GAP - BIRD_H;
	  return ((gs->bird_y > ob->y) && (gs->bird_y < bottom));
  } else if ((gs->bird_y + BIRD_H) > (COL -1)){
	  return 0;
  } else {
    return 1;
  }
}

void printgame(gamestate *gs, settings *set) {
  update_ob(gs); // must be before bird
  update_bird(gs);
  update_score(gs);
}

void update_ob(gamestate *gs){
	obstacle *ob = gs->ob;
  ob->x -= ob->speed;
  if (ob->x <= 0) {
    ob->x = COL;
    ob->y = rand() % (ROW - OB_GAP);
  }
	paint_rect(ob->x, 0, ob->y, 1, OB_COLOR);
	paint_rect(ob->x, ob->y + OB_GAP, ROW - ob->y - OB_GAP, 1, OB_COLOR);

	if ((ob->x + OB_W) < COL){
		paint_rect((ob->x + OB_W), 0, ROW, 1, BACKGROUND_COLOR);
	}else{
		paint_rect(COL - ob->x, 0, ROW, 1, BACKGROUND_COLOR);
	}
}

void update_bird(gamestate *gs){
	paint_rect(gs->bird_x, gs->prev_bird_y, BIRD_H, BIRD_W, BACKGROUND_COLOR);
	paint_bird(gs->bird_x, gs->bird_y);
}

void update_score(gamestate *gs){
	if ((gs->ob->x + OB_W) == gs->bird_x){
    gs->score += SCORE_INC;
    if (gs->score > highscore){
      highscore = gs->score;
    }
  }
  paint_rect(0, 0, SCORE_H, gs->score, YELLOW);
  paint_rect(highscore, 0, SCORE_H, 2, RED);
}

/* Entry point */
int main(){
	init_gp();
	init_fb();
	
	gamestate gs;
	settings set;
  btn_pressed = 0;
  
  while (1) {
		initgame(&gs, &set);
		gameloop(&gs, &set);
	}

	cleanup_gp();
  return EXIT_SUCCESS;
}



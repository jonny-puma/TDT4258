#include <time.h>
#include "graphics.h"
#include "game.h"


FILE* fp_gamepad;

int init_gp(){

	fp_gamepad = fopen("/dev/gamepad", "rb");

	if (!fp_gamepad){
		printf("error fp_gamepad\n");
	}

	signal(SIGIO, &sigio_handler);

	fcntl(fileno(fp_gamepad), F_SETOWN, getpid());

	long fileaccess = fcntl(fileno(fp_gamepad), F_GETFL);

	fcntl(fileno(fp_gamepad), F_SETFL, fileaccess | FASYNC);

	return EXIT_SUCCESS;
}

void cleanup_gamepad(){
	fclose(fp_gamepad);
}

void initgame(gamestate *gs, settings *set) {
  // init gamestate
  gs->bird_y = ROW/2;
  gs->bird_x = COL/3;
  gs->prev_bird_y = COL/4;
  gs->velocity = 0;
  gs->score = 0;

  obstacle *ob = malloc(sizeof(obstacle));
  ob->x = COL;
  ob->y = rand() % (ROW - OB_GAP);
  ob->speed = 1; // way to fast 

  gs->ob = ob;

  // init settings
  set->power = 10;
  set->timestep = 1;
}



void sigio_handler(gamestate *gs, settings *set)
{

	printf("Entered sigio_handler in game.c\n");
	// printf("Signal: %d\n", fgetc(device));
    switch (fgetc(fp_gamepad)) {
        
        case BUTTON2: case BUTTON6:
            printf("UP\n");
			flap(gs, set);
            break;
		default:
			printf("DEFAULT\n"); //Her er verdien 255 av en eller annen grunn..
			break;
    }
}


void gameloop(gamestate *gs, settings *set) {
  while (true) {
    if (!isalive(gs)) {
      break;
    }
	physics(gs, set);
	printgame(gs, set);
  }
}

void physics(gamestate *gs, settings *set) {
  // gravity force
  if (gs->velocity < 1){
  	gs->velocity += set->timestep;
  }

  // integrate to bird_y
  gs->prev_bird_y = gs->bird_y;
  gs->bird_y += gs->velocity*set->timestep; // can be wrong

  // stop at floor
  if (gs->bird_y >= ROW-1) {
    gs->bird_y = ROW/2;
    if (gs->velocity > 0) {
        gs->velocity = 0;
    }
  }

  // move obstacle
  obstacle *ob = gs->ob;
  ob->x -= ob->speed;
  if (ob->x <= 0) {
    ob->x = COL;
    ob->y = rand() % (ROW - OB_GAP);
    //ob->speed++;
  }
}

void flap(gamestate *gs, settings *set){
	gs->velocity -= set->power;
}

bool isalive(gamestate *gs) {
  obstacle *ob = gs->ob;
 // if ((gs->bird_x > (ob->x - BIRD_W)) && (gs->bird_x < (ob->x + OB_W))) {
//	  int bottom = ob->y + OB_GAP - BIRD_H;
//	return ((gs->bird_y > ob->y) && (gs->bird_y < bottom));
 // } else if ((gs->bird_y + BIRD_H) > (COL -1)){
//	  return false;
 // } else {
    return true;
 // }
}

void printgame(gamestate *gs, settings *set) {
  update_ob(gs); // must be before bird
  update_bird(gs);
}

void update_ob(gamestate *gs){
	obstacle *ob = gs->ob;
	paint_square(ob->x, 0, ob->y, 1, OB_COLOR);
	paint_square(ob->x, ob->y + OB_GAP, ROW - ob->y - OB_GAP, 1, OB_COLOR);

	if ((ob->x + OB_W) < COL){
		paint_square((ob->x + OB_W), 0, ROW, 1, BACKGROUND_COLOR);
	}else if (ob->x == 4){
		paint_square(ob->x, 0, ROW, OB_W, BACKGROUND_COLOR);
	}
}

void update_bird(gamestate *gs){
	paint_square(gs->bird_x, gs->prev_bird_y, BIRD_H, BIRD_W, BACKGROUND_COLOR);
	paint_square(gs->bird_x, gs->bird_y, BIRD_H, BIRD_W, BIRD_COLOR);
}


/* Entry point */
int main(){
	printf("Entered main in game.c\n");
	init_gp();
	init_fb();
	backgroundColor(BACKGROUND_COLOR);
	printf("Im done with graphics init\n");

	gamestate gs;
	settings set;


  	while (1) {
		initgame(&gs, &set);
		gameloop(&gs, &set);
	}
	cleanup_gamepad();
    return EXIT_SUCCESS;
}



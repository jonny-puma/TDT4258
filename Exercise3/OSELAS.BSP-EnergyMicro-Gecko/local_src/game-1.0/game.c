#include <stdio.h>
#include <stdlib.h>

FILE* fp_gamepad;

int init_gp(){

	fp_gamepad = fopen("/dev/gamepad", "rb");

	signal(SIGIO, &sigio_handler);

	fcntl(fileno(fp_gamepad), F_SETOWN, getpid());

	long fileaccess = fcntl(fileno(fp_gamepad), F_GETFL);

	fcntl(fileno(fp_gamepad), F_SETFL, fileaccess | FASYNC);

	return EXIT_SUCCESS;
}

void cleanup_gamepad(){
	fclose(fp_gamepad);
}



void up()
{
	printf("UP\n");
	//paint_move_square(0, 16, 0xF800);
	//flush_screen_buffer();
	//printf("screen.dx: %d,     screen.dy: %d\n", screen.dx, screen.dy);
	//paint_square(screen.dx, (screen.dy + 10), 0xF800);
}

void down()
{
	printf("DOWN\n");
	//paint_move_square(0, -16, 0xF800);
	//flush_screen_buffer();
	//printf("screen.dx: %d,     screen.dy: %d\n", screen.dx, screen.dy);
	//paint_square(screen.dx, (screen.dy - 10), 0xF800);
}

void left()
{
	printf("LEFT\n");
	//paint_move_square(-16, 0, 0xF800);
	//flush_screen_buffer();
	//printf("screen.dx: %d,     screen.dy: %d\n", screen.dx, screen.dy);
	//(paint_square((screen.dx - 10), screen.dy, 0xF800);
}

void right()
{
	printf("RIGHT\n");
	//paint_move_square(16, 0, 0xF800);
	//flush_screen_buffer();
	// printf("screen.dx: %d,     screen.dy: %d\n", screen.dx, screen.dy);
	// paint_square((screen.dx + 10), screen.dy, 0xF800);
}


void sigio_handler()
{
//Knappen til venstre:
// LEFT = 	254 = FE = 11111110 = SW1
// RIGHT = 	251 = FB = 11111011 = SW3
// UP = 	253 = FD = 11111101 = SW2
// DOWN = 	247 = F7 = 11110111 = SW4
//Knappene på høyre side er:
// LEFT = 	239 = EF = 11101111 = SW5
// RIGHT = 	191 = BF = 10111111 = SW7
// UP = 	223 = DF = 11011111 = SW6
// DOWN = 	127 = 7F = 01111111 = SW8

	//printf("Signal: %d\n", fgetc(device));
    switch (fgetc(fp_gamepad)) {
        case BUTTON1: case BUTTON5:
            left();
            break;
        case BUTTON3: case BUTTON7:
            right();
            break;
        case BUTTON2: case BUTTON6:
            up();
            break;
        case BUTTON4: case BUTTON8:
            down();
            break;
		default:
			printf("DEFAULT\n"); //Her er verdien 255 av en eller annen grunn..
			break;
    }
}




/* Entry point */
int main(){
	printf("Entered main in game.c\n");
	init_gamepad();

	//init_fb();
	printf("Im done with graphics init\n");
	//paint_background(0xFFFF);
	//background();
	//printf("Im done with background\n");

	//paint_screenangle(0xF800, x, y, 320, 240);
	//paint_square(0, 0, 0xF800);
	//paint_move_square(-10, 0, 0xF800);
	//flush_screen_buffer()
	//int i;
  	while (1) {
		// for (i = 0; i < 20 ; i++){
		// 	if ((i % 10) == 0){
		// 		refresh_screen();	
		// 	}
		// }
		// i = 0;

		//refresh_screen();
		//pause();
			
	}
	cleanup_gamepad();
    return EXIT_SUCCESS;
}

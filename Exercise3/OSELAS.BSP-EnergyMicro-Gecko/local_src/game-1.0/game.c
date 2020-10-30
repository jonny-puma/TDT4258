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



void up()
{
	printf("UP\n");
	paint_square(5, 5, 50, 60, 0x2299);
}

void down()
{
	printf("DOWN\n");
	paint_square(100, 100, 30, 30, 0x4444);
	
}

void left()
{
	printf("LEFT\n");
	backgroundColor(0xf0f0);
	
}

void right()
{
	printf("RIGHT\n");
	backgroundColor(0x3333);
	
}


void sigio_handler()
{

	printf("Entered sigio_handler in game.c\n");
	// printf("Signal: %d\n", fgetc(device));
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
	init_gp();
	init_fb();
	backgroundColor(0xffff);
	printf("Im done with graphics init\n");

  	while (1) {
	}
	cleanup_gamepad();
    return EXIT_SUCCESS;
}

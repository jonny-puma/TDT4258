#include "graphics.h"
#include "stdlib.h"


int fbfd; // framebuffer device
uint16_t *fbp; // one pixel 

static int screen_pixels;
static int screen_bytes;
 //size of screen

struct fb_copyarea screen;

static int array_size = SCREEN_PIXEL_WIDTH*SCREEN_PIXEL_HEIGHT;
// static int BACKGROUND_COLOR = WHITE;
static int reddd = 0xF800;

#define COLOR_SILVER 0xC0C0


void init_fb()
{
    fbfd = open("/dev/fb0", O_RDWR); //open with read and write
    if (fbfd == -1) {
        printf("Error when opening framebuffer.\n");
    }

    //size of screen
    screen.dx = 0;
    screen.dy = 0;
    screen.width = SCREEN_PIXEL_WIDTH;
    screen.height = SCREEN_PIXEL_HEIGHT;

    int screen_pixels = SCREEN_PIXEL_WIDTH*SCREEN_PIXEL_HEIGHT; 
    int screen_bytes = screen_pixels * 2; //2 bytes per pixel (16 bit)

    // map pixels to array;
    fbp = (uint16_t*)mmap(NULL, screen_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    
    if ((int)fbp == MAP_FAILED) {
        printf("Error, failed to memorymap framebuffer.\n");
    }
   
}

void flush_screen_buffer(){
	if (ioctl(fbfd, 0x4680, &screen) == -1){
        printf("ERROR in ioctl!\n");
    }
    //printf("The status of screen \n screen.dx: %d,     screen.dy: %d,\nscreen.width: %d,       screen.height: %d\n", screen.dx, screen.dy, screen.width, screen.height);
    //printf("\nI have refreshed the screen\n\n");
}

void deinit_fb()
{
    munmap(fbp, screen_bytes);
    close(fbfd);
}


void backgroundColor(int16_t color){
    screen.dx = 0;
    screen.dy = 0;
    screen.width = SCREEN_PIXEL_WIDTH;
    screen.height = SCREEN_PIXEL_HEIGHT;
    int i;
     for ( i = 0; i < array_size; i++) {
        fbp[i] = color;
    }
    flush_screen_buffer();
}

void paint_square(int pos_x, int pos_y, int height, int width, int16_t color){
    screen.dx = pos_x;
    screen.dy = pos_y;
    screen.width = width;
    screen.height = height;
    int i;
    int j;
	for(i = screen.dx; i < screen.dx + screen.width; i++){
		for(j = screen.dy; j < screen.dy + screen.height; j++){
			fbp[i + j * SCREEN_PIXEL_WIDTH] = color;
		}
	}
    flush_screen_buffer();
    //printf("\nI have refresed the screen\n");
}

void paint_bird(int pos_x, int pos_y){
    screen.dx = pos_x;
    screen.dy = pos_y;
    screen.width = 17;
    screen.height = 12;
    int i;
    int j;
	for(i = screen.dx; i < screen.dx + screen.width; i++){
		for(j = screen.dy; j < screen.dy + screen.height; j++){
			fbp[i + j * SCREEN_PIXEL_WIDTH] = birdArray[i + j*screen.width];
		}
	}
    flush_screen_buffer();
}
#include "graphics.h"
#include "stdlib.h"


int fbfd; // framebuffer device
uint16_t *fbp; // one pixel 

static int screen_pixels;
static int screen_bytes;
struct fb_copyarea screen;
static int array_size = COL*ROW;

void init_fb()
{
    fbfd = open("/dev/fb0", O_RDWR); //open with read and write
    if (fbfd == -1) {
        printf("Error when opening framebuffer.\n");
    }

    //size of screen
    screen.width = COL;
    screen.height = ROW;

    int screen_pixels = COL*ROW; 
    int screen_bytes = screen_pixels * 2; //2 bytes per pixel (16 bit)

    // map pixels to array;
    fbp = (uint16_t*)mmap(NULL, screen_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    
    if ((int)fbp == MAP_FAILED) {
        printf("Error, failed to memorymap framebuffer.\n");
    }
    paint_rect(0, 0, ROW, COL, BACKGROUND_COLOR);
   
}

void flush_screen_buffer()
{
	if (ioctl(fbfd, 0x4680, &screen) == -1){
        printf("ERROR in ioctl!\n");
    }
}

void deinit_fb()
{
    munmap(fbp, screen_bytes);
    close(fbfd);
}

void paint_rect(int pos_x, int pos_y, int height, int width, int16_t color)
{
    // area to be written to screen
    screen.dx = pos_x;
    screen.dy = pos_y;
    screen.width = width;
    screen.height = height;
    int x;
    int y;
    for(x=0; x<width; x++){
      for(y=0; y<height; y++){
        fbp[x + pos_x + (y + pos_y)*COL] = color;
      }
    }
    flush_screen_buffer();
}

void paint_bird(int pos_x, int pos_y)
{
    // area to be written to screen
    screen.dx = pos_x;
    screen.dy = pos_y;
    screen.width = BIRD_W;
    screen.height = BIRD_H;
    int x;
    int y;
    for(y=0; y<BIRD_H; y++){
      for(x=0; x<BIRD_W; x++){
        if (birdArray[x + y*BIRD_W] != TRANS){
            fbp[x + pos_x + (y + pos_y)*COL] = birdArray[x + y*BIRD_W];
        }
      }
    }
    flush_screen_buffer();
}

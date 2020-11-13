#include "graphics.h"
#include "stdlib.h"


// frame buffer device and pixel array map
int fb_dev;
uint16_t *fb_pxl;

static int screen_pixels;
static int screen_size;
struct fb_copyarea copyarea;
static int array_size = COL*ROW;

void init_fb()
{
    // open with read and write permission
    fb_dev = open("/dev/fb0", O_RDWR); 

    if (fb_dev == -1) {
        printf("Error: could not open FB.\n");
    }

    //size of screen
    copyarea.width = COL;
    copyarea.height = ROW;

    int screen_pixels = COL*ROW; 
    int screen_size = screen_pixels*sizeof(uint16_t);

    // map pixels to array;
    fb_pxl = (uint16_t*)mmap(NULL, screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fb_dev, 0);
    
    if ((int)fb_pxl == MAP_FAILED) {
        printf("Error: could not map FB.\n");
    }

    // clear screen
    paint_rect(0, 0, ROW, COL, BACKGROUND_COLOR);
   
}

void flush_screen()
{
	if (ioctl(fb_dev, 0x4680, &copyarea) == -1) {
        printf("Screen flush failed\n");
    }
}

void free_fb()
{
    munmap(fb_pxl, screen_size);
    close(fb_dev);
}

void paint_rect(int x, int y, int height, int width, int16_t color)
{
    // area to be flushed
    copyarea.dx = x;
    copyarea.dy = y;
    copyarea.width = width;
    copyarea.height = height;
    int dx;
    int dy;
    for(dx=0; dx<width; dx++) {
      for(dy=0; dy<height; dy++) {
        fb_pxl[x + dx + (y + dy)*COL] = color;
      }
    }
    flush_screen();
}

void paint_bird(int x, int y)
{
    // area to be flushed
    copyarea.dx = x;
    copyarea.dy = y;
    copyarea.width = BIRD_W;
    copyarea.height = BIRD_H;
    int dx;
    int dy;
    for(dy=0; dy<BIRD_H; dy++) {
      for(dx=0; dx<BIRD_W; dx++) {
        if (birdArray[dx + dy*BIRD_W] != TRANS) {
            fb_pxl[x + dx + (y + dy)*COL] = birdArray[dx + dy*BIRD_W];
        }
      }
    }
    flush_screen();
}

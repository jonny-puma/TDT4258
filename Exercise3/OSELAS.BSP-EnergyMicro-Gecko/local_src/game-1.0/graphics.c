#include "graphics.h"
#include "stdlib.h"


// frame buffer device and pixel array map
int fb_dev;
uint16_t *fb_pxl;

static int screen_pixels;
static int screen_size;
struct fb_copyarea screen;
static int array_size = COL*ROW;

void init_fb()
{
    // open with read and write permission
    fb_dev = open("/dev/fb0", O_RDWR); 
    if (fb_dev == -1) {
        printf("Error when opening framebuffer.\n");
    }

    //size of screen
    screen.width = COL;
    screen.height = ROW;

    int screen_pixels = COL*ROW; 
    int screen_size = screen_pixels*sizeof(uint16_t);

    // map pixels to array;
    fb_pxl = (uint16_t*)mmap(NULL, screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fb_dev, 0);
    
    if ((int)fb_pxl == MAP_FAILED) {
        printf("Error, failed to map framebuffer.\n");
    }

    // clear screen
    paint_rect(0, 0, ROW, COL, BACKGROUND_COLOR);
   
}

void flush_screen()
{
	if (ioctl(fb_dev, 0x4680, &screen) == -1) {
        printf("Screen flush failed, ERROR in ioctl!\n");
    }
}

void deinit_fb()
{
    munmap(fb_pxl, screen_size);
    close(fb_dev);
}

void paint_rect(int x, int y, int height, int width, int16_t color)
{
    // area to be flushed
    screen.dx = x;
    screen.dy = y;
    screen.width = width;
    screen.height = height;
    int dx;
    int dy;
    for(dx=0; dx<width; x++) {
      for(dy=0; dy<height; y++) {
        fb_pxl[x + dx + (y + dy)*COL] = color;
      }
    }
    flush_screen();
}

void paint_bird(int x, int y)
{
    // area to be flushed
    screen.dx = x;
    screen.dy = y;
    screen.width = BIRD_W;
    screen.height = BIRD_H;
    int dx;
    int dy;
    for(dy=0; dy<BIRD_H; y++) {
      for(dx=0; dx<BIRD_W; x++) {
        if (birdArray[dx + dy*BIRD_W] != TRANS) {
            fb_pxl[x + dx + (y + dy)*COL] = birdArray[dx + dy*BIRD_W];
        }
      }
    }
    flush_screen();
}

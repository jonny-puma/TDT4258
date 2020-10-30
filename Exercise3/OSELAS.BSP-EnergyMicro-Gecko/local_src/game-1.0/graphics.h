
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>


#define SCREEN_PIXEL_HEIGHT 240
#define SCREEN_PIXEL_WIDTH  320



void paint_square(int pos_x, int pos_y, int height, int width, int16_t color);
void backgroundColor(int16_t color);
void deinit_fb();
void flush_screen_buffer();
void init_fb();

#endif
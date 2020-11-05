
#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#define TRANS -1
#define BLACK 0x0000
#define WHITE 0xFFFF
#define YELLOW 0xFF00
#define RED 0xF800


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
void paint_bird(int pos_x, int pos_y);

static int birdArray[] = {  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,
                            TRANS,  TRANS,  TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  WHITE,  BLACK,  TRANS,  TRANS,  TRANS, 
                            TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  BLACK,  WHITE,  BLACK,  TRANS,  TRANS
                            BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  BLACK,  WHITE,  BLACK,  TRANS,  TRANS, 
                            BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  WHITE,  BLACK,  TRANS,  TRANS, 
                            BLACK,  YELLOW, WHITE,  WHITE,  WHITE,  YELLOW, BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,
                            TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    RED,    RED,    RED,    RED,    BLACK, 
                            TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    RED,    RED,    RED,    BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS}


#endif
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

// Colors
#define TRANS -1
#define BLACK 0x0000
#define WHITE 0xFFFF
#define YELLOW 0xFF00
#define RED 0xF800
#define BIRD_COLOR 0x3333
#define OB_COLOR 0x1414
#define BACKGROUND_COLOR 0xffff

// sprite dimensions
#define BIRD_H 12
#define BIRD_W 17

// height of score bar
#define SCORE_H 8
#define SCORE_INC 2

// screen size
#define ROW 240
#define COL 320


void paint_rect(int pos_x, int pos_y, int height, int width, int16_t color);
void free_fb();
void flush_screen();
void init_fb();
void paint_bird(int pos_x, int pos_y);

// Bird sprite
static int birdArray[] = {  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,
                            TRANS,  TRANS,  TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  WHITE,  BLACK,  TRANS,  TRANS,  TRANS, 
                            TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  BLACK,  WHITE,  BLACK,  TRANS,  TRANS,
                            BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  BLACK,  WHITE,  BLACK,  TRANS,  TRANS, 
                            BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  WHITE,  WHITE,  WHITE,  BLACK,  TRANS,  TRANS, 
                            BLACK,  YELLOW, WHITE,  WHITE,  WHITE,  YELLOW, BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,
                            TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    RED,    RED,    RED,    RED,    BLACK, 
                            TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  RED,    RED,    RED,    RED,    BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  YELLOW, YELLOW, YELLOW, YELLOW, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS, 
                            TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  BLACK,  BLACK,  BLACK,  BLACK,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS};

#endif

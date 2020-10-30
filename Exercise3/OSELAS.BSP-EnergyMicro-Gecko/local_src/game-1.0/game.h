#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "graphics.h"

#define BUTTON1 0xFE
#define BUTTON2 0xF7
#define BUTTON3 0xFB
#define BUTTON4 0xFD
#define BUTTON5 0xEF
#define BUTTON6 0x7F
#define BUTTON7 0xBF
#define BUTTON8 0xDF

int init_gamepad();
void cleanup_gamepad();
void sigio_handler();
void up();
void down();
void left();
void right();
int main();
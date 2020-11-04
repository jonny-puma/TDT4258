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

#define ROW 240
#define COL 320
#define OB_W 10

#define BIRD_COLOR 0x3333
#define BIRD_H 8
#define BIRD_W 8

#define OB_GAP 40
#define OB_COLOR 0x1414

#define BACKGROUND_COLOR 0xffff

typedef struct {
	int timestep;
	int power;
} settings;

typedef struct {
  int x;
  int y;
  int speed;
} obstacle;

typedef struct {
	int bird_y;
  int bird_x;
  int prev_bird_y;
	int velocity;
	int score;
  obstacle *ob;
} gamestate;

int init_gp();
void cleanup_gamepad();
void sigio_handler(gamestate *gs, settings *set);
void initgame(gamestate *gs, settings *set);
void gameloop(gamestate *gs, settings *set);
void physics(gamestate *gs, settings *set);
bool isalive(gamestate *gs);
void printgame(gamestate *gs, settings *set);
void update_ob(gamestate *gs);
void update_bird(gamestate *gs);
int main();
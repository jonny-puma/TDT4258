#define BUTTON2 0xFD


// obstacle dimensions
#define OB_W 10
#define OB_GAP 75

#define TIMESTEP 0.01

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
	float velocity;
	int score;
  obstacle *ob;
} gamestate;

int init_gp();
void cleanup_gamepad();
void sigio_handler();
void initgame(gamestate *gs, settings *set);
void gameloop(gamestate *gs, settings *set);
void physics(gamestate *gs, settings *set);
int isalive(gamestate *gs);
void printgame(gamestate *gs, settings *set);
void update_score(gamestate *gs);
void update_ob(gamestate *gs);
void update_bird(gamestate *gs);
int main();

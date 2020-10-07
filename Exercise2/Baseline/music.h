// Frequency for given notes in Hz. Number indicates octave.
#define B6 1975.53
#define E7 2637.02

#define A5 880
#define B5 987.767
#define C5 523.251
#define F5 698.456
#define G5 783.991
#define E5 659.255

#define B4 493.883
#define C4 261.626
#define D4 293.665

#define A3 220.000
#define dA3 207.652

#define A2 110.000
#define dA2 103.826


typedef enum {
  FLAAKLYPA,
  COIN,
  JUMP,
  DEATH
} songname;

typedef struct {
    struct note *notes;
    uint32_t playhead;
    uint32_t duration;
} song;

typedef struct {
    float freq;
    float sec;
} note;

songname *currentsong = NULL;

void setupMusic();
void playnote();
void changesong(songname name);
uint32_t synthesiseWave();
void increaseVolume();
void decreaseVolume();
void increaseTicks();

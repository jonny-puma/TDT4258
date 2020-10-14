#ifndef MUSIC_H
#define MUSIC_H
#include <stdint.h>

// Frequency for given notes in Hz. Number indicates octave.
#define B6 1975
#define E7 2637
#define A5 880
#define B5 987
#define C5 523
#define F5 698
#define G5 783
#define E5 659
#define B4 493
#define C4 261
#define D4 293
#define A3 220
#define dA3 207
#define dA2 103
//-----------------------------------------------------------

typedef struct {
    int32_t freq;
    int32_t duration_ticks;
} note_t;

typedef struct {
    note_t *notes;
    uint32_t nr_notes;
} sound_t;

typedef enum {
  NONE,
  FLAAKLYPA,
  COIN,
  CRASH,
  FLAP
} soundname;

uint32_t volume;

void playsound();

void setsound(soundname new_sound);

void decreasevol();
    
void increasevol();

soundname *current_sound;
#endif

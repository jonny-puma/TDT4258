#ifndef MUSIC_H
#define MUSIC_H
#include <stdint.h>

// Frequency for given notes in Hz. Number indicates octave.
#define B6 1975*2
#define E7 2637*2
#define A5 880*2
#define B5 987*2
#define C5 523*2
#define F5 698*2
#define G5 783*2
#define E5 659*2
#define B4 493*2
#define C4 261*4
#define D4 293*4
#define A3 220*4
#define dA3 207*8
#define dA2 103*8
//-----------------------------------------------------------

typedef struct {
    int32_t freq;
    int32_t duration_ticks;
} note_t;

typedef struct {
    note_t *notes;
    int nr_notes;
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
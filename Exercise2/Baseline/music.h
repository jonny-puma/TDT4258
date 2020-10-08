<<<<<<< HEAD
/*
{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4
{.freq = A3 (2)
{.freq = dA (2)
{.freq = A3 (2)

{.freq = A3 (2)
{.freq = A5
{.freq = G5
{.freq = F5
{.freq = E5
{.freq = B5
{.freq = A3 
{.freq = B4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = E5

{.freq = A3 (2)
{.freq = A5
{.freq = G5
{.freq = F5
{.freq = E5
{.freq = B5
{.freq = A3 
{.freq = B4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = E5

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4
{.freq = A3 (2)
{.freq = dA (2)
{.freq = A3 (2)
*/

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

struct song{
    struct note *notes;
    uint32_t playhead;
    uint32_t duration;
};

struct note{
    uint32_t freq;
    uint32_t sec;
};

void setupMusic();

void updateNote();

void resetSong();

uint32_t synthesiseWave();

void increaseVolume();

void decreaseVolume();

void increaseTicks();
=======
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

void playsound(soundname *current_sound);

void setsound(soundname new_sound);

void decreasevol();
    
void increasevol();
#endif
>>>>>>> jonas3

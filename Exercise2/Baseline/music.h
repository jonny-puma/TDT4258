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

#include <stdint.h>

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

typedef struct 
{
    int32_t freq;
    int32_t duration_ticks;
} note_t;

typedef struct 
{
    note_t *notes;
    int nr_notes;
} song_t;

typedef struct {
    song_t *song_playing;
    int note_idx;
    int ticks;
} song_handle_t;


void playMelody();

bool medoldyFinished();

void resetSong( uint32_t C );

void decreaseVolume();
    
void increaseVolume();

void setupMusic();

uint32_t synthesiseWave();
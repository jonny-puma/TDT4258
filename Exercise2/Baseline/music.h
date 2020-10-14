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

typedef struct 
{
    uint32_t freq;
    uint32_t duration_ticks;
} note_t;

typedef struct 
{
    note_t *notes;
    uint32_t nr_notes;
} song_t;

typedef struct {
    song_t *song_playing;
    uint32_t note_idx;
    uint32_t ticks;
} song_handle_t;


int playMelody( int C );

void resetSong( int C );

void decreaseVolume();
    
void increaseVolume();

void setupMusic();

uint32_t synthesiseWave();
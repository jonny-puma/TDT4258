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
#define A2 110
#define dA2 103
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


int playMelody( int C );

void resetSong( int C );

void decreaseVolume();
    
void increaseVolume();

void setupMusic();

uint32_t synthesiseWave();
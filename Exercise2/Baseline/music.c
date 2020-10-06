#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

struct note flaaklypa_notes[] =
{   
    {.freq = E5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = C5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = C5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = dA3, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = C5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = F5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = C5, .sec = 0.8},
    {.freq = B5, .sec = 0.8},
    {.freq = A5, .sec = 0.8},
    {.freq = G5, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = E5, .sec = 0.8},
    {.freq = D4, .sec = 0.8},
    {.freq = C4, .sec = 0.8},
    {.freq = B4, .sec = 0.8},
    {.freq = A3, .sec = 0.8},
    {.freq = dA3, .sec = 0.8},
    {.freq = A3, .sec = 0.8}
};

struct note coin_notes[]=
{
    {.freq = B6, .sec = 0.3},
    {.freq = E7, .sec = 0.5}
};

struct note jump_notes[]=
{
    {.freq = B6, .sec = 0.3},
    {.freq = E7, .sec = 0.5}
};

struct note death_notes[]=
{
    {.freq = B6, .sec = 0.3},
    {.freq = E7, .sec = 0.5}
};

struct song flaaklypa=
{
    .notes = &flaaklypa_notes,
    .playhead = 0,
    .duration = 6969
};

struct song coin=
{
    .notes = &coin_notes,
    .playhead = 0,
    .duration = 6969
};

struct song jump=
{
    .notes = &jump_notes,
    .playhead = 0,
    .duration = 6969
};

struct song death=
{
    .notes = &death_notes,
    .playhead = 0,
    .duration = 6969
};

void updateNote(){
    //Start a song for the first time
    if (*ticks > current_song->notes[current_song->playhead].sec * FREQUENCY){
        current_song->playhead++;
        // Might be redundant
        *ticks = 0;
    }
    if (current_song->playhead > current_song->duration){
        current_song->playhead = 0;
        *ticks = 0;
        // *CURRENT_SONG = NONE;
    }else{
        uint32_t val = synthesiseWave();
        *DAC0_CH0DATA = val;
        *DAC0_CH1DATA = val;
    }
}

uint32_t synthesiseWave(){
    int num_ticks = FREQUENCY/current_song->notes[current_song->playhead].freq;
    if (num_ticks % *ticks > num_ticks/2){
        return volume;
    }else{
        return 0;
    }
}

void resetSong(){
    switch (*CURRENT_SONG){
        case FLAAKLYPA:
            current_song = &flaaklypa;
            break;

        case COIN:
            current_song = &coin;
            break;

        case JUMP:
            current_song = &jump;
            break;

        case DEATH:
            current_song = &death;
            break;

        default:
            // set none
            break;
    }
    current_song->playhead = 0;
}
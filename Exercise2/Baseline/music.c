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
    .notes = flaaklypa_notes,
    .playhead = 0,
    .duration = 6969
};

struct song coin=
{
    .notes = coin_notes,
    .playhead = 0,
    .duration = 6969
};

struct song jump=
{
    .notes = jump_notes,
    .playhead = 0,
    .duration = 6969
};

struct song death=
{
    .notes = death_notes,
    .playhead = 0,
    .duration = 6969
};

void setupMusic(){
    *volume = 0x1000;
    *CURRENT_SONG = NONE;
    *ticks = 0;
}

void updateNote(){
    // Checking if song is finished
    if (current_song->playhead > current_song->duration){
        *ticks = 0;
        *CURRENT_SONG = NONE;
    
    }else{
        // Checking if next note 
        if (*ticks > current_song->notes[current_song->playhead].sec * FREQUENCY){
            (current_song->playhead)++;
            *ticks = 0;
        }else{
            (*ticks)++; 
        }
        // Synthesising square wave for the tones frequency 
        
        uint32_t val = synthesiseWave();
        *GPIO_PA_DOUT = (val)<<8;
        // Outputting to DAC
        *DAC0_CH0DATA = val;
        *DAC0_CH1DATA = val;
    }
}

uint32_t synthesiseWave(){
    uint32_t num_ticks = FREQUENCY/current_song->notes[current_song->playhead].freq;
    // Alternating between high and low.
    if (*ticks % num_ticks > num_ticks/2){
        return *volume;
    }else{
        return 0;
    }
}

void resetSong(){
    switch (*CURRENT_SONG){
        case FLAAKLYPA:
            //*GPIO_PA_DOUT = (0xfe)<<8;
            current_song = &flaaklypa;
            //*current_song = flaaklypa;
            break;

        case COIN:
            //*GPIO_PA_DOUT = (0xfd)<<8;
            current_song = &coin;
            //*current_song = coin;
            break;

        case JUMP:
            //*GPIO_PA_DOUT = (0xfc)<<8;
            //current_song = &jump;
            *current_song = jump;
            break;

        case DEATH:
            //*GPIO_PA_DOUT = (0xfb)<<8;
            //current_song = &death;
            *current_song = death;
            break;

        default:
            // Do nothing
            break;
    }
    current_song->playhead = 0;
}

// Simply multiply or divide volume by each time since sound is logarithmic(?)
void increaseVolume(){
    *volume = (*volume) << 1;
}

void decreaseVolume(){
    *volume = (*volume) >> 1;
}

#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

static song_handle_t song_h;
uint32_t *volume;

note_t coin_notes[] = {
    {B6, 3},
    {E7, 5}
};

song_t coin_song = {coin_notes, 2};

void setupMusic(){
    *volume = 512;
    *CURRENT_SONG = NONE;
}


void playMelody(){

    // Checking if its time for the next note 
    if (song_h.ticks > song_h.song_playing->notes->duration_ticks){
        song_h.note_idx++;
        song_h.song_playing->notes++;
        song_h.ticks = 0;
    }

    // Synthesising square wave for the tones frequency 
    uint32_t val = synthesiseWave();
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;


    // Checking if song is finished
    if ((song_h.note_idx + 1) == song_h.song_playing->nr_notes){
        *CURRENT_SONG = NONE;
    }
}

uint32_t synthesiseWave(){
    int n_ticks = FREQUENCY/song_h.song_playing->notes->freq;

    if (n_ticks % song_h.ticks > n_ticks/2){
        return *volume;
    }else{
        return 0;
    }
}

void resetSong(){
    switch (*CURRENT_SONG){
        case COIN:
            song_h.song_playing = &coin_song;
            break;
        default:
            break;
    }
    song_h.note_idx = 0;
    song_h.ticks = 0;
}

void decreaseVolume(){
    *volume = *volume << 1;
}

void increaseVolume(){
    *volume = *volume >> 1;
}
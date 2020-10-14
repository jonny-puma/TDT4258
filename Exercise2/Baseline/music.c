#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

static song_handle_t song_h;
uint32_t *volume;

note_t coin_notes[] = {
    {B6, 500},
    {B4, 1000}
};



note_t flaa_notes[] =
 {
    { E5, 4500},
    { A5, 4500},
    { B5, 4500},
    { C5, 3000},
    { B5, 3000},
    { A5, 6000},
    { G5, 2500},
    { E5, 2500},
    { C4, 5500},
    { D4, 2500},
    { E5, 2500},
    { F5, 5500},
    { E5, 3500},
    { D4, 3500},
    { C4, 3500},
    { D4, 3500},
    { E5, 3500},
    { D4, 3500},
    { C4, 3500},
    { B4, 3500},
    { E5, 3500},
    { A5, 3500},
    { B5, 3500},
    { C5, 3500},
    { B5, 3500},
    { A5, 3500},
    { G5, 3500},
    { E5, 3500},
    { C4, 3500},
    { D4, 3500},
    { E5, 3500},
    { D4, 3500},
    { C4, 3500},
    { B4, 3500},
    { A3, 3500},
    { dA3, 3500},
    { A3, 3500},
    { A3, 3500},
    { A5, 3500},
    { G5, 3500},
    { F5, 3500},
    { E5, 3500},
    { B5, 3500},
    { A3, 3500},
    { B4, 3500},
    { C4, 3500},
    { D4, 3500},
    { E5, 3500},
    { F5, 3500},
    { E5, 3500},
    { D4, 3500},
    { E5, 3500},
    { A3, 3500}
};


song_t coin_song = {coin_notes, 2};
song_t fla_song  = {flaa_notes, 50};

void setupMusic(){
    *volume = 1024;
}


int playMelody( int C ){
    song_h.ticks++;

    uint32_t val = synthesiseWave();
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;

    // Checking if its time for the next note 
    if (song_h.ticks > song_h.song_playing->notes[song_h.note_idx].duration_ticks){
        song_h.note_idx++;
        song_h.ticks = 0;
    }

    // Checking if song is finished
    if ((song_h.note_idx)  == song_h.song_playing->nr_notes){
        return 0;
    } else
    {
        return C;
    }
    
}

uint32_t synthesiseWave(){
    int n_ticks = FREQUENCY/song_h.song_playing->notes[song_h.note_idx].freq;

    if ((song_h.ticks % n_ticks) > n_ticks/2){
        return *volume;
    }else{
        return 0;
    }
}

void resetSong( int C ){
    switch (C){
        case 1:
            song_h.song_playing = &fla_song;
            break;
        case 2:
            song_h.song_playing = &coin_song;
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
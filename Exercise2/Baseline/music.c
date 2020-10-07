#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

static song_handle_t song_h;
uint32_t *volume;

note_t coin_notes[] = {
    {B6, 2000},
    {B4, 3500}
};

note_t flaa_notes[] = {

    { E5, 9000},
    { A5, 9000},
    {  B5, 9000},
    { C5, 9000},
    { B5, 9000},
    { A5, 9000},
    { G5, 9000},
    { E5, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { F5, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { B4, 9000},
    { E5, 9000},
    { A5, 9000},
    { B5, 9000},
    { C5, 9000},
    { B5, 9000},
    { A5, 9000},
    { G5, 9000},
    { E5, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { B4, 9000},
    { A3, 9000},
    { dA3, 9000},
    { A3, 9000},
    { A3, 9000},
    { A5, 9000},
    { G5, 9000},
    { F5, 9000},
    { E5, 9000},
    { B5, 9000},
    { A3, 9000},
    { B4, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { F5, 9000},
    { E5, 9000},
    { D4, 9000},
    { E5, 9000},
    { A3, 9000},
    { A5, 9000},
    { G5, 9000},
    { F5, 9000},
    { E5, 9000},
    { B5, 9000},
    { A3, 9000},
    { B4, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { F5, 9000},
    { E5, 9000},
    { D4, 9000},
    { E5, 9000},
    { E5, 9000},
    { A5, 9000},
    { B5, 9000},
    { C5, 9000},
    { B5, 9000},
    { A5, 9000},
    { G5, 9000},
    { E5, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { F5, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { B4, 9000},
    { E5, 9000},
    { A5, 9000},
    { B5, 9000},
    { C5, 9000},
    { B5, 9000},
    { A5, 9000},
    { G5, 9000},
    { E5, 9000},
    { C4, 9000},
    { D4, 9000},
    { E5, 9000},
    { D4, 9000},
    { C4, 9000},
    { B4, 9000},
    { A3, 9000},
    { dA3, 9000},
    { A3, 9000}
};


song_t coin_song = {coin_notes, 2};
song_t fla_song = {flaa_notes, 103};

void setupMusic(){
    *volume = 1024;
}


int playMelody( int C ){
    (song_h.ticks)++;

    // Synthesising square wave for the tones frequency 
    uint32_t val = synthesiseWave();
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;

    // Checking if its time for the next note 
    if (song_h.ticks > song_h.song_playing->notes[song_h.note_idx].duration_ticks){
        song_h.note_idx++;
        song_h.ticks = 0;
    }
    // Checking if song is finished
    if ((song_h.note_idx + 1)  == song_h.song_playing->nr_notes){
        return 0;
    } else
    {
        return C;
    }
    
}

uint32_t synthesiseWave(){
    int n_ticks = FREQUENCY/song_h.song_playing->notes[song_h.note_idx].freq;

    if ((song_h.ticks % n_ticks) > n_ticks/2){
        return 1000;
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
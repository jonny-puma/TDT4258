#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

struct note_t crash_notes[] = {
    {4, 0.05},
    {6, 0.05},
    {9, 0.05},
    {15, 0.05},
    {23, 0.05},
    {33, 0.05},
    {45, 0.05},
    {62, 0.05},
    {23, 0.05},
    {33, 0.05},
    {9, 0.05},
    {15, 0.05},
    {4, 0.05},
    {6, 0.05},
};

note_t coin_notes[] = {
    {B6, 1000},
    {B4, 1500}
};

note_t flaa_notes[] = {
    {E5, 4500},
    {A5, 4500},
    {B5, 4500},
    {C5, 3000},
    {B5, 3000},
    {A5, 6000},
    {G5, 2500},
    {E5, 2500},
    {C4, 5500},
    {D4, 2500},
    {E5, 2500},
    {F5, 5500},
    {E5, 3500},
    {D4, 3500},
    {C4, 3500},
    {D4, 3500},
    {E5, 3500},
    {D4, 3500},
    {C4, 3500},
    {B4, 3500},
    {E5, 3500},
    {A5, 3500},
    {B5, 3500},
    {C5, 3500},
    {B5, 3500},
    {A5, 3500},
    {G5, 3500},
    {E5, 3500},
    {C4, 3500},
    {D4, 3500},
    {E5, 3500},
    {D4, 3500},
    {C4, 3500},
    {B4, 3500},
    {A3, 3500},
    {dA3, 3500},
    {A3, 3500},
    {A3, 3500},
    {A5, 3500},
    {G5, 3500},
    {F5, 3500},
    {E5, 3500},
    {B5, 3500},
    {A3, 3500},
    {B4, 3500},
    {C4, 3500},
    {D4, 3500},
    {E5, 3500},
    {F5, 3500},
    {E5, 3500},
    {D4, 3500},
    {E5, 3500},
    {A3, 3500}
};

note_t flap_notes[] = {
  {C5, 500},
  {B5, 500},
  {A5, 500}
};

sound_t coin_sound = {coin_notes, 2};
sound_t fla_sound = {flaa_notes, 103};
sound_t crash_sound = {crash_notes, 13};
sound_t flap_sound = {flap_notes, 3};

int ticks = 0;
int note_idx = 0;
sound_t *sound_data = &fla_sound;

uint32_t synthesize(int frequency)
{
    int duration_ticks = DAC_FRQ/frequency;

    if ((ticks % duration_ticks) > duration_ticks/2) {
        return volume;
    } else {
        return 0;
    }
}

void playsound(soundname *current_sound)
{
    ticks++; 
    note_t current_note = sound_data->notes[note_idx];

    // Synthesising square wave and push to DAC 
    uint32_t val = synthesize(current_note.freq);
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;

    // Checking if its time for the next note 
    if (ticks > current_note.duration_ticks) {
        note_idx++;
        ticks = 0;
    }

    // Checking if sound is finished
    if ((note_idx + 1)  == sound_data->nr_notes) {
        current_sound = NONE;
    }
}

void setsound(soundname newsound)
{
    switch (newsound) {
        case FLAAKLYPA:
            sound_data = &fla_sound;
            break;
        case COIN:
            sound_data = &coin_sound;
            break;
        case CRASH:
            sound_data = &crash_sound;
            break;
        case FLAP:
            sound_data = &flap_sound;
            break;
        default:
            break;
    }
    note_idx = 0;
    ticks = 0;
}

void decreasevol()
{
    volume <<= 1;
}

void increasevol()
{
    volume >>= 1;
}

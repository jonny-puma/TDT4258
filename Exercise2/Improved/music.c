#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"
#include "timer.h"


note_t crash_notes[] = {
    {40, 700},
    {60, 700},
    {90, 700},
    {150, 700},
    {230, 700},
    {330, 700},
    {450, 700},
    {620, 700},
    {230, 700},
    {330, 700},
    {90, 700},
    {150, 700},
    {40, 700},
    {60, 700},
};

note_t coin_notes[] = {
    {B6, 500},
    {B5, 1500}
};

note_t flaa_notes[] = {
    {E5, 25000},
    {A5, 25000},
    {B5, 25000},
    {C5, 25000},
    {B5, 25000},
    {A5, 25000},
    {G5, 25000},
    {E5, 25000},
    {C4, 55000},
    {D4, 25000},
    {E5, 25000},
    {F5, 25000},
    {E5, 25000},
    {D4, 25000},
    {C4, 25000},
    {D4, 25000},
    {E5, 25000},
    {D4, 25000},
    {C4, 25000},
    {B4, 25000},
    {E5, 25000},
    {A5, 25000},
    {B5, 25000},
    {C5, 25000},
    {B5, 25000},
    {A5, 25000},
    {G5, 25000},
    {E5, 25000},
    {C4, 25000},
    {D4, 25000},
    {E5, 25000},
    {D4, 25000},
    {C4, 25000},
    {B4, 25000},
    {A3, 25000},
    {dA3, 25000},
    {A3, 25000},
    {A3, 25000},
    {A5, 35000},
    {G5, 35000},
    {F5, 35000},
    {E5, 35000},
    {B5, 35000},
    {A3, 35000},
    {B4, 35000},
    {C4, 35000},
    {D4, 35000},
    {E5, 35000},
    {F5, 35000},
    {E5, 35000},
    {D4, 35000},
    {E5, 35000},
    {A3, 35000}
};

note_t flap_notes[] = {
  {A3, 2000},
  {B4, 2000}
};

sound_t coin_sound = {coin_notes, sizeof(coin_notes)/sizeof(note_t)};
sound_t fla_sound = {flaa_notes, sizeof(flaa_notes)/sizeof(note_t)};
sound_t crash_sound = {crash_notes, sizeof(crash_notes)/sizeof(note_t)};
sound_t flap_sound = {flap_notes, sizeof(flap_notes)/sizeof(note_t)};

uint32_t volume = 1024;
uint32_t ticks = 0;
uint32_t note_idx = 0;
soundname current_sound = NONE;
sound_t *sound_data = 0;


uint32_t synthesize(uint32_t frequency)
{
    uint32_t duration_ticks = 41000/frequency;

    if ((ticks % duration_ticks) > duration_ticks/2) {
        return volume;
    } else {
        return -volume;
    }
}

void playsound(soundname *current_sound)
{
     
    note_t current_note = sound_data->notes[note_idx];

    // Synthesize square wave and push to DAC 
    uint32_t val = synthesize(current_note.freq);
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;
    ticks++;

    // Checking if its time for the next note 
    if (ticks > current_note.duration_ticks) {
        note_idx++;
        ticks = 0;
    }

    // Checking if sound is finished
    if ((note_idx + 1)  >= sound_data->nr_notes) {
        setsound(NONE);
    }
}

void setsound(soundname newsound)
{
    switch (newsound) {
        case FLAAKLYPA:
            sound_data = &fla_sound;
            startTimer();
            break;
        case COIN:
            sound_data = &coin_sound;
            startTimer();
            break;
        case CRASH:
            sound_data = &crash_sound;
            startTimer();
            break;
        case FLAP:
            sound_data = &flap_sound;
            startTimer();
            break;
        case NONE:
            stopTimer();
            break;
    }
    note_idx = 0;
    ticks = 0;
}

void decreasevol()
{
    volume += 200 ;
}

void increasevol()
{
    volume -= 200;
}

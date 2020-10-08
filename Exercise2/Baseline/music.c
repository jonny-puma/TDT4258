#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "common.h"
#include "efm32gg.h"

note_t crash_notes[] = {
    {400, 70},
    {600, 70},
    {900, 70},
    {1500, 70},
    {2300, 70},
    {3300, 70},
    {4500, 70},
    {6200, 70},
    {2300, 70},
    {3300, 70},
    {900, 70},
    {1500, 70},
    {400, 70},
    {600, 70},
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
  {C5, 200},
  {B5, 200}
};

sound_t coin_sound = {&coin_notes[0], 2};
sound_t fla_sound = {&flaa_notes[0], 103};
sound_t crash_sound = {&crash_notes[0], 13};
sound_t flap_sound = {&flap_notes[0], 3};

int ticks = 0;
int note_idx = 0;
sound_t *sound_data = &fla_sound;

void setupmusic()
{
  volume = 1024;
}

uint32_t synthesize(uint32_t frequency)
{
    uint32_t duration_ticks = DAC_FRQ/frequency;

<<<<<<< HEAD
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
=======
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

    // Synthesize square wave and push to DAC 
    uint32_t val = synthesize(current_note.freq);
    *DAC0_CH0DATA = val;
    *DAC0_CH1DATA = val;

    // Checking if its time for the next note 
    if (ticks > current_note.duration_ticks) {
        note_idx++;
        ticks = 0;
>>>>>>> jonas3
    }

    // Checking if sound is finished
    if ((note_idx + 1)  >= sound_data->nr_notes) {
        *current_sound = NONE;
    }
}

void setsound(soundname newsound)
{
    switch (newsound) {
        case FLAAKLYPA:
<<<<<<< HEAD
            //*GPIO_PA_DOUT = (0xfe)<<8;
            current_song = &flaaklypa;
            //*current_song = flaaklypa;
=======
            sound_data = &fla_sound;
>>>>>>> jonas3
            break;
        case COIN:
<<<<<<< HEAD
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
=======
            sound_data = &coin_sound;
            break;
        case CRASH:
            sound_data = &crash_sound;
>>>>>>> jonas3
            break;
        case FLAP:
            sound_data = &flap_sound;
            break;
	case NONE:
	    break;
    }
<<<<<<< HEAD
    current_song->playhead = 0;
=======
    note_idx = 0;
    ticks = 0;
>>>>>>> jonas3
}

void decreasevol()
{
    volume += 200 ;
}

void increasevol()
{
    volume -= 200;
}

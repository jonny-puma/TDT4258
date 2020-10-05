#include "music.h"
#include "common.h"

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
    
}

void resetSong(){
    switch (*CURRENT_SONG)
    {
        case FLAAKLYPA:
            current_song = &flaaklypa[0];
            break;
        case COIN:
            current_song = &coin[0];
            break;
        case JUMP:
            current_song = &jump[0];
            break;
        case DEATH:
            current_song = &death[0];
            break;
        default:
            // set none
            break;
    }
    current_song->playhead = 0;
}

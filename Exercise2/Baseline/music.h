#include "efm32gg.h" // ???

/*
{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4
{.freq = A3 (2)
{.freq = dA (2)
{.freq = A3 (2)

{.freq = A3 (2)
{.freq = A5
{.freq = G5
{.freq = F5
{.freq = E5
{.freq = B5
{.freq = A3 
{.freq = B4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = E5

{.freq = A3 (2)
{.freq = A5
{.freq = G5
{.freq = F5
{.freq = E5
{.freq = B5
{.freq = A3 
{.freq = B4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = E5

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = F5
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4

{.freq = E5
{.freq = A5
{.freq = B5
{.freq = C5
{.freq = B5
{.freq = A5
{.freq = G5
{.freq = E5
{.freq = C4
{.freq = D4
{.freq = E5
{.freq = D4
{.freq = C4
{.freq = B4
{.freq = A3 (2)
{.freq = dA (2)
{.freq = A3 (2)
*/

// Hz
#define B6 1975.53
#define E7 2637.02

#define A5 880
#define B5 987.767
#define C5 523.251
#define F5 698.456
#define G5 783.991
#define E5 659.255

#define B4 493.883
#define C4 261.626
#define D4 293.665

#define A3 220.000
#define dA3 207.652

#define A2 110.000
#define dA2 103.826

struct song{
    note *notes;

};

struct note{
    float freq;
    float sec;
};
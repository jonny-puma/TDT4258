#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

void setupTimer(uint16_t period);
void startTimer();
void stopTimer();
void sleep();
#endif

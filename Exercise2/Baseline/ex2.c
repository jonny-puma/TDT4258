#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"

extern void setupDAC();
extern void setupGPIO();
extern void setupMusic();
extern void setupTimer(uint32_t period);

extern void startTimer();
extern int buttonHandler( int C_s );
extern void updateNote();

int main(void)
{
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();
	startTimer();
  	int tune_n = 0;

	while(1){
		tune_n = buttonHandler( tune_n);
		if (*TIMER1_CNT > SAMPLE_PERIOD){
			*TIMER1_CNT = 0;
			if (tune_n == 0){
        		*GPIO_PA_DOUT = 0x0f00;
			}else{
        		tune_n = playMelody( tune_n );
        		*GPIO_PA_DOUT = 0xf000;
      		}
		}
	} 
	return 0;
}
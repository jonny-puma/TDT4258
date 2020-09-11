        .syntax unified
	
	      .include "efm32gg.s"

	/////////////////////////////////////////////////////////////////////////////
	//
  // Exception vector table
  // This table contains addresses for all exception handlers
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .section .vectors
	
	      .long   stack_top               /* Top of Stack                 */
	      .long   _reset                  /* Reset Handler                */
	      .long   dummy_handler           /* NMI Handler                  */
	      .long   dummy_handler           /* Hard Fault Handler           */
	      .long   dummy_handler           /* MPU Fault Handler            */
	      .long   dummy_handler           /* Bus Fault Handler            */
	      .long   dummy_handler           /* Usage Fault Handler          */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* SVCall Handler               */
	      .long   dummy_handler           /* Debug Monitor Handler        */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* PendSV Handler               */
	      .long   dummy_handler           /* SysTick Handler              */

	      /* External Interrupts */
	      .long   dummy_handler
	      .long   gpio_handler            /* GPIO even handler */
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   gpio_handler            /* GPIO odd handler */
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler

	      .section .text

	/////////////////////////////////////////////////////////////////////////////
	//
	// Reset handler
  // The CPU will start executing here after a reset
	//
	/////////////////////////////////////////////////////////////////////////////

	      .globl  _reset
	      .type   _reset, %function
        .thumb_func
_reset: 
		///CMU enable GPIO///
		mov r0, #1
		ldr r1, = CMU_BASE
		ldr r2, [r1, #CMU_HFPERCLKEN0]
		lsl r0, r0, #CMU_HFPERCLKEN0_GPIO
		orr r2, r2, r0
		str r2, [r1, #CMU_HFPERCLKEN0]

		//// LEDS ////
		ldr r0, =GPIO_PA_BASE
		mov r2, #0x2
		str r2, [r0, #GPIO_CTRL]  // Set drive strength

		ldr r2, =0x55555555
		str r2, [r0, #GPIO_MODEH] // pin 8-15 to output

		mov r2, #0x00
        lsl r2, #8
		str r2, [r0, #GPIO_DOUT]

        mov r2, #0xff
        lsl r2, #8
        str r2, [r0, #GPIO_DOUT]

        //// Buttons ////
        ldr r1, =GPIO_PC_BASE

        ldr r2, =0x33333333
        str r2, [r1, #GPIO_MODEL]

        
        mov r2, #0xff
        str r2, [r1, #GPIO_DOUT]


// r0 is PA_BASE - LEDS
// r1 is PC_BASE - BUTTONS
// r2 is multipurpose
// r3 is multipurpose
    .thumb_func
main:
        // Start by reading PC_DIN
        ldr r2, [r1, #GPIO_DIN]  // Read in buttons to r2
        lsl r2, #8
        str r2, [r0, #GPIO_DOUT] // Write r2 to leds
        
        b main
	/////////////////////////////////////////////////////////////////////////////
	//
  // GPIO handler
  // The CPU will jump here when there is a GPIO interrupt
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
gpio_handler:  

	      b .  // do nothing
	
	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
dummy_handler:  
        b .  // do nothing


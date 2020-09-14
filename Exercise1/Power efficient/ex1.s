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
		ldr r1, =CMU_BASE
		ldr r2, [r1, #CMU_HFPERCLKEN0]
		lsl r0, r0, #CMU_HFPERCLKEN0_GPIO
		orr r2, r2, r0
		str r2, [r1, #CMU_HFPERCLKEN0]

		//// ENABLE LEDS ////
		ldr r1, =GPIO_PA_BASE
		
        mov r2, #0x1
		str r2, [r1, #GPIO_CTRL]    // Define LED-drive strength

		ldr r2, =0x55555555
		str r2, [r1, #GPIO_MODEH]   // Define LEDS as output
		
		//// TURN OFF ALL LEDS ////
		mov r0, #0xff
		lsl r0, r0, #8
		str r0, [r1, #GPIO_DOUT]


        //// ENABLE BUTTONS ////
		ldr r3, =GPIO_PC_BASE
		
        ldr r2, =0x33333333
		str r2, [r3, #GPIO_MODEL]   // Define BUTTONS as input
		
        mov r2, #0xff
		str r2, [r3, #GPIO_DOUT]    // Enable internal pull-up

		//// Enabling interrupts ////
		ldr r3, =GPIO_BASE

		ldr r2, =0x22222222
		str r2, [r3, #GPIO_EXTIPSELL]  // Enable external interupt for all pins (0-7) on port C

		mov r2, #0xff
		str r2, [r3, #GPIO_EXTIFALL]  // Set interupt on falling edge
		str r2, [r3, #GPIO_EXTIRISE]  // Set interupt on rising edge
		str r2, [r3, #GPIO_IEN]       // Enable interupt generation

		ldr r2, =0x802
		ldr r1, =ISER0
		str r2, [r1]

		//// POWER SAVE ////
		ldr r2, =SCR
        ldr r0, =0x06
        str r0, [r2]

        ldr r2, =EMU_BASE
        ldr r0, =0x7
        str r0, [r2, #EMU_MEMCTRL]  // Disable RAM-block 1-3

        /*
        ldr r1, =CMU_BASE

        mov r0, #15
        str r0, [r1, #CMU_LFACLKEN0]

        mov r0, #3
        str r0, [r1, #CMU_LFBCLKEN0]
        */

        ldr r1, =GPIO_PA_BASE
        ldr r2, =GPIO_PC_BASE
        ldr r3, =GPIO_BASE
		wfi
		


	
	/////////////////////////////////////////////////////////////////////////////
	//
  	// GPIO handler
  	// The CPU will jump here when there is a GPIO interrupt
	//
	/////////////////////////////////////////////////////////////////////////////
	
// r0 multivariate
// r1 GPIO_PA_BASE
// r2 GPIO_PC_BASE
// r3 GPIO BASE


        .thumb_func
gpio_handler:
		// Read and reset interrupt
		ldr r0, [r3, #GPIO_IF]
		str r0, [r3, #GPIO_IFC]

        // Map buttons to LEDs
		ldr r0, [r2, #GPIO_DIN]
        lsl r0, r0, #8
        str r0, [r1, #GPIO_DOUT]
		
	    bx lr

	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
dummy_handler:  
        bx lr


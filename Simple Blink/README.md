# Simple Blink

## README
The programs provided are a simple look into what microprocessors can do.  The basic task used for this example is blinking an LED.  

Both files uploaded run primarily the same code with minor differences because of the separate processors.  The codes is designed to blink an LED with a 50% duty cycle.  The codes first begin with their specific include statements and main functions.  The watchdog timers are then paused to stop the code from continuously looping through the main function.  The MSP430 code includes a redundant P1SEL and P1SEL2 call because they default to I/O anyway, but was included for practice.  After, the directions of the LED pins are set to output and an infinite while loop is created.  The loop cycles the pin outputs between on and off by use of XOR logic.  A delay is then added to make the on/off slow enough that it is visible.

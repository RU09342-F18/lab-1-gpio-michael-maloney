/**
 * Code by Michael Maloney
 * 9/15/2018
 * multiblink.c
 */

#include <msp430.h>				//Include statement for msp430 variables.

void main(){
    WDTCTL = WDTPW + WDTHOLD;    //Pauses watchdog timer.
	P1SEL &= ~BIT0 + ~BIT6;      //P1SEL and P1SEL2 are both set to 0 at bit 0 and 6 to allow I/0 control for
	P1SEL2 &= ~BIT0 + ~BIT6;        //both pin1.0 and 1.6(not used in this part, but later on)
	P1DIR |= BIT0 + BIT6;        //The direction of the I/O is set to out on both pins.
	int i=0;                //Int i is instantiated to be the incremental number that the two leds will base their flashing on.
	while(1){              //Infinite while loop.
	    if ((i%5000) <1) {P1OUT ^= BIT0;}   //Instead of using a delay, a modulus operator is used to turn the LEDs on and off
	    if ((i%250)<1) {P1OUT ^= BIT6;}     // based on whether the incrementing i variable is divisible by a certain number.
	    i++;            //I increments mimicking a clock
	    if (i == 5000) {i = 0;} //When i hits 5000 (the lowest common denominator from above), it is reset to 0 to protect from overflow errors.
	}
}

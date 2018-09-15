/**
 * Code by Michael Maloney
 * 9/15/2018
 * blink.c
 */

#include <msp430.h>				//Include statement for msp430 variables.

void main(){
    WDTCTL = WDTPW + WDTHOLD;    //Pauses watchdog timer.
	P1SEL &= ~BIT0 + ~BIT6;      //P1SEL and P1SEL2 are both set to 0 at bit 0 and 6 to allow I/0 control for 
	P1SEL2 &= ~BIT0 + ~BIT6;        //both pin1.0 and 1.6(not used in this part, but later on)
	P1DIR |= BIT0 + BIT6;        //The direction of the I/O is set to out on both pins.
	while(1){              //Infinite while loop.
	    P1OUT ^= BIT0;     //P1OUT is XORed with BIT0 to flip it on and off through each pass of the loop.
	    __delay_cycles(1000000);  //A delay is used in each loop pass, keeping a 50% duty cycle.
	}

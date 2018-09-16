/**
 * Code by Michael Maloney
 * 9/16/2018
 * switchblink.c
 */

#include <msp430.h>				//Include statement for msp430 variables.

void main(){
    WDTCTL = WDTPW + WDTHOLD;    //Pauses watchdog timer.
	P1SEL &= ~BIT0 + ~BIT6 + ~BIT3;      //P1SEL and P1SEL2 are both set to 0 at bit 0, 3, and 6 to allow I/0 control for
	P1SEL2 &= ~BIT0 + ~BIT6 + ~BIT3;        //Pins 1.0, 1.3, and 1.6.
	P1DIR |= BIT0 + BIT6;        //The direction of the I/O is set to out on both LED pins.
	P1DIR &= ~BIT3;              //The direction of the I/O is set to in for the button pin.
	P1OUT &= 0;                  //The output pins are started in the low state.
	while (1){                   //Infinite while loop to allow the button process to continue indefinitely.
	    if ((P1IN & BIT3) == 0x00){     // xxxxx(0/1)xx AND 00000100 = 00000(0/1)00, so when pressed, the value equals 0x00, triggering the if statement.
	        P1OUT ^= BIT0 + BIT6;       //The LED output pins are flipped when button is pressed, and remain on until the button is pressed again. 
	        P1REN = BIT0 + BIT6;        //A pull down resistor is needed to ensure the input value doesn't stay high when pressed.
	    }                               //End of if statement.
	    P1REN = 0;                      //The resistors are switched off to keep LEDs at max voltage (assuming they are on).
	    __delay_cycles(200000);         //Each loop is delayed 200000 cycles to account for the time it takes a human to press a button.
	}                                    
}

#include <msp430.h> //includes msp430 header file


/**Michael Maloney
 * 9/19/2018
 * MSP430f5529multi.c
 */
int main()
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~BIT0;      //P1SEL set to 0 at pin 0 to allow I/O usage at the pin.
	//P1SEL2 &= ~BIT0;   //PxSEL2 does not exist on this board.
	P4SEL &= ~BIT7;      //Same reasoning as above to set PxSEL to 0 at BIT7 for I/0.
	//P4SEL2 &= ~BIT7;   //PxSEL2 does not exist on this board.
	P1DIR |= BIT0;       //P1.0 direction set to output.
	P4DIR |= BIT7;       //P4.7 direction set to output.
	int i=0;                //Int i is instantiated to be the incremental number that the two leds will base their flashing on.
	    while(1){              //Infinite while loop.
	        if ((i%5000) <1) {P1OUT ^= BIT0;}   //Instead of using a delay, a modulus operator is used to turn the LEDs on and off
	        if ((i%250)<1) {P4OUT ^= BIT7;}     // based on whether the incrementing i variable is divisible by a certain number.
	        i++;            //I increments mimicking a clock
	        if (i == 5000) {i = 0;} //When i hits 5000 (the lowest common denominator from above), it is reset to 0 to protect from overflow errors.
	    }
}


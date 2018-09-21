# Off Board Blink

## README
The final part of this lab was to create an off-board blinking LED.  This part is practically the same as the multiple blink section, except the LaunchPad board is swapped out for a breadboard and components.  The code used for this is part is actually entirely the same and nothing is changed.

The circuit includes 2 LEDs connected directly to pins 2 (PIN 1.0) and 14 (PIN 1.6) by 1k resistors to limit current draw. Pin 1 is connected directly to Vcc of 3.3 volts to power the chip.  3.3V is also connected by a 47K resistor to the reset pin 16 to allow the board to function.  To counteract noise in the reset pin, a 1nF capacitor is connected from reset pin 16 to ground.  Also, to allow for reset usage on the board, a switch is connected from reset pin 16 to one side of the switch, and ground to the other, so if pressed the pin will drop to 0.

As stated, the code is exactly the same as in the multiple blink section, so if questions about this code come up, the README section for the multiple blink program will hopefully answer them.

### Off-Board Blinking Circuit
![](ezgif-2-0dbd894623[1].gif)

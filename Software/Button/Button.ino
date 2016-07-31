/*
	This file is part of Waag Society's BioHack Academy Code.

	Waag Society's BioHack Academy Code is free software: you can 
	redistribute it and/or modify it under the terms of the GNU 
	General Public License as published by the Free Software 
	Foundation, either version 3 of the License, or (at your option) 
	any later version.

	Waag Society's BioHack Academy Code is distributed in the hope 
	that it will be useful, but WITHOUT ANY WARRANTY; without even 
	the implied warranty of MERCHANTABILITY or FITNESS FOR A 
	PARTICULAR PURPOSE.  See the GNU General Public License for more 
	details.

	You should have received a copy of the GNU General Public License
	along with Waag Society's BioHack Academy Code. If not, see 
	<http://www.gnu.org/licenses/>.

 BHA_Button library demonstration
 
 The code demonstrates how to register a button press only once, instead 
 of multiple times. This is accomplished by measuring the time that has 
 passed since the last registered button press and only registering a new 
 button press after a certain time has passed.

 This sketch makes use of the LED that each Arduino has onboard, 
 connected to pin 13. Other parts the circuit needs are:
 * push button
 * 10K resistor
 Check the "Button Wiring.fzz" file and observe the circuit.

 Derived from
 http://www.arduino.cc/en/Tutorial/Debounce
 */

// Include the BHA button library
#include "BHA_Button.h"

// Constants won't change while the program runs. 
// That's why we use them to set pin numbers
const int buttonPin = 11;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Construct BHA_Button class
BHA_Button button(buttonPin);

// Variables will change:
int buttonState;             // the current reading from the input pin

void setup() {
  // declare the pinMode of the ledPin as OUTPUT
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);
}

void loop() {
  // check button state
  buttonState = button.poll();

  // only switch LED on if the button state is HIGH
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}


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

 BHA_RotaryEncoder library demonstration
 
 The code demonstrates how to process the input of the rotary encoder.

 This sketch makes use of the serial port connection to observe the result.
 In case you are unfamiliar with serial port connections check this 
 tutorial: https://www.arduino.cc/en/Tutorial/AnalogReadSerial
 Or have a look at the BHA_SerialCommunication demonstration file
 
 Check the "Rotary Encoder Wiring.fzz" file and observe the circuit.
 */

// Include the BHA Rotary Encoder library
#include "BHA_RotaryEncoder.h"

// First indicate which Arduino you are using. This defines which pins are 
// used as interrupts https://www.arduino.cc/en/Reference/AttachInterrupt
#define arduinoType 1 // Choose: 0 = Arduino UNO; 1 = Arduino Leonardo

#if arduinoType == 0
  #define encoderPin1 2
  #define encoderPin2 3
#endif
#if arduinoType == 1
  #define encoderPin1 0
  #define encoderPin2 1
#endif
  
// Construct BHA_RotaryEncoder class
BHA_RotaryEncoder rotaryEncoder(encoderPin1, encoderPin2);

void setup() {
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0, or interrupt 1 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);  
  
  // Open Serial connection
  Serial.begin(9600);
}

void loop() {
  Serial.println(rotaryEncoder.c);
}

void updateEncoder() {
  // work around function, as attachInterrupt() only accepts pointers to functions and not to class methods
  rotaryEncoder.updateEncoder();
}


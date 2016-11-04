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
 */

#include "Arduino.h"
#include "BHA_Button.h"

BHA_Button::BHA_Button(int pin)
{
  // Define pinMode
  pinMode(pin, INPUT);
  _pin = pin;
  
  // Set initial values
  _lastDebounceTime = 0;  // the last time the output pin was toggled
  _debounceDelay = 500;    // the debounce time; increase if the output flickers
}

int BHA_Button::poll()
{
  // read the state of the button into a local variable
  int reading = digitalRead(_pin);
  
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:
  
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    
    // check whether the button is pressed
    if (reading == HIGH) {
      
      // return HIGH
      return HIGH;
      
      // store the time
      _lastDebounceTime = millis();
    }
  }
  else {
    // too little time has passed, so return LOW
    return LOW;
  }
}

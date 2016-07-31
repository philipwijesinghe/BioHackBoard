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

// First prevent the library from getting included twice
#ifndef BHA_Button_h
#define BHA_Button_h

#include "Arduino.h"

class BHA_Button
{
  public:   
    BHA_Button(int pin);
    int poll();
  private:
    int _pin;
        
    // the following variables are long's because the time, measured in miliseconds,
    // will quickly become a bigger number than can be stored in an int.
    long _lastDebounceTime;  // the last time the button was pressed
    long _debounceDelay;    // the debounce time; increase if the code registers two or more button presses in stead of one
};

#endif

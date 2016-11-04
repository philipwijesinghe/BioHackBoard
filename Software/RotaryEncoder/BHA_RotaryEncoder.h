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
#ifndef BHA_RotaryEncoder_h
#define BHA_RotaryEncoder_h

#include "Arduino.h"

class BHA_RotaryEncoder
{
  public:   
    BHA_RotaryEncoder(int pin1, int pin2);
    void updateEncoder();
    int c; // counter variable
  private:
    int _pin1;
    int _pin2;
    
    // These variables are keeping track of the state of the pins
    int _lastEncoded;
    int _lastMSB;
    int _lastLSB;
};

#endif

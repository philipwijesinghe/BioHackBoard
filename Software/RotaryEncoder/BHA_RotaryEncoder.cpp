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
#include "BHA_RotaryEncoder.h"

BHA_RotaryEncoder::BHA_RotaryEncoder(int pin1, int pin2)
{
  // Define pinMode
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  _pin1 = pin1;
  _pin2 = pin2;
  
  // Turn on Arduino's internal pull up resistors
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, HIGH);
  
  // Set initial values
  int _lastEncoded = 0;
  int _lastMSB = 0;
  int _lastLSB = 0;
  int c = 0;

}

void BHA_RotaryEncoder::updateEncoder()
{  
  int MSB = digitalRead(_pin1); //MSB = most significant bit
  int LSB = digitalRead(_pin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (_lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) c --;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) c ++;

  _lastEncoded = encoded; //store this value for next time
}

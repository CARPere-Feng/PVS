#ifndef _CONFIGURATIONS_H
#define _CONFIGURATIONS_H

#include "Arduino.h"

const uint8_t PROGMEM road_to_valve[] = {
	2,	// road 0
	3,	// road 1 
	4,	// road 2
	5,	// road 3
	6,	// road 4
	7,	// road 5
	8,	// road 6
	9,	// road 7
	10,	// road 8
	11,	// road 9
	12,	// road 10
	13	// road 11
};

const uint8_t PROGMEM road_to_sensor[] = {
	A2,	// road 0
	A3,	// road 1 
	A4,	// road 2
	A5,	// road 3
	A6,	// road 4
	A7,	// road 5
	A8,	// road 6
	A9,	// road 7
	A10,	// road 8
	A11,	// road 9
	A12,	// road 10
	A13	// road 11
};

#endif // !_CONFIGURATIONS_H

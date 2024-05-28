#include <iostream>

#ifndef SHIP_H
#define SHIP_H

using namespace std;


class Ship {

	bool isLengthValid();

public:

	int length;
	bool isVertical;

	// constructors 
	Ship();
	Ship(int _length);
	Ship(bool _isVertical);
	Ship(int _length, bool _isVertical);


};

#endif
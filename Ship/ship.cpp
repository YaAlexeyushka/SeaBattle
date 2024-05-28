#include "ship.h"

using namespace std;


// functions
bool Ship::isLengthValid() {
	return (length >= 1 and length < 5);
}

// constructors
Ship::Ship() {
	length = 1;
	isVertical = true;
}

Ship::Ship(int _length) {
	length = _length;

	if (!isLengthValid()) {
		throw "Length is invalid exception";
	}
}

Ship::Ship(bool _isVertical) {
	isVertical = _isVertical;
}

Ship::Ship(int _length, bool _isVertical) {
	length = _length;
	isVertical = _isVertical;

	if (!isLengthValid()) {
		throw "Length is invalid exception";
	}
}








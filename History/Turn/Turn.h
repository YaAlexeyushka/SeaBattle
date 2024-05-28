#include <iostream>

#ifndef TURN_H
#define TURN_H

using namespace std;

struct Turn {
	int y;
	char x;
	bool isFirstPlayerTurn;
	string result;

	Turn(bool _isFirstPlayerTurn, string _result, char _x, int _y);
};

#endif
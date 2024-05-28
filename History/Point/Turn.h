#include <iostream>

#ifndef TURN_H
#define TURN_H

using namespace std;

struct Turn {
	int x, y;
	bool isFirstPlayerTurn;
	string result;

	Turn(bool _isFirstPlayerTurn, string _result, int _x, int _y);
};

#endif
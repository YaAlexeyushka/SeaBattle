#include "Turn.h"

using namespace std;

Turn::Turn(bool _isFirstPlayerTurn, string _result, int _x, int _y) {
	isFirstPlayerTurn = _isFirstPlayerTurn;
	result = _result;
	x = _x;
	y = _y;
}

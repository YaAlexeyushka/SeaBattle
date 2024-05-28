#include <iostream>
#include "../Cell/Cell.h"
#include "../Ship/ship.h"

#ifndef BOARD_H
#define BOARD_H

using namespace std;


class Board {


public:
	Cell board[10][10];
	int shipsAlive=10;

	// constructors
	Board();

	// functions 
	Cell getCell(char hor, int ver);
	void convert(int* x, int* y, char hor, int ver);
	bool isCoordinateValid(int y);
	bool isShipClose(int x, int y);
	bool isAbleToPlaceShip(Ship ship, int x, int y);
	void placeShip(Ship ship, char hor, int ver);
	void makeShot(char hor, int ver);

};

#endif
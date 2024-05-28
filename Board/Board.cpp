#include <map>
#include "Board.h"

using namespace std;


// constructors
Board::Board() {

}

// functions
Cell Board::getCell(char hor, int ver) {
	int x, y;
	convert(&x, &y, hor, ver);
	return board[x][y];
}

void Board::convert(int* x, int* y, char hor, int ver) {
	map<int, char> letters = { {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},
		{'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9} };

	if (letters.count(hor) == 0) {
		throw "coordinates are invalid exception";
	}

	*x = letters.at(hor);
	*y = 10 - ver;
}

bool Board::isCoordinateValid(int y) {
	return (y >= 0 and y < 10);
}

bool Board::isShipClose(int x, int y) {

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int newX = x + dx;
			int newY = y + dy;

			if (newX >= 0 and newX < 10 and newY >= 0 and newY < 10) {
				if (board[newX][newY] == ShipPart) {
					return true;  
				}
			}
		}
	}

	return false;
}

bool Board::isAbleToPlaceShip(Ship ship, int x, int y) {
	if (board[x][y] == ShipPart) {
		return false;
	}

	if (ship.isVertical) {
		if (y + ship.length - 1 > 9) {
			return false;
		}

		for (int i = y; i <= y + ship.length-1; i++) {
			if (isShipClose(x, i)) {
				return false;
			}
		}
	}
	else {
		if (x + ship.length > 9) {
			return false;
		}

		for (int i = x; i <= x + ship.length-1; i++) {
			if (isShipClose(i, y)) {
				return false;
			}
		}
	}

	return true;
}

void Board::placeShip(Ship ship, char hor, int ver) {
	int x, y;
	convert(&x, &y, hor, ver);
	
	if (!isCoordinateValid(y)) {
		throw "coordinates are invalid exception";
	}

	if (!isAbleToPlaceShip(ship, x, y)) {
		throw "coordinates are invalid exception";
	}

	if (ship.isVertical) {
		for (int i = y; i <= y + ship.length - 1; i++) {
			board[x][i] = ShipPart;
		}
	}
	else {
		for (int i = x; i <= x + ship.length - 1; i++) {
			board[i][y] = ShipPart;
		}
	}
}

void Board::makeShot(char hor, int ver) {
	int x, y;
	convert(&x, &y, hor, ver);

	if (!isCoordinateValid(y)) {
		throw "coordinates are invalid exception";
	}

	if (board[x][y] == ShipPart) {
		board[x][y] = Hit;
	}
	else  {
		board[x][y] = Miss;
	}
}








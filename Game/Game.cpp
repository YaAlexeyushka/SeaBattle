#include <string>
#include "Game.h"

using namespace std;


// constructors
Game::Game() {
	string _playerName1, _playerName2;

	cout << "Enter the name of the first player: ";
	cin >> _playerName1;

	cout << "Enter the name of the second player: ";
	cin >> _playerName2;

	firstPlayerName = _playerName1;
	secondPlayerName = _playerName2;
}

Game::Game(string _playerName1, string _playerName2) {
	firstPlayerName = _playerName1;
	secondPlayerName = _playerName2;
}


// functions
void Game::makeTurn(Board& board, string playerName) {
	int y;
	char x;

	while (true) {
		cout << playerName << ", enter coordinates of shot: " << endl;
		cin >> x >> y;

		try {
			board.makeShot(x, y);
		}
		catch(...) {
			cout << "Coordinates are invalid!";
			continue;
		}

		Cell cell = board.getCell(x, y);

		if (cell == Miss) {
			cout << "Miss!" << endl;
			history.addTurn(isFirstPlayerTurn, "Miss", x, y);

			return;
		}

		if (cell == Hit) {
			int x1, y1;
			board.convert(&x1, &y1, x, y);
			if (board.isShipClose(x1, y1)) {
				history.addTurn(isFirstPlayerTurn, "Hit", x, y);
				cout << "Hit!" << endl;
			}
			else {
				board.shipsAlive--;
				history.addTurn(isFirstPlayerTurn, "Sank", x, y);
				cout << "Sank!" << endl;
				cout << "Left ships: " << board.shipsAlive << endl;

				if (board.shipsAlive == 0) {
					return;
				}
			}
		}
	}
}

void Game::changeCoordinates(char* x, int* y, string shipName, string playerName) {
	cout << playerName << ", enter coordinates of "<< shipName<< ": " << endl;
	cin >> *x >> *y;
}

bool Game::vertical(string playerName) {
	char vert;

	cout << playerName << ", plase it vertically? (1-yes, 0-no): " << endl;
	cin >> vert;

	if (vert == '1') {
		return true;
	}
	else if (vert == '0') {
		return false;
	}
	else {
		vertical(playerName);
	}
}

void Game::placeShips(Board &board, string playerName) {
	char x;
	int y;
	bool isVertical;
	string shipsNames[4] = { "four-decker ship", "three-decker ship",
		"double decker ship", "single decker ship" };

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i <= j; i++) {
			changeCoordinates(&x, &y, shipsNames[j], playerName);

			isVertical = vertical(playerName);

			Ship ship(4-j, isVertical);

			try {
				board.placeShip(ship, x, y);
			}
			catch (...) {
				cout << "Coordinates are invalid!" << endl;
				i--;
			}
		}
	}
}

void Game::startGame() {
	isFirstPlayerTurn = true;
	Board firstPlayerBoard, secondPlayerBoard;

	placeShips(firstPlayerBoard, firstPlayerName);
	placeShips(secondPlayerBoard, secondPlayerName);

	while (true) {

		if (isFirstPlayerTurn) {
			makeTurn(secondPlayerBoard, firstPlayerName);
		}
		else {
			makeTurn(firstPlayerBoard, secondPlayerName);
		}

		if (secondPlayerBoard.shipsAlive == 0) {
			cout << firstPlayerName << ' ' << "won!";
			break;
		}
		else if (firstPlayerBoard.shipsAlive == 0) {
			cout << secondPlayerName << ' ' << "won!";
			break;
		}

		isFirstPlayerTurn = !isFirstPlayerTurn;
	}

	history.writeHistory("history/history.txt");

	char ch;
	cout << "Do you want to start a new game?(1-yes, 0-no): " << endl;
	cin >> ch;
	if (ch == '1') {
		startGame();
	}
}


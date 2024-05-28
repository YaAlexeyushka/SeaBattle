#include "Board/Board.h"
#include "ship/ship.h"
#include "Game/Game.h"
#include "History/History.h"

using namespace std;


int main() {
	Ship ship1(4, true);
	Board board;

	board.placeShip(ship1, 'f', 6);
	board.makeShot('f', 6);
	if (board.board[5][4] == Hit) {
		cout << "HIT!" << endl;
	}

	Ship ship2(3, false);
	try {
		board.placeShip(ship2, 'g', 5);
	}
	catch (...) {
		cout << "ships are close" << endl;
	}

	History history;
	bool isFirstPlayerTurn = true;
	history.addTurn(isFirstPlayerTurn, "HIT", 'j', 2);
	history.writeHistory("test_history.txt");

	Game game;
	game.startGame();
}
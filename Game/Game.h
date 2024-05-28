#include <iostream>
#include <string>
#include "../board/Board.h"
#include "../ship/ship.h"
#include "../Cell/Cell.h"
#include "../History/History.h"

#ifndef GAME_H
#define GAME_H

using namespace std;


class Game {

public:
	string firstPlayerName, secondPlayerName;
	bool isFirstPlayerTurn;
	History history;

	// constructors
	Game();
	Game(string _playerName1, string _playerName2);

	// functions 
	void makeTurn(Board& board, string playerName);
	void changeCoordinates(char* x, int* y, string shipName, string playerName);
	bool vertical(string playerName);
	void placeShips(Board& board, string playerName);
	void startGame();
	

};

#endif
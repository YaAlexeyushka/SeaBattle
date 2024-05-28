#include <iostream>
#include <vector>
#include <string>
#include "Turn/Turn.h"

#ifndef HISTORY_H
#define HISTORY_H

using namespace std;


class History {

public:

	vector<Turn> history;

	void writeHistory(string file);
	void addTurn(bool isFirstPlayerTurn, string result, char x, int y);
};

#endif
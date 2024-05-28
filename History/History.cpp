#include <string>
#include "History.h"
#include <fstream>

using namespace std;

void History::writeHistory(string file) {
	ofstream out;
	out.open(file);

	if (out.is_open()) {
		for (Turn t : history) {
			string player = "p2";

			if (t.isFirstPlayerTurn) {
				player = "p1";
			}

			out << player << " - " << t.x << ' ' << t.y << ' ' << t.result << endl;
		}
	}

	out.close();
	cout << "File has been written" << endl;
}

void History::addTurn(bool isFirstPlayerTurn, string result, char x, int y) {
	Turn t(isFirstPlayerTurn, result, x, y);
	history.push_back(t);
}
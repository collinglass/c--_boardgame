#include <iostream>
#include <vector>
#include "board.h"

int main () {
	char row = 'a';
	char row2 = 'b';
	char row3 = 'c';
	Board<int> board(10,20);
	board.placeTile(row, 10, 17);
	board.placeTile(row2, 10, 18);
	board.placeTile(row3, 10, 19);
	board.placeTile(row2, 9, 20);
	board.placeTile(row2, 11, 21);
	std::cout << board.getTileAt(row,10) << std::endl;
	vector<int> agent = board.getAdjacent(row2,10);
	for (int i = 0; i < 4; i++) {
		std::cout << agent[i] << std::endl;
	}
	Group<int> group;
	std::cout << group.getDummy() << std::endl;
	
	return 0;
}
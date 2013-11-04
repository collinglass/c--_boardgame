#include <iostream>
#include "board.h"

int main () {
	char row = 'a';
	Board<int> board(10,20);
	board.placeTile(row, 10, 17);
	std::cout << board.getTileAt(row,10) << std::endl;
	return 0;
}
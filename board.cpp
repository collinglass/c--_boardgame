#include <iostream>
#include <iomanip>
#include <vector>
#include "board.h"
#include "group.h"

int main() {

	cout << static_cast<int>('a') << " " << static_cast<int>('z') << endl;
	int index = 1;
	const int numRows = 5;
	const int numCols = 5;
	char rows[5] = { 'a', 'b', 'c', 'd', 'e' };
	int result = 0;

	// create blank board
	Board<int> board(numRows, numCols);

	// print out blank board
	cout << "Blank Board" << endl;
	board.printBoard();
	/*for (int i = 0; i < numRows; i++) {
	 for (int j = 0; j < numCols; j++) {
	 board.getTileAt(result, i + 97, j);
	 cout << setw(4) << result << " ";
	 }
	 cout << endl;
	 }*/

	// initialize board with indices 0 to (numRow - 1)(numCol - 1)
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			board.placeTile(i + 97, j, index);
			index++;
		}
	}

	cout << endl;

	// print initialized board
	cout << endl << "Initialized Board" << endl;
	board.printBoard();
	/*for (int i = 0; i < numRows; i++) {
	 for (int j = 0; j < numCols; j++) {
	 board.getTileAt(result, i + 97, j);
	 cout << setw(5) << result << " ";
	 }
	 cout << endl;
	 }*/

	cout << endl;

	// get adjacency vector for tile at [3,3]
	cout << "Adjacency vector for tile at [3,3]" << endl;
	vector<int> agent = board.getAdjacent(rows[2], 2);
	for (int i = 0; i < agent.size(); i++) {
		cout << setw(5) << agent[i] << endl;
	}

	cout << endl;

	// getting dummy from group
	Group<int> group;
	cout << "Dummy: " << group.getDummy() << endl;
}

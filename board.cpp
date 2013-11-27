#include <iostream>
#include <iomanip>
#include <vector>
#include "board.h"
#include "group.h"

int main() {
	int numPlayers;
	int playerTurn = 1;
	bool isFinished = false;
	bool playAgain = true;
	int numRows;
	char tileRow;
	int numCols;
	int tileCol;
	int continueResponse = 0;

	cout << "Welcome to the C++ Board Game!!" << endl << endl;

	//do-while loop used to play game at least once and players can decide if they want to play again
	do {
		// collect information about the game
		cout << "Enter number of players: ";
		cin >> numPlayers;
		cout << numPlayers;
		cout << endl
				<< "Enter dimensions of the board, separated by spaces (rows cols): ";
		cin >> numRows >> numCols;
		cout << numRows << " " << numCols << endl;

		Board<char> board(numRows, numCols);
		board.printBoard();

		//start player's turn
		while (!isFinished) {
			cout << "It's your turn, Player " << playerTurn
					<< "! Enter a tile coordinate (Alpha_Lower Numeric): "
					<< endl;
			cin >> tileRow >> tileCol;

			//player places tile
			board.placeTile(tileRow, tileCol, 'A');

			//print new board
			board.printBoard();

			//check if game is complete

			// next player's turn
			if (playerTurn == numPlayers) {
				playerTurn = 1;
			} else {
				playerTurn++;
			}

		}
		// check if players want to play again
		cout << "Do you want to play again? (yes = 1/ no = 0)" << endl;
		cin >> continueResponse;

		if (continueResponse == 1) {
			cout << "response yes" << endl;
			playAgain = true;
		} else if (continueResponse == 0) {
			cout << "response no" << endl;
			playAgain = false;
		} else {
			while (!(continueResponse == 1 || continueResponse == 0)) {
				cout << "Invalid response: " << continueResponse
						<< "; select yes or no" << endl;
				cin >> continueResponse;
			}
		}

	} while (playAgain);

	/*DO NOT DELETE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*
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
	 */
}

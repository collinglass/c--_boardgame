#include <iostream>
#include <iomanip>
#include <vector>
#include "boardgame.h"

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
	char element;
	const char* exMsg;


	cout << "Welcome to the C++ Board Game!!" << endl << endl;

	//do-while loop used to play game at least once and players can decide if they want to play again
	do {
		// collect information about the game
		
		while ( !(numPlayers >= 3 && numPlayers <= 6) ) {
			cout << "Enter number of players: ";
			cin >> numPlayers;
			if ( numPlayers == 0 ) {
				cout << "No Ghosts allowed!";
				cout << endl << "Game can only be played with 3-6 players!" << endl;
			} else if ( numPlayers == 1 ) {
				cout << "This isn't solitaire! Get 2 to 5 more people!";
				cout << endl << "Game can only be played with 3-6 players!" << endl;
			} else if ( numPlayers == 2 ) {
				cout << "This is romantic, unfortunately get another person! or 2 or 3 or 4!";
				cout << endl << "Game can only be played with 3-6 players!" << endl;
			}
		}
		cout << numPlayers;

		BoardGame<char> boardgame(9, 12, 'A');

		//start player's turn
		while (!isFinished) {
			exMsg = "";
			cout << "It's your turn, Player " << playerTurn
			<< "! Enter a tile coordinate (Alpha_Lower Numeric): "
			<< endl;
			cin >> tileRow >> tileCol;
			if ( (tileRow >= 97 && tileRow <= 122) && (tileCol >= 0 && tileCol < numCols) ) {
				//player places tile
				Position _position;
				_position.row = tileRow;
				_position.col = tileCol;
				exMsg = boardgame.playAt(_position);

				//check if game is complete
				bool win = false;
				win = boardgame.checkWin();
				if ( win == true ) {
					isFinished = true;
					cout << "Player " << playerTurn << " is the winner!" << endl;
				}
			} else {
				exMsg = "Illegal input!";
			}
			if ( exMsg != "" ) {
				cerr << exMsg << endl;
			} else {
				// next players turn
				if (playerTurn == numPlayers) {
					playerTurn = 1;
				} else {
					playerTurn++;
				}
			}
		}
		// check if players want to play again
		cout << "Do you want to play again? (yes = 1/ no = 0)" << endl;
		cin >> continueResponse;
		if (continueResponse == 1) {
			cout << "response yes" << endl;
			isFinished = false;
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

#include "board.h"
#include "group.h"
#include <iostream>
#include <map>
#include <vector>

template<class T>
class BoardGame {
	Board<T> board;
	std::map<T, Group<T>*> mapT;
	T symbol;
public:
	BoardGame(char row, int col, T _symbol);
	void playAt(char row, int col);
};

template<class T> BoardGame<T>::BoardGame(char row, int col, T _symbol) : board(row, col) {
	symbol = _symbol;
	board.printBoard();
}

template<class T> void BoardGame<T>::playAt(char row, int col) {
	try {
		T tempTile;
		board.getTileAt(tempTile, row, col);
		if (tempTile == 0) {
			Group<T>* group = new Group<T>(symbol);

			// add to mapT
			T groupT = group->getDummy();
			
			// Get Adjacent tiles, if there are any adjacent tiles we need to figure which one is the biggest
			vector<T> vectorAdj = board.getAdjacent(row, col);
			for ( int i = 0; i < 4; i++ ) {
				T temp = vectorAdj.at(i);
				if (temp != 0) {
					typedef std::map<T, Group<T>*>::iterator it_type;
					for(it_type iterator = mapT.begin(); iterator != mapT.end(); iterator++) {
    					iterator->first = T;
    					iterator->second = Group<T>*;
    					
					}
				}
			}


			board.placeTile(row, col, groupT);
			board.printBoard();
		} else {
			throw "Illegal Move: selected tile is not empty!";
		}
	} catch (const char* exMsg) {
		cerr << exMsg << endl;
	}
}

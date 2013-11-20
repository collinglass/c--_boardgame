#include "board.h"
#include "group.h"
#include <iostream>
using namespace std;

template<class T>
class BoardGame {
	Board<T> board;
	map<T, Group*> mapT;
	T tile;
public:
	BoardGame::BoardGame(T symbol);
	BoardGame::BoardGame(char row, int col, T _tile);
	void playAt(char row, int col);
};

template<class T> BoardGame<T>::BoardGame(char row, int col, T _tile) {
	tile = _tile;
	board(row, col);
}

template<class T> void BoardGame<T>::playAt(char row, int col) {
	try {
		if (board.getTileAt(row, col) == 0) {
			Group<T>* group = new Group<T>;

			// add to mapT
			T groupT = group->getDummy();
			board.placeTile(row, col, groupT);
		} else {
			throw "Illegal Move: selected tile is not empty!";
		}
	} catch (const char* exMsg) {
		cerr << exMsg << endl;
	}
}

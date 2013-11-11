#include "board.h"

template <class T>
class BoardGame {
	Board<T> board;
	map<T,Group*> mapT;
	T tile;
public:
	BoardGame::BoardGame(T symbol);
	void playAt(char row, char col);
};

template<class T> BoardGame<T>::BoardGame(char row, int col, T _tile) {
	tile = _tile;
	board(row,col);
}

template<class T> void BoardGame<T>::playAt(char row, char col) {
	if ( board.getTileAt(row,col) == 0 ) {
		Group* group = new Group<tile>;
		// add to mapT
		T groupT = group->getDummy();
		board.placeTile(row,col, groupT);
	} else {
		// throw exception
	}
}
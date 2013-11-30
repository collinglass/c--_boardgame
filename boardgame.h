#include "board.h"
#include "group.h"
#include <iostream>
#include <map>
#include <vector>
#include <iterator>

template<class T>
class BoardGame {
	Board<T> board;
	std::map<T, Group<T>*> mapT;
	T symbol;
public:
	BoardGame(char row, int col, T _symbol);
	void playAt(Position _position);
};

template<class T> BoardGame<T>::BoardGame(char row, int col, T _symbol) : board(row, col) {
	symbol = _symbol;
	board.printBoard();
}

template<class T> void BoardGame<T>::playAt(Position _position) {
	try {
		T tempTile;
		board.getTileAt(tempTile, _position.row, _position.col);
		if (tempTile == 0) {
			Group<T>* group = new Group<T>(symbol);

			// add to mapT
			T groupT = group->getDummy();
			
			// Get Adjacent tiles, if there are any adjacent tiles we need to figure which one is the biggest
			vector<T> vectorAdj = board.getAdjacent(_position.row, _position.col);
			Group<T>* largestGroup = new Group<T>(' ');
			vector<Group<T>*> vectorGroup;

			for ( int i = 0; i < vectorAdj.size(); i++ ) {
				T temp = vectorAdj.at(i);
				typename std::map<T,Group<T>*>::iterator iter;
				if (temp != 0) {
					for( iter = mapT.begin(); iter != mapT.end(); iter++) {
    					// iterator->first = T;
    					// iterator->second = Group<T>*;
    					if ( temp == iter->first ) {
    						vectorGroup.push_back(iter->second);
    						if( largestGroup->getSize() < iter->second->getSize() ) {
    							largestGroup = iter->second;
    						}
    					}
					}
				}
			}
			largestGroup->addPosition(_position);
    		delete group;
    		Group<T>* tempGroup;
    		for ( int i = 0; i < vectorGroup.size(); i++ ) {
    			if ( vectorGroup.at(i) != largestGroup ) {
    				tempGroup = vectorGroup.at(i);
    				for ( int j = 0; j < tempGroup->getSize(); j++ ) {
    					largestGroup->addPosition(tempGroup->getPosition(i));
    				}
    				delete tempGroup;
    			}
    		}



			board.placeTile(_position.row, _position.col, groupT);
			board.printBoard();
		} else {
			throw "Illegal Move: selected tile is not empty!";
		}
	} catch (const char* exMsg) {
		cerr << exMsg << endl;
	}
}

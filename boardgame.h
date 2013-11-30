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
			
			if( mapT.size() == 0 ) {
				mapT.insert ( std::pair<T,Group<T>*>(groupT,group) );
			} else {
				// Get Adjacent tiles, if there are any adjacent tiles we need to figure which one is the biggest
				vector<T> vectorAdj = board.getAdjacent(_position.row, _position.col);
				Group<T>* largestGroup = new Group<T>(' ');
				vector<Group<T>*> vectorGroup;
				bool isNotEmpty = false;
				for ( int i = 0; i < vectorAdj.size(); i++ ) {
					T temp = vectorAdj.at(i);
					typename std::map<T,Group<T>*>::iterator iter;
					if (temp != 0) {
						isNotEmpty = true;
						for( iter = mapT.begin(); iter != mapT.end(); iter++) {
							cout << "buzz" << endl;
    						// iterator->first = T;
    						// iterator->second = Group<T>*;
    						if ( temp == iter->first ) {
    							vectorGroup.push_back(iter->second);
    							//cout << vectorGroup << endl;
    							if( largestGroup->getSize() < iter->second->getSize() ) {
    								cout << "This is: " << iter->second->getName() << "." << endl;
    								largestGroup = iter->second;
    							} else if ( largestGroup->getSize() == iter->second->getSize() ) {
    								cout << "This is iterator age: " << iter->second->getAge() << "." << endl;
    								cout << "This is largestGroup age: " << largestGroup->getAge() << "." << endl;
    								if ( largestGroup->getAge() > iter->second->getAge() ) {			// may cause problems
    									cout << "This is3: " << iter->second->getName() << "." << endl;
    									largestGroup = iter->second;
    								}
    							}
    						}
						}
					}
				}
				if( isNotEmpty == 0 ) {
					mapT.insert ( std::pair<T,Group<T>*>(groupT,group) );
				} else {
					largestGroup->addPosition(_position);	// not causing Segmentation Fault
					groupT = largestGroup->getSymbol();
					cout << largestGroup->getName() << "no" << endl;
    				delete group;
    				Group<T>* tempGroup;
    				for ( int i = 0; i < vectorGroup.size(); i++ ) { // vectorGroup not causing Segmentation Fault
    					
    					if ( vectorGroup.at(i)->getName() != largestGroup->getName() ) {
    						cout << vectorGroup.at(i)->getName() << "yes" << endl;
    						cout << largestGroup->getName() << "no" << endl;
    						tempGroup = vectorGroup.at(i);
    						for ( int j = 0; j < tempGroup->getSize(); j++ ) {
    							largestGroup->addPosition(tempGroup->getPosition(i));
    							groupT = largestGroup->getSymbol();
    						}
    						delete tempGroup;
    					}
    				}
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

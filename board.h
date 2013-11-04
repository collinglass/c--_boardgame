#include <vector>
#include <iostream>

using std::vector;

template <class T>
class Board {
	T** tiles;
public:
	Board(int cols, int rows);
    void placeTile(char col, int row, T element);
    T getTileAt(char col, int row);
    vector<T> getAdjacent(char col, int row);
};

template<class T> Board<T>::Board(int cols, int rows){
	tiles = new T*[rows];
	for (char i = 0; i < rows; i++ ) {
		tiles[i] = new T[cols];
	}
}

template<class T> void Board<T>::placeTile(char col, int row, T element){
   	if ( col >= 97 && col <= 122 ) {
   		col -= 97;
   		tiles[col][row] = element;
   	} else if ( col >= 65 && col <= 90 ) {
   		col -= 65;
   		tiles[col][row] = element;
   	} else {
   		std::cout << "Invalid Column Input!" << std::endl;
   	}
   	return;
}

template<class T> T Board<T>::getTileAt(char col, int row){
	T result;
	if ( col >= 97 && col <= 122 ) {
		col -= 97;
   		result = tiles[col][row];
	} else if ( col >= 65 && col <= 90 ) {
		col -= 65;
		result = tiles[col][row];
	} else {
		std::cout << "Invalid Column Input!" << std::endl;
	}
	return result;
}

template<class T> vector<T> Board<T>::getAdjacent(char col, int row){	 // up to 4 in the list
	vector<T> result;
	if ( col >= 97 && col <= 122 ) {
		col -= 97;
		result.push_back(tiles[col-1][row]);
		result.push_back(tiles[col+1][row]);
		result.push_back(tiles[col][row-1]);
		result.push_back(tiles[col][row+1]);
	} else if ( col >= 65 && col <= 90 ) {
		col -= 65;
		result.push_back(tiles[col-1][row]);
		result.push_back(tiles[col+1][row]);
		result.push_back(tiles[col][row-1]);
		result.push_back(tiles[col][row+1]);
	} else {
    		std::cout << "Invalid Column Input!" << std::endl;
	}
	return result;
}



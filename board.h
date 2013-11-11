#include <vector>
#include <iostream>

using std::vector;

template <class T>
class Board {
	T** tiles;
public:
	Board(int rows, int cols);
    void placeTile(char row, int col, T element);
    T getTileAt(char row, int col);
    vector<T> getAdjacent(char row, int col);
};

template<class T> Board<T>::Board(int rows, int cols){
	tiles = new T*[rows];
	for (char i = 0; i < rows; i++ ) {
		tiles[i] = new T[cols];
	}
}

template<class T> void Board<T>::placeTile(char row, int col, T element){
   	if ( row >= 97 && row <= 122 ) {
   		row -= 97;
   		tiles[row][col] = element;
   	} else if ( row >= 65 && row <= 90 ) {
   		row -= 65;
   		tiles[row][col] = element;
   	} else {
   		std::cout << "Invalid Row Input!" << std::endl;
   	}
   	return;
}

template<class T> T Board<T>::getTileAt(char row, int col){
	T result;
	if ( row >= 97 && row <= 122 ) {
		row -= 97;
   		result = tiles[row][col];
	} else if ( row >= 65 && row <= 90 ) {
		row -= 65;
		result = tiles[row][col];
	} else {
		std::cout << "Invalid Row Input!" << std::endl;
	}
	return result;
}

template<class T> vector<T> Board<T>::getAdjacent(char row, int col){	 // up to 4 in the list
	vector<T> result;
	if ( row >= 97 && row <= 122 ) {
		row -= 97;
		result.push_back(tiles[row-1][col]);
		result.push_back(tiles[row+1][col]);
		result.push_back(tiles[row][col-1]);
		result.push_back(tiles[row][col+1]);
	} else if ( row >= 65 && row <= 90 ) {
		row -= 65;
		result.push_back(tiles[row-1][col]);
		result.push_back(tiles[row+1][col]);
		result.push_back(tiles[row][col-1]);
		result.push_back(tiles[row][col+1]);
	} else {
    		std::cout << "Invalid Row Input!" << std::endl;
	}
	return result;
}

template <class T>
class Group {
	T symbol;
	std::string name;
	unsigned int size;
	static unsigned int counter;
public:
	T getDummy();
};

template<class T> unsigned int Group<T>::counter = 1;

template<class T> T Group<T>::getDummy(){
	symbol = (unsigned char)counter;
	return symbol;
}

#include <vector>
#include <iostream>

using namespace std;

template<class T>
class Board {
	T** tiles;
	int rows;
	int cols;
public:
	Board(int rows, int cols);
	void placeTile(char row, int col, T element);
	void getTileAt(T& tile, char row, int col);
	vector<T> getAdjacent(char row, int col);
	void printBoard();
};

template<class T> Board<T>::Board(int _rows, int _cols) :
		rows(_rows), cols(_cols) {
	tiles = new T*[_rows];
	for (int i = 0; i < _rows; i++) {
		tiles[i] = new T[_cols];
		T* element = &tiles[i][0];
		for (int j = 0; j < _cols; j++) {
			*element = 0;
			element++;
		}
	}
}

template<class T> void Board<T>::placeTile(char row, int col, T element) {
	if (static_cast<int>(row) >= 97 && static_cast<int>(row) <= 122) {
		row -= 97;
		tiles[static_cast<int>(row)][col] = element;
	} else {
		std::cout << "Invalid Row Input!" << std::endl;
	}
}

template<class T> void Board<T>::getTileAt(T& tile, char row, int col) {
	if (static_cast<int>(row) >= 97 && static_cast<int>(row) <= 122) {
		row -= 97;
		tile = tiles[static_cast<int>(row)][col];
	} else {
		tile = 0;
	}
}

template<class T> vector<T> Board<T>::getAdjacent(char row, int col) { // up to 4 in the list
	vector<T> result;
	if (static_cast<int>(row) >= 97 && static_cast<int>(row) <= 122) {
		row -= 97;

		// must add fail safe mechanism for edges
		if (row - 1 >= 0) {
			result.push_back(tiles[row - 1][col]); // north
		}
		if (row + 1 < rows) {
			result.push_back(tiles[row + 1][col]); // south
		}
		if (col - 1 >= 0) {
			result.push_back(tiles[row][col - 1]); // west
		}
		if (col + 1 < cols) {
			result.push_back(tiles[row][col + 1]); // east
		}
	} else {
		cout << "Invalid Row Input!" << endl;
	}
	return result;
}

template<class T> void Board<T>::printBoard() {
	T tile;
	for (int i = 0; i < rows; i++) {
		cout << "[ ";
		for (int j = 0; j < cols; j++) {
			getTileAt(tile, i + 97, j);
			cout << setw(5) << tile << " ";
		}
		cout << "]" << endl;
	}

}

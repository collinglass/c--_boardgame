template <class T>
class Board {
	T** tiles;
public:
	Board(int cols, int rows){
		tiles = new T[rows];
		for (char i = 0; i < rows; i++ ) {
			tiles[i] = new T[cols];
		}
	}
    placeTile(char col, int row, T element){

    }
    T getTileAt(char col, int row){

    }
    vector<T> getAdjacent(char col, int row){	 // up to 4 in the list

    }
};
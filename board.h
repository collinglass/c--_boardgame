template <class T>
class Board {
	T** tiles;
public:
	Board(int cols, int rows){
		tiles = new T[rows];
		for (int i = 0; i < rows; i++ ) {
			tiles[i] = new T[cols];
		}
	}
    placeTile(char, int, T){

    }
    T getTileAt(char, int){

    }
    vector<T> getAdjacent(char, int){	 // up to 4 in the list

    }
};
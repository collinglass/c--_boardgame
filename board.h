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
    void placeTile(char col, int row, T element){
    	if ( col >= 97 && col <= 122 ) {
    		col -= 97;
    		tiles[col][row] = element;
    	} else if ( col >= 65 && col <= 90 ) {
    		col -= 65;
    		tiles[col][row] = element;
    	} else {
    		std::cout << "Invalid Column" << std::endl;
    	}
    	return;
    }
    T getTileAt(char col, int row){

    }
    vector<T> getAdjacent(char col, int row){	 // up to 4 in the list

    }
};
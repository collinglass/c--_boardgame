/*
 * group.h
 *
 *  Created on: Nov 14, 2013
 *      Author: Arash
 */

struct Position {
	char row;
	int col;
};

template <class T>
class Group {
	T symbol;
	vector<Position> positions;
	std::string name;
	unsigned int size;
	unsigned int age;
	static unsigned int counter;
public:
	Group(T _symbol);
	std::string getName();
	unsigned int getSize();
	void addPosition(Position _position);
	unsigned int getAge();
	T getSymbol();
	T getDummy();
};

template<class T> unsigned int Group<T>::counter = 0;

template<class T> Group<T>::Group(T _symbol) {
	symbol = _symbol;
	size = 1;
	age = 1 + counter;
	name = _symbol;
}

template<class T> std::string Group<T>::getName(){
	return name;
}

template<class T> unsigned int Group<T>::getSize(){
	return size;
}

template<class T> void Group<T>::addPosition(Position _position){
	positions.push_back(_position);
	size++;
	return;
}

template<class T> unsigned int Group<T>::getAge(){
	return age;
}

template<class T> T Group<T>::getSymbol(){
	return symbol;
}

template<class T> T Group<T>::getDummy(){
	symbol = symbol + counter;
	counter++;
	return symbol;
}

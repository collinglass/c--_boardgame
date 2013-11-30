/*
 * group.h
 *
 *  Created on: Nov 14, 2013
 *      Author: Arash
 */
template <class T>
class Group {
	T symbol;
	std::string name;
	unsigned int size;
	unsigned int age;
	static unsigned int counter;
public:
	Group(T _symbol);
	std::string getName();
	unsigned int getSize();
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

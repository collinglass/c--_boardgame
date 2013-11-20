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
	static unsigned int counter;
public:
	T getDummy();
};

template<class T> unsigned int Group<T>::counter = 1;

template<class T> T Group<T>::getDummy(){
	symbol = (unsigned char)counter;
	return symbol;
}

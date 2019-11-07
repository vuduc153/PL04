#ifndef MYPAIR_H
#define MYPAIR_H

template <typename T1, typename T2>
class MyPair {
public:
	T1 first;
	T2 second;
	MyPair(T1 arg1, T2 arg2);	
};

template <typename T1, typename T2>
MyPair<T1, T2>::MyPair(T1 arg1, T2 arg2) {
	this->first = arg1;
	this->second = arg2;
}

#endif
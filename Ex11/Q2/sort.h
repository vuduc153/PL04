#ifndef SORT_H
#define SORT_H
#include <iostream> 
#include <algorithm> 
#include <vector>

template <class Ran>
void sort(Ran begin, Ran end) {
	for(Ran current = begin; current != end - 1; ++current) {
		for(Ran i = begin; i != end; ++i) {
			if(*i > *(i + 1)) {
				std::iter_swap(i, i + 1);
			}
		}
	}	
}

#endif
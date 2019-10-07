#include <iostream>
#include "stack.h"

bool Stack::empty() {
	if(_top == -1) 
		return true;
	return false;
}

bool Stack::full() {
	if(_top == _max_size)
		return true;
	return false;
}

int Stack::size() {
	return _top;
}

void Stack::push(int num) {
	if(Stack::full()) {
		std::cerr << "Stack overflows" << std::endl;
		return;
	}
	_top ++;
	_data[_top] = num;
}

void Stack::pop() {
	if(Stack::empty()) {
		std::cerr << "Stack underflows" << std::endl;
		return;
	}
	_top --;
}

int Stack::top() {
	return _data[_top];
}
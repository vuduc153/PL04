// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    int* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        int* temp = new int[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    ArrayStack(): _num_items(0), _allocated_size(0), _items(nullptr) {}
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to a null pointer, 
     */

    explicit ArrayStack(int allocated_size) {
        _num_items = 0;
        _allocated_size = allocated_size;
        int *stack = new int[allocated_size];
        _items = stack;
    }
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */

    // Copy Constructor:
    ArrayStack(const ArrayStack& stack) {
        std::cout << "Copy Constructor" << std::endl;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;
        _items = new int[_allocated_size];
        int i;
        for(i = 0; i < _allocated_size; i ++) 
            _items[i] = stack._items[i];
    }

    // Assignment Operator:
    ArrayStack& operator= (const ArrayStack& stack) {
        std::cout << "Assignment Operator" << std::endl;
        if(this == &stack) return *this;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;
        delete[] _items;
        _items = new int[_allocated_size];
        int i;
        for(i = 0; i < _allocated_size; i ++) 
            _items[i] = stack._items[i];
        return *this;
    }

    // Move Constructor:
    ArrayStack(ArrayStack&& stack) {
        std::cout << "Move Constructor" << std::endl;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;
        _items = stack._items;
        stack._items = nullptr;
    }

    // Move Assignment Operator:
    ArrayStack& operator= (ArrayStack&& stack) {
        std::cout << "Move Assignment Operator" << std::endl;
        if(this == &stack) return *this;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;
        delete[] _items;
        _items = stack._items;
        stack._items = nullptr;
        return *this;
    }   

    // Destructor::
    ~ArrayStack() {
        // COMPLETE
        delete[] _items;
    }

    void push(int item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    int pop() {
        int ret = _items[--_num_items];
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
        return ret;
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H
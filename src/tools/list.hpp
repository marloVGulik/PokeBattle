#pragma once
#include <iostream>

template<typename T>
class List {
    protected:
    T* _data;
    size_t _size;
    public:
    List(T List[], int size = 0);
    ~List();
    // List operator [] (int i) { return _data[i]; };

    T at(unsigned int i) { if(i < _size) return _data[i]; };
    size_t size() { return _size; };
    T* data() { return _data; };

    void push(T data);

};

#include "list.cpp"
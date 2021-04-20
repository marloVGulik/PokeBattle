#include "list.hpp"

template<typename T>
List<T>::List(T List[], int size) {
    _data = new T[size];
    _size = size;

    std::cout << "Created an array of size " << size << "\n";
}

template<typename T>
List<T>::~List() {
    delete _data;
}

template<typename T>
void List<T>::push(T data) {
    _size += 1;
    if(_size > 0) std::cout << "DATA_O: " << _data[0] << "\n";
    T* tmpPtr = _data;
    _data = new T[_size];
    std::cout << "DATA_N: " << tmpPtr[0] << "\n";
    memmove(_data, tmpPtr, _size - 1);
    _data[_size - 1] = data;
}
#pragma once

#include <iostream>
#include <string>
#include "string.h"

template <typename T>
class TVector {
    private:
        T *_container;
        size_t _size;
        size_t _capacity;
    public:
        TVector();
        TVector(const T& el, size_t size);
        TVector(const TVector &other);
        TVector(TVector &&other) noexcept;
        TVector(const std::initializer_list<T> &list);
        ~TVector();
        const T& operator[](size_t idx) const;
        T& operator[](size_t idx);
        TVector<T> &operator=(const TVector &other);
        TVector<T> &operator=(TVector &&other) noexcept;
        void Push_back(const T &elem);
        size_t Size() const;
        size_t Capacity() const;
        void Reserve(size_t size);
};

template <typename T>
size_t TVector<T>::Capacity() const {
    return _capacity;
}

template <typename T>
TVector<T>::TVector(const T& el, size_t size) {
    _size = size;
    _capacity = size * 1.5 + 1;
    _container = new T[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _container[i] = el;
    }
}

template <typename T>
TVector<T>::TVector() {
    _size = 0;
    _capacity = 1;
    _container = new T[_capacity];
}

template <typename T>
void TVector<T>::Reserve(size_t size) {
    T* tmpContainer = new T[size];
    for (int i = 0; i < _size; ++i) {
        tmpContainer[i] = _container[i];
    }
    _container = tmpContainer;
    _capacity = size;
}

template <typename T>
TVector<T>::TVector(TVector<T> &&other) noexcept {
    _size = other._size;
    _capacity = other._capacity;
    _container = std::move(other._container);
}

template <typename T>
TVector<T>::TVector(const TVector<T> &other) {
    _size = other._size;
    _capacity = other._capacity;
    _container = new T[_capacity];
    for (int i = 0; i < other.Size(); i++) {
        _container[i] = other._container[i];
    }
}

template <typename T>
TVector<T>::~TVector() {
    _size = 0;
    _capacity = 0;
    delete[] _container;
    _container = nullptr;
}

template <typename T>
TVector<T>::TVector(const std::initializer_list<T> &list) {
    _size = list.size();
    _capacity = _size * 1.5 + 1;
    size_t i = 0;
    _container = new T[_capacity];
    for (const char &c: list) {
        _container[i] = c;
        ++i;
    }
}

template <typename T>
T& TVector<T>::operator[](size_t idx) {
    return _container[idx];
}

template <typename T>
const T& TVector<T>::operator[](size_t idx) const{
    return _container[idx];
}

template <typename T>
TVector<T> &TVector<T>::operator=(const TVector<T> &other) {
    std::cout << "copying vec\n";
    _size = other._size;
    _capacity = other._capacity;
    _container = new T[_capacity];
    memcpy(_container, other._container, other.Size() * sizeof(T));
    return *this;
}

template <typename T>
TVector<T> &TVector<T>::operator=(TVector<T> &&other) noexcept{
    std::cout << "moving vec\n";
    std::swap(_size, other._size);
    std::swap(_container, other._container);
    std::swap(_capacity, other._capacity);
    return *this;
}

template <typename T>
size_t TVector<T>::Size() const {
    return _size;
}

template <typename T>
void TVector<T>::Push_back(const T& elem) {
    // for (int i = 0; i < _size; ++i) {
    //     std::cout << _container[i];
    // }
    // std::cout << _size << "AA\n";
    if (_size < _capacity) {
        std::cout << "moving el in TVec\n";
        _container[_size] = elem;
    } else {
        T* newArray = new T[int(_capacity * 1.5) + 1];
        for (int i = 0; i < _size; ++i) {
            newArray[i] = _container[i];
        }
        newArray[_size] = elem;
        _container = newArray;
        _capacity = int(_capacity * 1.5) + 1;
    }
    ++_size;
    // for (int i = 0; i < _size; ++i) {
    //     std::cout << _container[i];
    // }
    // std::cout << _size << "BB\n" ;
}
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <type_traits>

template <typename T,typename = typename std::enable_if<std::is_arithmetic<T>::value,T>::type>
class NumArray {
    std::vector<T> _data;
public:

    //constructor from initializer list of T values
    NumArray(std::initializer_list<T> list) : _data(list) {}
    // GetVec method returning vector of T values
    std::vector<T>& GetVec() {return _data;}
    // set method for setting value of type T at index
    NumArray<T>& set(T val, size_t index) {
        _data[index] = val;
        return *this;
    }
    // print method for printing vector of T values
    void print() const {
        for (const auto& val : _data) {
            std::cout << val << "   ";
        }
        std::cout << std::endl;
    }
};
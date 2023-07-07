#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Klasy.h"
//swap template swapping elements using memcpy
template<typename T>
void swapit(T& a, T& b) {
    T tmp;
    memcpy(&tmp, &a, sizeof(T));
    memcpy(&a, &b, sizeof(T));
    memcpy(&b, &tmp, sizeof(T));
}
//special swap function for SkomplikowanaKlasa type
void swapit(SkomplikowanaKlasa&a,SkomplikowanaKlasa&b);
//bubble sort template sorting an array
template<typename T,typename U>
void bubble_sort(std::vector<T>& v, U comp) {
    for (unsigned i = 0; i < v.size(); ++i) {
        for (unsigned j = i+1; j < v.size(); ++j) {
            if (comp(v[i], v[j])) {
                swapit(v[i], v[j]);
            }
        }
    }
}
//print function printing arrays on screen
template<typename T,int N>
void print(T (&v)[N]) {
    for (int i = 0; i < N; ++i) {
        std::cout << v[i] << std::endl;
    }
}
/*template<typename T>
void print(T& v) {
    for (auto &val: v) {
        std::cout << val << std::endl;
    }
}*/
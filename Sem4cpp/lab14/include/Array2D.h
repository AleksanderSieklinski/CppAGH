#pragma once
#include "BadDimsException.h"

class Array2D{
    int nx,ny;
    int *arr;
public:
    //constructor of Array2D creates a 2D array of size a*b
    Array2D(int a, int b);
    //destructor of Array2D deletes the 2D array
    ~Array2D();
    //reshape changes the dimensions of the 2D array
    void reshape(int a, int b);
    //operator[] returns a pointer to the ith row of the 2D array
    int* operator[](int i);
    //at returns a reference to the element at the ith row and jth column of the 2D array
    int& at(int i, int j) const;
    //at does the same as above, but it is used when the 2D array is non-const
    int& at(int i, int j);
    //operator<< prints the 2D array
    friend std::ostream& operator<<(std::ostream& os, const Array2D& arr);
};
#pragma once
#include <iostream>
#include "Fraction.h"

class FractionArray
{
public:
    FractionArray(int i):_arr(new Fraction[i]){}
    ~FractionArray(){
        delete [] _arr;
    }
    Fraction& operator[](int i);
    const Fraction operator[](int i) const;
private:
    Fraction* _arr;
};
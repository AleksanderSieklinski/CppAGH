#include "FractionArray.h"

Fraction& FractionArray::operator[](int i){
    return _arr[i];
}

const Fraction FractionArray::operator[](int i) const{
    return _arr[i];
}
#include "Vector.h"
Vector::Vector(int i) {
    SetX(i,i);
    SetY(i,i);
    SetZ(i,i);
}

ComplexNumber & Vector::X() { return _X; }

Vector & Vector::SetX(double x, double y) {
    _X._x = x;
    _X._y = y;
    return *this;
}
Vector & Vector::SetY(double x, double y) {
    _Y._x = x;
    _Y._y = y;
    return *this;
}
Vector & Vector::SetZ(double x, double y) {
    _Z._x = x;
    _Z._y = y;
    return *this;
}
void Vector::Print() const {
    if(_X._x == 0 && _X._y == 0 && _Y._x == 0 && _Y._y == 0 
    && _Z._x == 0 && _Z._y == 0){
        std::cout<<"[]\n";
    }
    else {
        std::cout<<"[("<<_X._x<<", "<<_X._y<<"), ("<<_Y._x<<", "
        <<_Y._y<<"), ("<<_Z._x<<", "<<_Z._y<<")]\n";
    }
    
}
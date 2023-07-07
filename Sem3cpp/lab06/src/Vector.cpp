#include "Vector.h"
static Vector *ToBeRemoved = nullptr;
static Vector v;

Vector::Vector(Vector &&m) : _X(std::move(m._X)), _Y(std::move(m._Y)), _Z(std::move(m._Z)) {
m.SetX(0, 0);
m.SetY(0, 0);
m.SetZ(0, 0);
ToBeRemoved = &m;
}
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

ComplexNumber & Vector::X() { return _X; }
const ComplexNumber Vector::X() const { return _X; }

const Vector *Vector::CreateConstVector(ComplexNumber X, ComplexNumber Y, ComplexNumber Z) {
    static Vector v;
    v._X = X;
    v._Y = Y;
    v._Z = Z;
    return &v;
}

void Vector::Cleanup() {
    if (ToBeRemoved)
    {
        delete ToBeRemoved;
        ToBeRemoved = nullptr;
    }
}

void Vector::Print() const {
    if(_X._x == 0 && _X._y == 0 && _Y._x == 0 && _Y._y == 0 && _Z._x == 0 && _Z._y == 0){
        std::cout << "[]\n";
    }
    else {
        std::cout << "[(" << _X._x << ", " << _X._y << "), (" 
                  << _Y._x << ", " << _Y._y << "), ("
                  << _Z._x << ", " << _Z._y << ")]\n";
    }
    
}
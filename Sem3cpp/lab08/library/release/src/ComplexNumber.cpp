#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double x, double y) : _x(x), _y(y) {};

double ComplexNumber::Abs(ComplexNumber&a) {return sqrt(pow(a._x,2)+pow(a._y,2));}

void ComplexNumber::Print() const { std::cout << "(" <<_x<< ", " <<_y<< ")"; }

ComplexNumber::operator double() {return Abs(*this);}
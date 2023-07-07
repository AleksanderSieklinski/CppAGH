#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double x, double y) : _x(x), _y(y) {};
void ComplexNumber::Print() const { std::cout << "(" <<_x<< ", " <<_y<< ")"; }
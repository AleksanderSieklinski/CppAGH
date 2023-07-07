#ifndef ComplexNumber_h
#define ComplexNumber_h
#include <iostream>
class Vector;
class ComplexNumber
{
    public:
        friend class Vector;
        ComplexNumber() {}
        ComplexNumber(double,double);
        void Print() const;
    private:
        double _x;
        double _y;
};
#endif
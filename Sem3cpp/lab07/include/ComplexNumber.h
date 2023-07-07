#ifndef ComplexNumber_h
#define ComplexNumber_h
#include <iostream>
#include <cmath>
class Vector;
class ComplexNumber
{
    public:
        //befriending class Vector
        friend class Vector;
        //default constructor
        ComplexNumber() {}
        //constructor setting the values of _x and _y
        ComplexNumber(double,double);
        //conversion function from ComplexNumber to double (using Abs function)
        explicit operator double();
        //function returning sqrt'd sum of sqared values _x and _y
        static double Abs(ComplexNumber&);
        //printing the values of (_x,_y)
        void Print() const;
    private:
        double _x;
        double _y;
};
#endif
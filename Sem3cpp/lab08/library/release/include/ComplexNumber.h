#ifndef ComplexNumber_h
#define ComplexNumber_h
#include <iostream>
#include <cmath>
class ComplexNumber
{
    public:
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
        double Get_X() const {return _x;}
        double Get_Y() const {return _y;}
        double Set_X(double x) {return _x = x;}
        double Set_Y(double y) {return _y = y;}
    private:
        double _x;
        double _y;
};
#endif
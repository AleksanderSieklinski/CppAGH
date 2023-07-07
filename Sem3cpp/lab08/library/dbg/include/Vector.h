#ifndef Vector_h
#define Vector_h
#include "ComplexNumber.h"
namespace REL{}
namespace DBG {
class Vector
{
    public:
        //default constructor
        Vector() {}
        //conversion constructor from int to Vector
        Vector(int);
        //returning the _X object
        ComplexNumber & X();
        //setting the values of _X
        Vector & SetX(double,double);
        //setting the values of _Y
        Vector & SetY(double,double);
        //setting the values of _Z
        Vector & SetZ(double,double);
        //printing the (_x,_y) values of [_X,_Y,_Z]
        void Print() const;
    private:
        ComplexNumber vector[3]={ComplexNumber(0,0),ComplexNumber(0,0),ComplexNumber(0,0)};
};
}
#endif
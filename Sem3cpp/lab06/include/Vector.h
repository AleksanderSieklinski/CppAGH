#ifndef Vector_h
#define Vector_h
#include "ComplexNumber.h"
class Vector
{
    public:
        Vector(Vector&&);
        Vector() {}
        Vector & SetX(double,double);
        Vector & SetY(double,double);
        Vector & SetZ(double,double);
        ComplexNumber & X();
        const ComplexNumber X() const;
        static const Vector *CreateConstVector(ComplexNumber, ComplexNumber, ComplexNumber);
        static void Cleanup();
        void Print() const;
    private:
        ComplexNumber _X;
        ComplexNumber _Y;
        ComplexNumber _Z;
};
#endif
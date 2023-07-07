#include "Vector.h"
using namespace DBG;
Vector::Vector(int i) {
    SetX(i,i);
    SetY(i,i);
    SetZ(i,i);
}

ComplexNumber & Vector::X() { return vector[1]; }

Vector & Vector::SetX(double x, double y) {
    vector[0].Set_X(x);
    vector[0].Set_Y(y);
    return *this;
}
Vector & Vector::SetY(double x, double y) {
    vector[1].Set_X(x);
    vector[1].Set_Y(y);
    return *this;
}
Vector & Vector::SetZ(double x, double y) {
    vector[2].Set_X(x);
    vector[2].Set_Y(y);
    return *this;
}
void Vector::Print() const {
    std::cout<<"[";
    for(int i=0;i<3;i++){
        if(vector[i].Get_X() == 0 && vector[i].Get_Y() == 0) {
            std::cout<<"()";
        }
        else {
            vector[i].Print();
            std::cout<<", ";
        }
    }
    std::cout<<"]"<<std::endl;
}
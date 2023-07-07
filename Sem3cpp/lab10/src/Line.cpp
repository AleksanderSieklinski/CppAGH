#include "Line.h"
Line::Line():_a{1},_b{1}{}
Line::Line(double a): _a{a},_b{a}{}
Line::Line(double a,double b):_a{a},_b{b} {}
LArray::LArray():_size{0},_count{0}{}
LArray::LArray(size_t a): _size{a},_count{0}{_tab = new Line(_size);}
LArray::~LArray() {delete []_tab;}

double Line::operator()(double x) const{
    return _a*x+_b;
}
int Line::X0() const{
    return -(_b/_a);
}
void LPrint::operator()(const Line &obj) const{
    std::cout<<"y = "<<obj._a<<"* x + "<<obj._b<<"\tx0 = "<<obj.X0()<<std::endl;
}
void LArray::Add(int a) {
    _tab[_count]._a=a;
    _tab[_count]._b=a;
    _count++;
}
void LArray::Add(Line& obj) {
    _tab[_count]=obj;
    _count++;
}
Line& LArray::operator[](int i) const{
    return _tab[i];
}
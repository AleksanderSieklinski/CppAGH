#include "FunctionSeries.h"
void FunctionSeries::insert(std::function <double(double)> funkcja) {
    _size++;
    std::function<double(double)> *temp = new std::function<double(double)> [_size];
    for(int i=0;i<_size-1;i++) {
        temp[i]=_tab[i];
    }
    if(_size>1) {
        delete [] _tab;
    }
    temp[_size-1]=funkcja;
    _tab=temp;
}
double FunctionSeries::calculate(double x) {
        double res,temp1=x;
        _x=x;
        for(int i=0;i<_size;i++) {
            res=_tab[i](temp1);
            temp1=res;
        }
        return res;
    }
double FunctionSeries::step(int x) {
    double res,temp1=_x;
     for(int i=0;i<=x;i++) {
        res=_tab[i](temp1);
        temp1=res;
     }
     return res;
}
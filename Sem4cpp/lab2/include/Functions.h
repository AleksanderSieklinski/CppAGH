#pragma once
#include <iostream>
#include <cmath>
class Sin {
    public:
    //constructor of Sin class
    Sin(double a=1.0,double b=0):_a{a},_b{b}{}
    //overloaded () operator to return value of sin
    double operator()(double x) const{
        return sin(_a*x+_b);
    }
    private:
    double _a,_b;
};
class Linear {
    public:
    //constructor of Linear class
    Linear(double a=1.0,double b=0):_a{a},_b{b}{}
    //overloaded () operator to return value of linear function
    double operator()(double x) const{
        return _a*x+_b;
    }
    private:
    double _a,_b;
};
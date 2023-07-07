#pragma once
#include "Functions.h"
#include <functional>
class FunctionSeries {
public:
    //constructor of FunctionSeries class
    FunctionSeries(int size=0):_size{size} {}
    //destructor of FunctionSeries class
    ~FunctionSeries() {delete [] _tab;}
    //method inserting functions into *tab
    void insert(std::function<double(double)>);
    //method calculating a loop of arguments from functions in *tab
    double calculate(double);
    //method similar to calculating but with defined depth of looping arguments
    double step(int x);
private:
    std::function<double(double)> *_tab;
    int _size;
    double _x;
};
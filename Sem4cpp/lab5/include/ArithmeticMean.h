#pragma once
#include "HarmonicMean.h"

class ArithmeticMean : public Mean {
    public:
    //function returning the arithmetic mean number
    virtual double result();
    //operator adding values to mean calculation
    virtual Mean& operator<<(double);
    //function returning the type of mean performed
    virtual std::string nazwasr(){return "Arithmetic";}
    //function resetting the numbers for arithmetic mean
    virtual void reset();
    //const operator returning the message that no values can be assigned because its const
    virtual const Mean& operator<<(double) const;
};
#pragma once
#include <iostream>
#include <string.h>
//abstract class
class Mean {
    public:
        virtual double result()=0;
        virtual Mean& operator<<(double)=0;
        virtual void reset() =0;
        virtual std::string nazwasr()=0;
        virtual const Mean& operator<<(double) const=0;
    protected:
        double licznik=0,mianownik=0;
};
class HarmonicMean : public Mean {
    public:
    //function returning the harmonic mean number
    virtual double result(); 
    //function resetting the numbers for harmonic mean
    virtual void reset();
    //operator adding values to mean calculation
    virtual Mean& operator<<(double liczba);
    //function returning the type of mean performed
    virtual std::string nazwasr(){return "Harmonic";}
    //const operator returning the message that no values can be assigned because its const
    virtual const Mean& operator<<(double) const;
};
//global function returning the type of mean performed
std::ostream& operator<<(std::ostream& o, Mean& m); 
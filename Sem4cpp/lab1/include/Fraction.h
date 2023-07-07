#pragma once
#include <iostream>

class Fraction
{
public:
    Fraction(int l=0, int m=1):_licznik(l), _mianownik(m){}
    Fraction simplify();
    const Fraction operator+(const Fraction& fr) const;
    Fraction operator*(const Fraction& fr) const;
    friend std::ostream& operator<<(std::ostream& s, const Fraction& fr);
    friend Fraction operator*(int i, Fraction fr);
    operator double() const{
        return static_cast<double>(_licznik)/static_cast<double>(_mianownik);
    }
private:
    int _licznik;
    int _mianownik;
};

std::ostream& operator<<(std::ostream& s, const Fraction& fr);
Fraction operator*(int i, Fraction fr);
#include "Fraction.h"
#include "Maths.h"

using namespace std;

Fraction Fraction::simplify(){
    int d=Maths::gcd(_licznik, _mianownik);
    _licznik=_licznik/d;
    _mianownik=_mianownik/d;
    return *this;
}

const Fraction Fraction::operator+(const Fraction& fr) const{
    int l,m;
    l=_licznik*fr._mianownik+_mianownik*fr._licznik;
    m=_mianownik*fr._mianownik;
    const Fraction result(l,m);
    return result;
}

Fraction Fraction::operator*(const Fraction& fr) const{
    Fraction result;
    result._licznik=_licznik*fr._licznik;
    result._mianownik=_mianownik*fr._mianownik;
    result.simplify();
    return result;
}

ostream& operator<<(ostream& s, const Fraction& fr){
    s<<fr._licznik<<"/"<<fr._mianownik;
    return s;
}

Fraction operator*(int i, Fraction fr){
    Fraction temp;
    temp._licznik=fr._licznik*i;
    temp._mianownik=fr._mianownik;
    return temp;
}
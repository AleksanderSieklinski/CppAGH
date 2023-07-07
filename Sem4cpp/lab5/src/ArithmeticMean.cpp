#include "ArithmeticMean.h"
double ArithmeticMean::result() {
    if(mianownik==0) return 0;
    return licznik/mianownik;
}
Mean& ArithmeticMean::operator<<(double liczba) {
        licznik+=liczba;
        mianownik++;
        return *this;
    }
void ArithmeticMean::reset() {
    licznik=0;
    mianownik=0;
}
const Mean& ArithmeticMean::operator<<(double liczba) const {
    std::cout<<"cannot add value "<<liczba<<" to const"<<std::endl;
    return *this;
}
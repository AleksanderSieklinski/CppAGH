#include "HarmonicMean.h"
double HarmonicMean::result() {
    if(mianownik==0) return 0;
    return mianownik/licznik;
}
Mean& HarmonicMean::operator<<(double liczba) {
    licznik+=1/liczba;
    mianownik++;
    return *this;
}
std::ostream& operator<<(std::ostream& o, Mean& m) {
    o<<m.nazwasr();
    return o;
}
const Mean& HarmonicMean::operator<<(double liczba) const {
    std::cout<<"cannot add value "<<liczba<<" to const"<<std::endl;
    return *this;
}
void HarmonicMean::reset() {
    licznik=0;
    mianownik=0;
}

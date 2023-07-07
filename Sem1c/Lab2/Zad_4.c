#include <stdio.h>
    int main () {
    double suma=0;
    double liczba=1.;
    int n=1;
    long long int ile=0;
    while (suma<10.) {
        suma+=liczba;
        liczba=1./(1+n);
        n++;
        ile++;
    }
    printf("Suma %ld elementów:",ile);
    printf(" %.12 lf\n",suma);
    
    return 0;	
}

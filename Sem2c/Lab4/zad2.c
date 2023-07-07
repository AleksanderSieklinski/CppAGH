#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *podloga(double *arg1,double *arg2) {
    static int wynik;
    wynik = floor(*arg1* *arg2);
    return &wynik;
}

int main(void){
    double a=6.5,b=8.9;
    int *rozw = podloga(&a,&b);
    printf("Rozw: %d\n",*rozw);
    return 0;	
}

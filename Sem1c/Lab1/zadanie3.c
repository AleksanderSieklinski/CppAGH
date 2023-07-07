#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    int main(void){
    time_t czas;
    srand( (unsigned int)time(&czas) );  
    int a = 118;
    int b = 286;
    int n=0;
    int min = 0;
    int max = 0;
    int suma = 0;
    float srednia = 0;
    int ile = 0;
    for (int i=0;i<20;i++) {
        n = rand()%(b-a+1) +a;
        if (n<min) {
        min=n;
        }
        if (n>max) {
        max=n;
        }
        suma = suma + n;
        ++ile;
    }
    srednia = suma/ile;
    printf ("Wartość max =%d, wartość min =%d, średnia arytmetyczna =%.5f", max , min , srednia);
    
return 0;	
}

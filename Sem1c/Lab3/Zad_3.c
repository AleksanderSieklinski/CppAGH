#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main () {
    time_t czas;   

    srand( (unsigned int)time(&czas) );
    int n;
    printf("Podaj liczbę losowań:");
    scanf("%d",&n);
    int tab[10];
    for(int i=0;i<n;i++) {
    float n= (float)rand()/(float)(RAND_MAX)*9.9999;
    if(n<1) {
    tab[0]=tab[0]+n;
    }
    else if(n<2) {
    tab[1]=tab[1]+n;
    }
    else if(n<3) {
    tab[2]=tab[2]+n;
    }
    else if(n<4) {
    tab[3]=tab[3]+n;
    }
    else if(n<5) {
    tab[4]=tab[4]+n;
    }
    else if(n<6) {
    tab[5]=tab[5]+n;
    }
    else if(n<7) {
    tab[6]=tab[6]+n;
    }
    else if(n<8) {
    tab[7]=tab[7]+n;
    }
    else if(n<9) {
    tab[8]=tab[8]+n;
    }
    else if(n<10) {
    tab[9]=tab[9]+n;
    }
    }
    printf("Przedzial [0, 1): %f",tab[0])
    printf("Przedzial [1, 2): %f",tab[1])
    printf("Przedzial [2, 3): %f",tab[2])
    printf("Przedzial [3, 4): %f",tab[3])
    printf("Przedzial [4, 5): %f",tab[4])
    printf("Przedzial [5, 6): %f",tab[5])
    printf("Przedzial [6, 7): %f",tab[6])
    printf("Przedzial [7, 8): %f",tab[7])
    printf("Przedzial [8, 9): %f",tab[8])
    printf("Przedzial [9, 10): %f",tab[9])
    return 0;	
}

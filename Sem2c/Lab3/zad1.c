#include <stdio.h>

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.1f,", *poczatek++); 
  printf ("\n");    
  return;}

void wypelnij(double tab[][6],int w) {
    double wart = -1.5;
    for(int i=0;i<w;i++) {
        for(int j=0;j<6;j++) {
            tab[i][j]=wart;
            wart+=0.4;
        }
    }
}
int main(void){
    double A_1[8][6],A_2[10][6];
    wypelnij (A_1, 8);
    wypelnij (A_2, 10);
    wypisz_d(A_1[0],A_1[7]);
    wypisz_d(A_2[0],A_2[9]);
    for(int i=0;i<8;i++) {
        printf("%d wiersz: ",i);
        wypisz_d(A_1[i],A_1[i]+6);
        printf("\n");
    }
    for(int i=0;i<10;i++) {
        printf("%d wiersz: ",i);
        wypisz_d(A_2[i],A_2[i]+6);
        printf("\n");
    }
    return 0;	
}

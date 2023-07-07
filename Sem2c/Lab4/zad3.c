#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rows 3
#define columns 3
int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
 
 void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
  
float *tab_avg(int tab[][columns],int x) {
    float *tab1 = malloc(x*sizeof(float));
    float suma=0;
    for(int i=0;i<x;i++) {
        for (int j=0;j<columns;j++) {
            suma+=tab[i][j];
           if(j==(columns-1)) {
               tab1[i]=suma/columns;
               suma=0;
               }
           }
        }
    return tab1;
}

void wypisz_f (float *poczatek, float *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
  
int main(void){
    srand((unsigned)time(0));
    int tab[rows][columns];
    for(int i=0;i<rows;i++) { 
        for(int j=0;j<columns;j++) {
            tab[i][j]=rand()%11-5;
        }
        wypisz_i(tab[i],tab[i]+columns);
    }
    float *p = tab_avg(tab,rows);
    wypisz_f(p,p+rows);
    free(p);
    return 0;	
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int cmp(const void *a,const void *b) {
    return *(const int*)a-*(const int*)b;
}
int cmp1(const void *a,const void *b) {
    int suma1 = suma(*(int**)a,10);
    int suma2 = suma(*(int**)b,10);
    return (suma1 > suma2) - (suma1 < suma2);
}
int cmpb(const void *a,const void *b) {
    int suma2 = suma(*(int**)b,10);
    return *(const int*)a-suma2;
}
int main(void){
    srand((unsigned)time(0));
    //// TAB3
    int **tab_3 = malloc( 15*sizeof(int*));
    for(int i = 0; i < 15; i++)  
        tab_3[i] = malloc(10 * sizeof(int));
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 10; j++)
            tab_3[i][j]  =  rand() % 21;  
    //// TAB3
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }    
    for(int i=0;i<15;i++) {
        qsort(tab_3[i],10,sizeof(int),cmp);
    }  
    printf("NEW QSORT TAB3\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }   
    qsort(tab_3,15,sizeof(*tab_3),cmp1);
    printf("NEW QSORT SUM TAB3\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }
    int var;
    scanf("%d",&var);
    int **p = bsearch(&var,tab_3,15,sizeof(*tab_3),cmpb);
    if(p!=NULL) {
        printf("Znaleziono wartosc.\n");
        int indeks = p-tab_3;
        int w=indeks/10;
        printf("Numer wiersza %d\n",w);
        wypisz_i(tab_3[w],tab_3[w]+10);
    }
    else {
        printf("Nie znaleziono wartosci.\n");
    }
    for(int i=0;i<15;i++) {
        free(tab_3[i]);
    }
    free(tab_3);
    return 0;	
}

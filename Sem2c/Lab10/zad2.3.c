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
    return suma((int*)a,10)-suma((int*)b,10);
}
int cmpb(const void *a,const void *b) {
    int x = *(int*)a;
    int *y = (int*)b;
    int suma2 = suma(*(int**)y,10);
    return x-suma2;
}
int main(void){
    srand((unsigned)time(0));
    //// TAB333      
    int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));
    for(int i = 0; i < 15  ; i++)
        for(int j = 0; j < 10; j++)
            tab_333[i][j]  =  rand() % 21;  
    //// TAB333
    printf("TAB333\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }
    for(int i=0;i<15;i++) {
        qsort(tab_333[i],10,sizeof(int),cmp);
    }  
    printf("NEW QSORT TAB333\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }
    qsort(tab_333,15,sizeof(*tab_333),cmp1);
    printf("NEW QSORT WIERSZE TAB333\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }
    int var;
    scanf("%d",&var);
    int (*p)[] = bsearch(&var,tab_333,15,10*sizeof(int),cmpb);
    if(p!=NULL) {
        printf("Znaleziono wartosc.\n");
        int indeks = p-tab_333;
        int w=indeks/10;
        printf("Numer wiersza %d\n",w);
        wypisz_i(tab_333[w],tab_333[w]+10);
    }
    else {
        printf("Nie znaleziono wartosci.\n");
    }
    free(tab_333);
    return 0;	
}

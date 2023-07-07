#include <stdio.h>

void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}

int *find_min_wsk(int *a,int *b) {
    int *min = a;
    for(int i=0;i<(b-a);i++) {
        if(*min>*(a+i)) {
            min = a+i;
        }
    }
    return min;
}

void sort (int *tab, int *tab1) {
    for(int i=0;i<tab1-tab;i++) {
        swap(tab+i,find_min_wsk(tab+i,tab1));
    }
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int main(void){
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
    printf("Wartosc min: %d Adres: %p Indeks: %d\n",*find_min_wsk(tab_A,tab_A+22),find_min_wsk(tab_A,tab_A+22),find_min_wsk(tab_A,tab_A+22)-tab_A);
    sort(tab_A,tab_A+23);
    wypisz_i(tab_A,tab_A+23);
    int tab_B[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
    sort(tab_B,tab_B+9);
    sort(tab_B+9,tab_B+23);
    //wypisz_i(tab_B,tab_B+23);
    for(int i=0;i<23;i++) {
        printf("tab[%d] = %d    ",i,tab_B[i]);
    }
    return 0;	
}

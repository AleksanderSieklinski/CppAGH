#include <stdio.h>
#include <stdlib.h>

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
  
void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
         
void swap_tab(int *a,int *b,int n) {
    for(int i=0;i<n;i++) {
        swap(a+i,b+i);
    }
}
void swap_rows(int n,int (*TAB)[n],int x,int y) {
    swap_tab(TAB[x],TAB[y],n);
}
int main(void){
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    for(int i=0;i<4;i++) {
        wypisz_i(tab_1[i],tab_1[i]+5);
    }
    printf("\n");
    for(int i=0;i<5;i++) {
        wypisz_i(tab_22[i],tab_22[i]+2);
    }
    swap_rows(5,tab_1,0,2);
    swap_tab(tab_22[0],tab_22[1],2);
    printf("\n");
    for(int i=0;i<4;i++) {
        wypisz_i(tab_1[i],tab_1[i]+5);
    }
    printf("\n");
    for(int i=0;i<5;i++) {
        wypisz_i(tab_22[i],tab_22[i]+2);
    }
    return 0;	
}

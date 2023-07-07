#include <stdio.h>
#include <stdlib.h>

void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
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

int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
 
 int min (int *tab, int len) { 
  int ind = 0;
  for (int i = 1; i < len; i++)  
    if(tab[i] < tab[ind])
            ind = i; 
 return ind;}
 
 void sort(int x,int y,int tab[x][y]) {
    int minw,mine;
    for(int i=0;i<x;i++) {
        minw=i;
        mine=tab[i][0];
        for(int j=i;j<x;j++) {
            if(mine>tab[j][min(tab[j],y)]) {
                mine=tab[j][min(tab[j],y)];
                minw=j;
            }
        }
        swap_rows(y,tab,minw,i);
    }
    
    
 }
int main(void){
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    print_tab_all(6,tab_A,3);
    printf("\n");
    print_tab_all(3,tab_B,4);
    printf("\n");
    sort(3,6,tab_A);
    sort(4,3,tab_B);
    print_tab_all(6,tab_A,3);
    printf("\n");
    print_tab_all(3,tab_B,4);
    printf("\n");
    return 0;	
}

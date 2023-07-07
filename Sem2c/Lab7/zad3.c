#include <stdio.h>
#include <stdlib.h>
int l=6;
int min (int *tab, int len) { 
  int ind = 0;
  for (int i = 1; i < len; i++)  
    if(tab[i] < tab[ind])
            ind = i; 
 return ind;}
 
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}
   
int  icmpr(const  void *a, const  void *b){
    return  *(const  int *)a - *( const  int *)b;
}
int wcmpr(const  void *a, const  void *b) {
    return *((int*)a+min((int*)a,l))-*((int*)b+min((int*)b,l));
}

void proc_1 (int x,int y,int a[x][y]) {
    for(int i=0;i<x;i++) {
        qsort(a[i],y,sizeof(int),icmpr);
    }
}

void proc_2(int x,int y,int a[x][y]) {
    qsort(a,x,y*sizeof(int),wcmpr);
}

int main(void){
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    print_tab_all(6,tab_A,3);
    printf("\n");
    print_tab_all(3,tab_B,4);
    printf("\n");
    proc_1(3,6,tab_A);
    proc_1(4,3,tab_B);
    printf("proc_1\n");
    print_tab_all(6,tab_A,3);
    printf("\n");
    print_tab_all(3,tab_B,4);
    printf("\n");
    proc_2(3,6,tab_A);
    printf("proc_2\n");
    print_tab_all(6,tab_A,3);
    printf("\n");
    //proc_2(4,3,tab_B);
    //print_tab_all(3,tab_B,4);
    //printf("\n");
    return 0;	
}

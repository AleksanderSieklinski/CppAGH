#include <stdio.h>
#include <stdlib.h>
int l=6;
int w=48;
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}
int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
  return ss;}
int  icmpr(const  void *a, const  void *b){
    return  suma((int*)a,l)-suma((int*)b,l);
}

int wcmpr(const  void *a, const  void *b) {
    return w-suma((int*)b,l);
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;} 
int main(void){
    int x1=3,y1=6;
    //int x2=4,y2=3;
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    //int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    qsort(tab_A,x1,y1*sizeof(int),icmpr);
    //qsort(tab_B,x2,y2*sizeof(int),icmpr);
    int (*p1)[y1]=bsearch(&w,tab_A,x1,y1*sizeof(int),wcmpr);
    printf("\n");
    //int (*p2)[y2]=bsearch(&w,tab_B,x2,y2*sizeof(int),wcmpr);
    if(p1!=NULL) {
        printf("Zawartosc wiersza w tab_A o takiej sumie:\n");
        int w1= p1-tab_A;
        wypisz_i(tab_A[w1],tab_A[w1]+y1);
    }
    else {
        printf("Brak wiersza w tab_A o takiej sumie:\n");
    }   
    //if(p2!=NULL) {
    //    printf("Zawartosc wiersza w tab_B o takiej sumie:\n");
    //    int w2= p2-tab_B;
    //    wypisz_i(tab_B[w2],tab_B[w2]+y2);
    //}
    //else {
    //    printf("Brak wiersza w tab_B o takiej sumie:\n");
    //}
    return 0;	
}

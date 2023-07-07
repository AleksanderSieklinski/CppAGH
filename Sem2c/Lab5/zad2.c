#include <stdio.h>

double suma (double *tab, int len) { 
  double ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}

void swap(int* a, int* b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}

double **find_tab(double *TAB[],int x,int size[]) {
    double min = suma(TAB[0],size[0]);
    double **minadres=TAB;
    for(int i=0;i<x;i++) {
        if(min>suma(TAB[i],size[i])) {
            min=suma(TAB[i],size[i]);
            minadres = TAB+i;
        }
    }
    return minadres;
}

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}

void swap_pointer (double **TAB1,double **TAB2) {
    double *temp= *TAB1;
    *TAB1=*TAB2;
    *TAB2=temp;
}

void sort(double **TAB,int x,int *size) {
    double **min;
    for(int i=0;i<x;i++) {
        min=find_tab(TAB+i,x-i,size+i);
        swap_pointer(TAB+i,min);
        int ile=min-TAB;
        swap(size+i,size+ile);
    }
}

int main(void){
    double  T_0[ ] = {1.0,3.0, 2.0,1.5, 1.5};
    double  T_1[ ] = {1.8, 2.0, 1.2};
    double  T_2[ ] = {5.6, 1.0, 3.3, 3.3};
    double  T_3[ ] = {1.1, 2.1, -6.5, 1.7, 0.4, 1.7};
    double  T_4[ ] = {6.7, 7.8, -9.1, 0.1};
    double *TAB[5]={T_0,T_1,T_2,T_3,T_4};
    int T_size[5]={sizeof(T_0)/sizeof(double),sizeof(T_1)/sizeof(double),sizeof(T_2)/sizeof(double),sizeof(T_3)/sizeof(double),sizeof(T_4)/sizeof(double)};
    for(int i=0;i<5;i++) {
        printf("T_size[%d]=%d\n",i,T_size[i]);
    }
    
    for (int i=0; i<sizeof(TAB)/sizeof(double);i++) {
       for (int j=0;j<T_size[i];j++) {
	        printf("TAB[%d][%d] = %0.1f ",i,j,*(TAB[i]+j));
	   }
       printf ("\n");
    }	
    double **wsk = find_tab(TAB,5,T_size);
    wypisz_d(*wsk,*wsk+T_size[wsk-TAB]);
    sort(TAB,5,T_size);
    for (int i=0; i<sizeof(TAB)/sizeof(double);i++) {
       for (int j=0;j<T_size[i];j++) {
	        printf("TAB[%d][%d] = %0.1f ",i,j,*(TAB[i]+j));
	   }
       printf ("\n");
    }	
    return 0;	
}

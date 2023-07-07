#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
    
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
  
int main(void){
    srand((unsigned)time(0));
    int size;
    scanf("%d",&size);
    int *table = malloc(size*sizeof(int));
    for(int i=0;i<size;i++) {
        table[i]=rand()%11-5;
    }
    int *arg_p = malloc(sizeof(int));
    int *arg_n = malloc(sizeof(int));
    int size1=1,size2=1;
    for(int i=0;i<size;i++) {
        if(table[i]!=0 && table[i]%2!=0) {
            arg_n[size2-1]=table[i];
            size2++;
            arg_n=realloc(arg_n,size2*sizeof(int));
        }
        else if (table[i]==0 || table[i]%2==0) {
            arg_p[size1-1]=table[i];
            size1++;
            arg_p=realloc(arg_p,size1*sizeof(int));
        }
    }
    wypisz_i(table,table+size);
    wypisz_i(arg_p,arg_p+size1-1);
    wypisz_i(arg_n,arg_n+size2-1);
    free(table);
    free(arg_p);
    free(arg_n);
    return 0;	
}

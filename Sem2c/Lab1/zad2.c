#include <stdio.h>
#include <stdlib.h>
#define N 5

int zamiana(int *x,int *y){
    int c;
    c=*x;
    *x=*y;
    *y=c;
    return 0;
}

int odwroc(int *tab,int ile) {
    for(int i=0;i<ile/2+1;i++) {
        zamiana(tab+i,tab+ile-i);
    }
    return 0;
}

int wymien_tablice(int *tab1,int *tab2,int ile) {
    for(int i=0;i<ile;i++) {
        zamiana(tab1+i,tab2+i);
    }
    
    return 0;
}



int main(void){
    int x=10,y=5;
    printf("Przed zamiana: %d %d \n",x,y);
    zamiana(&x,&y);
    printf("Zamienione: %d %d\nStara tablica: ",x,y);
    int tab[N]={1,3,5,8,10};
    int tab1[N]={2,4,6,9,11};
    for(int i=0;i<N;i++) {
        printf("%d ",tab[i]);
    }
    printf("\nObrocona tablica: ");
    
    odwroc(tab,N-1);
    for(int i=0;i<N;i++) {
        printf("%d ",tab[i]);
    }
    printf("\ntab1 w tab: ");
    wymien_tablice(tab,tab1,N);
    
    
    for(int i=0;i<N;i++) {
        printf("%d ",tab[i]);
    }
    printf("\ntab w tab1: ");
    for(int i=0;i<N;i++) {
        printf("%d ",tab1[i]);
    }
    printf("\n");
    return 0;	
}

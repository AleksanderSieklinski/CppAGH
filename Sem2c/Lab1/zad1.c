#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int suma (const int *p,const int *y) {
    if (p!=y) {
        return *y+ suma(p,y+1);
    }
    else {
        return *y;
    }
}

int main(void){
    srand(time(0));
    int tab[N];
    int *p=NULL;
    for(int *i=tab;i<tab+N;i++) {
        *i=rand()%29+7;
        p=i;
        printf("p[%ld] = %d\n",p-tab,*p);
    }
    printf("\n");
    int su = suma(p,tab);
    printf("su=%d\n",su);
    return 0;	
}

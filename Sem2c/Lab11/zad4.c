#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct elastyna{
    int ile;
    int tab[];
}str[5];
int cmpr(const void*a,const void*b) {
    if((struct elastyna*)a->ile>(struct elastyna*)a->ile) {
        return 1;
    }
    if((struct elastyna*)a->ile<(struct elastyna*)a->ile) {
        return -1;
    }
    if((struct elastyna*)a->ile==(struct elastyna*)a->ile) {
        return 1;
    }
    else {
        return 0;
    }
}
struct elastyna add_numbers(struct elastyna*, struct elastyna*);
int main(void){
    srand((unsigned)time(0));
    struct elastyna *(tab[5]);
    for(int i=0;i<5;i++) {
        tab[i]=&str[i];
        tab[i]->ile=100+rand()%51;
        tab[i]->tab[0]=1+rand()%9;
        for(int j=1;j<tab[i]->ile;i++) {
            tab[i]->tab[j]=rand()%10;
        }
        qsort(tab[i]->tab,tab[i]->ile,sizeof(int),cmpr);
    }
    return 0;	
}

#include <stdio.h>

int *find(int *tab,int ile,int x) {
    if (*tab==x) {
        return tab;
    }
    ile=(ile+1)/2;
    if(ile == 0) {
        if(*tab!=x) {
        return NULL;
        }
    }
    if(*(tab+ile)==x) {
        tab=tab+ile;
        return tab;
    }
    else if (*(tab+ile)>x) {
        return find(tab,ile,x);
    }
    else {
        tab=tab+ile;
        return find(tab,ile,x);
    }
}

int main() {
int tab_A[] = {1,3,5,6,7,9, 11,13,16,22,22,22,22,25,34,35,36,37,45,46,47,47,47,55,56,58,59};
int size = sizeof(tab_A)/sizeof(int);
int *wartosc = find(tab_A,size,22);
if (wartosc==NULL) {

}
int ile=0;
for(int i=0;i<size;i++) {
    if (*wartosc==tab_A[i]) {
    ile++;
    }
}
printf("Adres wartości: %p, wartość %d,ilość wystąpień: %d\n",wartosc,*wartosc,ile);
 return 0;
}

#include <stdio.h>

int add2(int *x, int *y) {
    return *x+*y;
}
int comp2(int *x, int *y) {
    return *x-*y;
}

int add2_or_comp2 (int x,int y, int f(int*,int*)) {
    return f(&x,&y);
}

int main(int argc, const char * argv[]) {
    int x=18,y=3;
    int p = add2(&x, &y);
    int r = comp2(&x, &y);
    int q = add2_or_comp2(x,y,add2);
    int s = add2_or_comp2(x,y,comp2);
    printf("Suma %d\n",p);
    printf("Różnica %d\n",r);
    printf("Suma wyborem %d\n",q);
    printf("Różnica wyborem %d\n",s);
    return 0;
}

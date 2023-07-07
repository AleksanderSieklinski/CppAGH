#include <stdio.h>
#include <stdlib.h>
    int main () {
    int ile=0;
    int numer;
    scanf("%d",&numer);
    while (numer != 0) {
        if (numer & 1 == 1) {
        ile++;
        }
        numer >>= 1;
    }
    printf ("%d\n",ile);
    return 0;	
}
// 11=1101

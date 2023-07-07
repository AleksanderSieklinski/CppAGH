#include <stdio.h>
#include <stdlib.h>

    int main () {
    int liczbacalk;
    char liczba[9];
    liczba[8]='\0';
    do {
    scanf("%d",&liczbacalk);
    }
    while (liczbacalk>255);
    int i=0;
    do {
        if (liczbacalk & 1 == 1) {
            liczba[8-i]='1';
            }
        else {
            liczba[8-i]='0';
            }
        
        printf("%c",liczba[8-i]);
        i++;
        liczbacalk >>= 1;
        }
    while(liczbacalk>0);
    printf("\n");
    return 0;	
}
// 11 = 1011

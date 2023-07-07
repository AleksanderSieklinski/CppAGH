#include <stdio.h>
#include <stdlib.h>
    int main () {
    char a[9];
    scanf("%s",a);
    printf("%s\n",a);
    int wynik=0;
    int ile=0;
    while (ile<8) {
    wynik*=2;
    wynik += (a[ile] == '1' ? 1 : 0);
    
    ile++;
    }
    printf("%d\n",wynik);
    return 0;	
}

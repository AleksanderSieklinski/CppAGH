#include <stdio.h>
    int main () {
    
    char x;
    scanf("%c",&x);
    for(char i='A';i<=x;i++) {
    char y=x-(i-'A');
    char q=i;
    while(q>'A') {
        printf(" ");
        q--;
    }
    
    while(y>='A') {
        printf("%c",y);
        y--;
    }
    y++;
    while(y<x-(i-'A')) {
        y++;
        printf("%c",y);
    }
    printf("\n");
    }
    return 0;	
}

#include <stdio.h>
int main(){
    int ile=0;
    for(int i=-5;i<=98;i++) {
        if(i%4==0 && i%5 != 0) {
        printf ("%d " , i);
        ++ile;
        }
    }
    printf("\nIle = %d", ile);
    
    return 0;	
}

#include <stdio.h>
    int main () {
    int n;
    do {
    printf("Podaj cyfrę");
    scanf("%d",&n);
    }while (n<0 || n>9);
    
    for(int i=0;i<n+1;i++) {
    int k=n;
    int g=i;
        while(n-g<n) {
        printf(" ");
        g--;
        }
        for(int j=0;j+i<n;j++) {
            printf("%d",k);
            k--;
        }
        
        printf(" ");
        
        for(int j=0;j<n+1;j++) {
            printf("%d",k);
            k--;
            if (k<0) {
            break;
            }
        }
        
        printf("\n");
    }
    
return 0;	
}

#include <stdio.h>
    int main () {
    int min=2000;
    int max=3000;
    int suma=0;
    long long int iloczyn=1;
    for(int i=min;i<max;i++) {
        int k=i;
        if(k%2!=0 && k%113==0) {
        printf("%d ",k);
        suma+=k;
        iloczyn*=k;
        }
    }
    printf("Suma:%d , iloczyn:%ld \n",suma,iloczyn);
    
    return 0;
}

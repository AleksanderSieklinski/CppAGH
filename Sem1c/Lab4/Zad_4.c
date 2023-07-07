#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    int main () {
    time_t czas;   
    srand( (unsigned int)time(&czas) );
    
    int a;
    scanf("%d",&a);
    int tab[a];
    for(int i=0;i<a;i++) {
    tab[i]= rand()%61;
    printf("element[%d] = %d\n",i,tab[i]);
    }
    printf("Po zamianie:\n");
    int j=0;
    for(int i=0;i<a,j<a-i;i++) {
    int temp;
    j=0;
        if(tab[a-1-i]%2==0) {
        while(tab[a-2-i-j]%2==0 && j<=a-i) {
            j++;
        }
        temp = tab[a-2-i-j];
        tab[a-2-i-j]=tab[a-1-i];
        tab[a-1-i] = temp;
        }
    }
    for(int i=0;i<a;i++) {
    printf("element[%d] = %d\n",i,tab[i]);
    }
    return 0;	
}

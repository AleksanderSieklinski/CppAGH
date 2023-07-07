#include <stdio.h>
#include <stdlib.h>
    
void tab_init(int tab[][5],int w) {
    for(int i=0;i<w;i++) {
        for(int j=0;j<5;j++) {
            tab[i][j]=i;
        }
    }
    return;
}    
 
void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}  
          
int main(void){
    int w=5;
    int abc[w][5];
    tab_init(abc,w);
    printf("\n");
    for(int i=0;i<w;i++) {
        for(int j=0;j<5;j++) {
            printf("TAB[%d][%d] = %d, ",i,j,abc[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<w;i++) {
        for(int j=0;j<5;j++) {
            if(i<j) {
            swap(abc[i]+j,abc[j]+i);
            }
        }
    }
    for(int i=0;i<w;i++) {
        for(int j=0;j<5;j++) {
            printf("TAB[%d][%d] = %d, ",i,j,abc[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<w;i++) {
        for(int j=0;j<5;j++) {
            if(j==i-1) {
            printf("TAB[%d][%d] = %d, ",i,j,abc[i][j]);
            }
        }
    }
    printf("\n");
    return 0;	
}

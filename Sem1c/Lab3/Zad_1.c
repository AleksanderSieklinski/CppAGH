#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main () {
    
    time_t czas;   

    srand( (unsigned int)time(&czas) );
  
    int n;
    int h;
    int k=0;
    int j;
    int a;
    
    scanf("%d %d",&n,&h);
    
    int tab1[n];
    int tab2[h];
    
    if(n>h) {
    a=n+1;
        for(int i=0;i<n;i++) {
        tab1[i]= rand()%10;
        printf("%d",tab1[i]);
        }
        printf("\n");
        for(j=0;j<n-h;j++) {
        tab2[j]=0;
        printf("%d",tab2[j]);
        }
        
        for(int i=j;i<n;i++) {
        tab2[i]= rand()%10;
        printf("%d",tab2[i]);
        }
    }
    else {
    a=h+1;
        for(int i=0;i<h;i++) {
        tab2[i]= rand()%10;
        printf("%d",tab2[i]);
        }
        printf("\n");
        for(j=0;j<h-n;j++) {
        tab1[j]=0;
        printf("%d",tab1[j]);
        }
        
        for(int i=j;i<h;i++) {
        tab1[i]= rand()%10;
        printf("%d",tab1[i]);
        }   
    }
    
    int tab3[a];
    printf("\n");
    for(int i=a-1;i>0;i--) {
    tab3[i]=tab1[i-1]+tab2[i-1] + k;
    k=0;
        if(tab3[i]>=10) {
        tab3[i]=tab3[i]-10;
        k++;
        }
    }
    tab3[0]=k;
    for(int i=0;i<a;i++) {
        printf("%d",tab3[i]);
        }
    
    
    return 0;	
}

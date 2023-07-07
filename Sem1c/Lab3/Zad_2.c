#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    int main () {
    time_t czas;   

    srand( (unsigned int)time(&czas) );
    
    
    double tab[10];
    
    for(int i=0;i<10;i++) {
        tab[i]= rand()%(100+100+1)-100. +drand48();
        while (tab[i]>100||tab[i]<-100) {
        tab[i]= rand()%(100+100+1)-100. +drand48();
        }
        if(tab[i]<0) {
            if(tab[i]>-10) {
                printf("Element [%d] = %0.2f \n",i,tab[i]);
            }   
            else {
                printf("Element [%d] =%0.2f \n",i,tab[i]);
            }
        }
        else {
        if(tab[i]<10) {
            printf("Element [%d] =  %0.2f \n",i,tab[i]);
        }
        else {
            printf("Element [%d] = %0.2f \n",i,tab[i]);
            }
        }
    }
    printf("Elementy po zamianie:\n");
    for(int i=0;i<10/2;i++) {
    double k = tab[i];
    tab[i]=tab[9-i];
    tab[9-i]=k;}
    for(int i=0;i<10;i++) {
    printf("Element [%d] = %-5.2f \n",i,tab[i]);
    }
    
    
    return 0;	
}

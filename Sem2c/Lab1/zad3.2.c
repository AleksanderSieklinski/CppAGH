#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5
    int suma (int tab[],int n,int *max,int *min,double *srednia,double *maxod,double *minod) {
    int su=0;
    for(int i=0;i<n;i++) {
        su+=tab[i];
        printf("%d ",tab[i]);
        if(*min>tab[i]) {
        *min =tab[i];
        }
        if(*max < tab[i]) {
        *max=tab[i];
        }
    }
    printf("\n");
    *srednia = su/n;
    for(int i=0;i<n;i++) {
        if(*minod>fabs(tab[i]-*srednia)) {
        *minod = fabs(tab[i]-*srednia);
        }
        if(*maxod < fabs(tab[i]-*srednia)) {
        *maxod=fabs(tab[i]-*srednia);
        }
    }
    return su;
}
        
        
int main(void){
    int max=0,min=1000;
    double srednia,maxod=0.0,minod=1000.0;
    int t[N]={1,3,5,7,9};
    int s = suma(t,N,&max,&min,&srednia,&maxod,&minod);
    printf("Suma: %d\nWart min: %d\nWart max: %d\nWart srednia: %f\nMax od: %f\nMin od: %f\n",s,min,max,srednia,maxod,minod);
    return 0;	
}

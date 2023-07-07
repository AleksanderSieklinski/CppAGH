#include <stdio.h>
#define N 7

void wypisz_f (float *poczatek, float *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
  
   void swap(float*a, float*b){
         float temp = *a;
         *a = *b;
         *b = temp;
         return;}
  
int main(void){
    float Tab_2[7]={5.45,34.23,71.01,4.02,6.21,11.45,78.98};
    float *Tab_1[7];
    for(int i=0;i<7;i++) {
        Tab_1[i]=Tab_2+i;
    }
    float **wsk,**wsk_1;
    wsk=wsk_1=Tab_1;
    
    
    
    printf("Tab_2: ");
    wypisz_f(*wsk,*wsk+N);
    while(wsk!=wsk_1+N) {
        printf("Tab_1[%ld]= %p\n",wsk-wsk_1,*wsk);
        wsk++;
    }
    wsk--;
    
    
    
    while(wsk>wsk_1) {
        swap(*wsk_1,*wsk);
        wsk--;
        wsk_1++;
      }
    wsk-=N/2;
    wsk_1=wsk;
    printf("Tab_2: ");
    wypisz_f(*wsk,*wsk+N);
    while(wsk!=wsk_1+N) {
        printf("Tab_1[%ld]= %p\n",wsk-wsk_1,*wsk);
        wsk++;
    }
    wsk=wsk_1;
    
    
    float *temp=*(wsk+N-1);
    for(int i=0;i<N;i++) {
        if(i!=(N-1))
        *(wsk+N-1-i)=*(wsk+N-2-i);
        else {
        *(wsk+N-1-i)=temp;
        }
    }
    printf("Tab_2 przez indentyfikator Tab: ");
    for(int i=0;i<N;i++) {
        printf("%0.2f ",Tab_2[i]);
    }
    printf("\n");
    while(wsk!=wsk_1+N) {
        printf("Tab_1[%ld]= %p\n",wsk-wsk_1,*wsk);
        wsk++;
    }

    return 0;	
}

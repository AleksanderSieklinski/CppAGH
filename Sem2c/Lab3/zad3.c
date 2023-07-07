#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.1f,", *poczatek++); 
  printf ("\n");    
  return;}
  
double suma (double *tab, int len) { 
  double ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}    
  
double *find_min_wsk (double *T_F, double *T_L){
   double *min = T_F++;
  
   while (T_F < T_L){
      if(*min > *T_F) min = T_F;
      T_F++;
   }
   return min;}
   
int row_number(double abc[][4],int w) {
    int max=abc[0][0];
    int ind_max;
    for(int i=0;i<w;i++) {
        for(int j=0;j<4;j++) {
            if(max<abc[i][j]) {
                max=abc[i][j];
                ind_max=i;
            }
        }
    }
return ind_max;
}  
   
   
double *fun_find(double abc[][4],int w) {
    double *min=find_min_wsk(abc[0],abc[0]+w*4);
    return min;
}
   
int main(void){
    srand((unsigned)time(0));
    double abc[5][4];
    for(int i=0;i<5;i++) {
        for(int j=0;j<4;j++) {
            abc[i][j]=rand()%20-10 + rand()/(1.0+RAND_MAX);
        }
    }
    for(int i=0;i<5;i++) {
        wypisz_d(abc[i],abc[i]+4);
    }
    printf("\n");
    double suma_abc[5];
    for(int h=0;h<5;h++) {
        suma_abc[h]=suma(abc[h],4);
    }
    printf("Sumy wierszow: ");
    wypisz_d(suma_abc,suma_abc+5);
    double suma_all_1 = suma(abc[0],sizeof(abc)/sizeof(double));
    double suma_1_2 = suma(abc[0]+(sizeof(abc)/sizeof(double))/2,sizeof(abc)/sizeof(double)/2);
    printf("Suma_all: %f\nSuma_polowy: %f\n",suma_all_1,suma_1_2);
    int ind_max = row_number(abc,5);
    printf("Wiersz z max wart: %d -->",ind_max);
    wypisz_d(abc[ind_max],abc[ind_max]+4);
    double *MIN_WSK = fun_find(abc, 5);
    double *first = &abc[0][0];
    int w=(MIN_WSK-first)/4;
    int k=MIN_WSK-first-4*w;
    printf("Indeks[%d][%d] Min: %0.1f\n",w,k,*MIN_WSK);
    return 0;	
}

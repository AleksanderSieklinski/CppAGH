#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int cmp(const void *a,const void *b) {
    return *(const int*)a-*(const int*)b;
}
int cmp1(const void *a,const void *b) {
    return suma((int*)a,10)-suma((int*)b,10);
}
int main(void){
    srand((unsigned)time(0));
    int var=5;
    //// TAB3
    int **tab_3 = malloc( 15*sizeof(int*));
    for(int i = 0; i < 15; i++)  
        tab_3[i] = malloc(10 * sizeof(int));
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 10; j++)
            tab_3[i][j]  =  rand() % 21; 
    //// TAB33     
    
    int **tab_33 = malloc( 15 * sizeof(int*));
    tab_33[0] = malloc(10 * 15 * sizeof(int));
    for(int i = 1; i < 15; i++)  
        tab_33[i] = tab_33[i-1] + (10 * sizeof(int));
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            tab_33[i][j]  =  rand() % 21;  
            printf ("%d  %d  %d\n", i, j, tab_33[i][j]);}
            puts ("___________");
            wypisz_i(tab_33[i],tab_33[i]+10);
        }   
        puts ("__1___3______");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }   
     puts ("_____3_3_____");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_33[i],tab_33[i]+10);
    }  
      
    //// TAB333      
    int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));
    for(int i = 0; i < 15  ; i++)
        for(int j = 0; j < 10; j++)
            tab_333[i][j]  =  rand() % 21;  
            
    if(tab_3!=NULL) {
        printf("TAB3 przydzielony");
    }
    else {
        printf("TAB3 nieprzydzielony");
    }
    if(tab_33!=NULL) {
        printf("TAB33 przydzielony");
    }
    else {
        printf("TAB33 nieprzydzielony");
    }
    if(tab_333!=NULL) {
        printf("TAB333 przydzielony");
    }
    else {
        printf("TAB333 nieprzydzielony");
    }
    //// TAB3
      puts ("_____3______");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }   
     puts ("_____3_3_____");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_33[i],tab_33[i]+10);
    }  
     puts ("_____333_____");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }  
    for(int i=0;i<15;i++) {
        qsort(tab_3[i],10,sizeof(int),cmp);
    }  
    printf("NEW NEW NEW NEW NEW\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }   
    /*qsort(tab_3,15,10*sizeof(int),cmp1);
    printf("NEW NEW NEW NEW NEW\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_3[i],tab_3[i]+10);
    }*/
    //// TAB33
    printf("TAB33\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_33[i],tab_33[i]+10);
    }
    for(int i=0;i<15;i++) {
        qsort(tab_33[i],10,sizeof(int),cmp);
    }
    printf("NEW NEW NEW NEW NEW\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_33[i],tab_33[i]+10);
    } 
    //// TAB333
    printf("TAB333\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }
    for(int i=0;i<15;i++) {
        qsort(tab_333[i],10,sizeof(int),cmp);
    }  
    printf("NEW NEW NEW NEW NEW\n");
    for(int i=0;i<15;i++) {
        wypisz_i(tab_333[i],tab_333[i]+10);
    }
    
    return 0;	
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }
double (*funkcja)(double);
int compare(const void *a,const void *b) {
    return funkcja(*(double *)a)-funkcja(*(double *)b);
}
void print_fun(double f(double),char *nazwa,double *data,int ile) {
    printf("Wynik: ");
    for(int i=0;i<ile;i++) {
        printf("%s(%0.1f) = %0.4f ",nazwa,*(data+i),f(*(data+i)));
    }
    printf("\n");
    }
double (**find_max(double (**fw)(double),double x))(double) {
    double maxf = (*fw)(x);
    double (**wskaznik)(double) = NULL;
    do {
        if((*fw)(x)>maxf) {
            wskaznik = fw;
            maxf = (*fw)(x);
        }
    }
    while (*(++fw)!= NULL);
    return wskaznik;
}
void sort_arg(double f(double),double tab[],int ile) {
    funkcja=f;
    qsort(tab,ile,sizeof(double),compare);
}
int main(void){
    char* nazwy[]={"log", "pow","sin","cos"};
    double data[8] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 }; 
    double (*TAB_FUN[5])(double)={fun0,fun1,fun2,fun3,NULL};
    double (**wsk_fun)(double)=TAB_FUN;
    char **str=nazwy;
    for(int i=0;i<4;i++) {
        print_fun(wsk_fun[i],*(str+i),data,8);
    }
    double (**wsk_max)(double)=find_max(TAB_FUN,0.05);
    printf ("dla x= %.3f najwieksza wartosc wynosi %.5f dla funkcji %s\n", 0.05,(**wsk_max)(0.05), nazwy[wsk_max-TAB_FUN]);
   int ktore=2;
   sort_arg(TAB_FUN[ktore],data,8);
   printf("Funkcja --> %s tablica data : ",nazwy[ktore]);
   for(int i=0;i<sizeof(data)/sizeof(double);i++) {
    printf("%0.1f ",data[i]);
   }
   printf("\nWartosci: ");
   for(int i=0;i<sizeof(data)/sizeof(double);i++) {
    printf("%0.1f ",TAB_FUN[ktore](data[i]));
   }
   printf("\n");
    return 0;	
}

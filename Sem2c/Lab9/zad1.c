#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float *tabwd;
float  min (float *f, float *l){
	float a = *f++;
	while (f < l){
	   if (a > *f) a = *f;
	   f++;
	}
return a;
}

float  max (float *f, float *l){
	float a = *f++;
	while (f < l){
	   if (a < *f) a = *f;
	   f++;
	}
return a;
}

float  avg (float *f, float *l){
	float sum = 0.;
	int i = l-f;
	while (f < l)
    	   sum += *f++;

return sum/i;
}

float  mid (float *f, float *l){
return *(f+(l-f)/2);
}
typedef struct {
    char *nazwa;
    float (*p)(float*,float*);
}fun;
fun *fun_tab(float(**f)(float*,float*),char *nazwy[],int ile) {
    fun *funtab=malloc(ile*sizeof(fun));
    for(int i=0;i<ile;i++) {
        funtab[i].nazwa=nazwy[i];
        funtab[i].p=*f++;
    }
    return funtab;
}
void fun_prn(fun* tab, int len_tab, float (*value)[8], int row) {
    for(int i=0;i<4;i++) {
        printf("%s(%d) = %0.2f  ",tab[i].nazwa,row,tab[i].p(value[row],value[row]+8));
    }
    printf("\n");
}
int compare (const void *a,const void *b) {
    return ((fun*)a)->p(tabwd,tabwd+9) - ((fun*)b)->p(tabwd,tabwd+9);
}
int compare1 (const void *a,const void *b) {
    if(*(const double*)a-((fun*)b)->p(tabwd,tabwd+9)-0.05<0 || *(const double*)a-((fun*)b)->p(tabwd,tabwd+9)+0.05<0) {
       return -1;
    }
    if(*(const double*)a-((fun*)b)->p(tabwd,tabwd+9)-0.05>0 || *(const double*)a-((fun*)b)->p(tabwd,tabwd+9)+0.05>0) {
       return 1;
    }
       return 0;
}
void sort_fun(fun *tab,int len_tab,float (*value)[8],int row) {
    tabwd=value[row];
    qsort(tab,len_tab,sizeof(tab[0]),compare);
}
fun *find_fun (fun *tab,int len_tab,float (*value)[8],int row,double w) {
    fun *fp;
    fp=bsearch(&w,tab,len_tab,sizeof(tab[0]),compare1);
    return fp;
}
int main(void){
    char* names[]={"min", "max","avg","mid"};
    float data[4][8] = { { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 },
                             { 2.5, 3.1, 1.5, 4.2, 2.5, 3.0, 3.5, 4.2 },
                             { 1.5, 2.0, 0.5, 2.7, 2.5, 3.0, 1.5, 2.0 },
                             { 0.5, 3.0, 0.5, 2.0, 2.0, 3.0, 3.5, 1.0 }}; 
    float (*TAB_FUN[])(float*,float*) = { min, max, avg, mid}; 
    fun *wsk_fun = fun_tab(TAB_FUN, names, 4);
    for(int i=0;i<4;i++) {
        fun_prn(wsk_fun,4,data,i);
    }
    printf("\n");
    sort_fun(wsk_fun,4,data,3);
    fun_prn(wsk_fun,4,data,3);
    fun *point = find_fun (wsk_fun, 4, data, 3, 2.01);
    if(point!= NULL) {
        printf("%s(%d) = %0.2f  \n",point->nazwa,3,point->p(data[3],data[3]+8));
    }
    else {
        printf("Nie ma\n");
    }
    fun *point1 = find_fun (wsk_fun, 4, data, 3, 3.01);
    if(point1!= NULL) {
        printf("%s(%d) = %0.2f  \n",point1->nazwa,3,point1->p(data[3],data[3]+8));
    }
    else {
        printf("Nie ma\n");
    }
    free(wsk_fun);
    return 0;	
}

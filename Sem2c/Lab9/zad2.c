#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *g="i";
char *f="g";
typedef struct {
    union unia {
        int x;
        double y;
    }u1;
    char c[1];
}liczba;
void struct_prn(int x,liczba l1[x]) {
    int ile=0;
    for(int i=0;i<x;i++) {
        if(strcmp(l1[i].c,g)==0) {
            printf("%d. %d --> %s\n",ile++,l1[i].u1.x,"Int");
        }
        else {
            printf("%d. %0.2f --> %s\n",ile++,l1[i].u1.y,"Double");
        }
    }
}
int cmpi(const void *a,const void *b) {
    return *(const int*)a-*(const int*)b;
}
int cmpd(const void *a,const void *b) {
    return 10000*(*(const double*)a)-10000*(*(const double*)b);
}
int cmp(const void *a,const void *b) {
    liczba *l1 = (liczba*)a;
    liczba *l2 = (liczba*)b;
    if(strcmp(l1->c,g)==0 && strcmp (l2->c,g)==0) {
        return l1->u1.x-l2->u1.x;
    }
    else if(strcmp(l1->c,f)==0 && strcmp (l2->c,f)==0) {
        if(l1->u1.y-l2->u1.y<0) {
            return -1;
        }
        if(l1->u1.y-l2->u1.y>0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (strcmp(l1->c,f)==0 && strcmp (l2->c,g)==0) {
        return -1;
    }
    else {
        return 1;
        
    }
}
void sorcik (int x,liczba l1[x]) {
    qsort(l1,x,sizeof(liczba),cmp);
}
int main(int argc,const char *argv[]){
    srand((unsigned)time(NULL));
    liczba tab[50];
    for(int i=0;i<50;i++) {
        if(rand()%2==1) {
            tab[i].u1.x=rand()%11-5;
            strcpy(tab[i].c,g);
        }
        else {
            tab[i].u1.y=rand()%10 -5 +drand48();
            strcpy(tab[i].c,f);
        }
    }
    struct_prn(50,tab);
    sorcik(50,tab);
    struct_prn(50,tab);
    int ilei=0,iled=0;
    for(int i=0;i<50;i++) {
        if(strcmp(tab[i].c,g)==0) {
            ilei++;
        }
        else {
            iled++;
        }
    }
    void *p;
    if(strchr(argv[1],'.')==NULL) {
        int w=atoi(argv[1]);
        printf("Szukamy inta\n");
        p=bsearch(&w,tab,ilei,sizeof(liczba),cmpi);
    }
    else {
        if(atof(argv[1])==atoi(argv[1])) {
            int w=atoi(argv[1]);
            printf("Szukamy impostor inta\n");
            p=bsearch(&w,tab,ilei,sizeof(liczba),cmpi);
        }
        else {
            double w=atof(argv[1]);
            printf("Szukamy double\n");
            p=bsearch(&w,tab+ilei,iled,sizeof(liczba),cmpd);
        }
    }
    if(p!=NULL) {
        printf("Znaleziono wartosc\n");
    }
    else {
        printf("Nie znaleziono wartosci\n");
    }
    return 0;	
}

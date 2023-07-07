#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct {
    int x,y,z;
} vector;
typedef struct {
    vector v1;
    double len;
} all_vect;
double vect_len(vector v) {
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
void fill_tab (all_vect *v, int x) {
    for(int i=0;i<x;i++) {
        v[i].len=vect_len(v[i].v1);
    }
}
void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
void sort(all_vect *v,int x) {
    double min;
    int mina=0;
    for(int i=0;i<x;i++) {
        min=v[i].len;
        mina=i;
        for(int j=i;j<x;j++) {
            if(v[j].len<min) {
                mina=j;
                min=v[j].len;
            }
        }
        all_vect temp=v[i];
        v[i]=v[mina];
        v[mina]=temp;
    }
}
int main(int argc,const char *argv[]){
    srand((unsigned)time(0));
    int ile=atoi(argv[1]);
    all_vect tab_vect[ile];
    for(int i=0;i<ile;i++) {
        tab_vect[i].v1.x=rand()%5;
        tab_vect[i].v1.y=rand()%5;
        tab_vect[i].v1.z=rand()%5;
    }
    fill_tab(tab_vect,ile);
    for(int i=0;i<ile;i++) {
        printf("%d x=%d y=%d z=%d len=%f\n",i,tab_vect[i].v1.x,tab_vect[i].v1.y,tab_vect[i].v1.z,tab_vect[i].len);
    }
    sort(tab_vect,ile);
    printf("\n");
    for(int i=0;i<ile;i++) {
        printf("%d x=%d y=%d z=%d len=%f\n",i,tab_vect[i].v1.x,tab_vect[i].v1.y,tab_vect[i].v1.z,tab_vect[i].len);
    }
    return 0;	
}

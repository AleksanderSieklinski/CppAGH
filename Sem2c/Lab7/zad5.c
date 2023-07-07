#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f1(double x) {
    return -x*x+3*x+11;
}
int zero(double f(double), double a, double b, double* m_z, double eps) {
    if(f(a)*f(b)<0) {
        *m_z=a;
        while(fabs(a-b)>eps) {
            *m_z=(a+b)/2;
            if(f(*m_z)*f(b)<=0) {
                a=*m_z;
            }
            else {
                b=*m_z;
            }
        }
        return 1;
    }
    return 0;
}
int main(void){
    double mz1,mz2,mz3;
    int a,b,c;
    a=zero(sin,-1,1,&mz1,0.0000001);
    b=zero(f1,0,8,&mz2,0.0000001);
    c=zero(f1,-1,1,&mz3,0.0000001);
    if(a==1) {
        printf("MZ (-1,1) sin: %0.2f\n",mz1);
    }
    else {
        printf("sin (-1,1) brak MZ\n");
    }
    if(b==1) {
        printf("MZ (0,8) f1: %0.2f\n",mz2);
    }
    else {
        printf("f1 (0,8) brak MZ\n");
    }
    if(c==1) {
        printf("MZ (-1,1) f1: %0.2f\n",mz3);
    }
    else {
        printf("f1 (-1,1) brak MZ\n");
    }
    
    return 0;	
}

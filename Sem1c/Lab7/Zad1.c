#include <stdio.h>

int cf (int n,int *l,int *g,int *c) {
    static int tab[20];
    tab[0]=0;
    tab[1]=1;
    printf("%d",*g);
    for(int i=0;i<*g;i++) {
        printf(".");
    }
    if (n>1) {
        printf("Obliczam f(%d)=f(%d)+f(%d),l=%d\n",n,n-1,n-2);
            tab[*c]=tab[*c-1]+tab[*c-2];
            *l+=1;
            *g+=1;
            *c+=1;
            cf(n-1,l,g,c);
    }
    else {
        for(int i=0;i<n;i++) {
            printf("Zwracam f(%d), l= %d\n",n,*l);
            *l++;
        }
    }
    int a=tab[n];
    *g-=1;
    return a;
}


int main(int argc, const char * argv[]) {
    int n;
    int l1 =1;
    int *l=&l1;
    int x=0;
    int *g=&x;
    int cx=2;
    int *c=&cx;
    printf("Wynik dla wartości wczytanej ");
    scanf("%d",&n);
    printf("rFibonacci (%d) = %d\n",n,cf(n,l,g,c));
    return 0;
}

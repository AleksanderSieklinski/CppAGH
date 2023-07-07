#include <stdio.h>
#include <stdlib.h>
void write_binar(unsigned n, char *wsk) {
    int tab[n];
    for(int i=0;i<n;i++) {
        tab[i]=1;
    }
    for(int i=0;i<32;i++) {
        if(n & tab[i] == 1) {
            *(wsk+31-i) = '1';
            n>>=1;
        }
        else {
            *(wsk+31-i) = '0';
            n>>=1;
        }
    }
}

unsigned bits(unsigned x,unsigned n) {

    x>>=32-n;
    x<<=32-n;
    return x;
}


int main(int argc, const char *argv[]){
    unsigned result, number, bit_num ;
    number = atoi(argv[1]);
    bit_num = atoi(argv[2]);
    char number_string[33];
    number_string[32]='\0';
    write_binar(number,number_string);
    printf("liczba wczytana %u : %s\n", number,number_string);      
    result = bits (number, bit_num);
    write_binar(result,number_string);
    printf("%u najstarszych bitow %s\n",bit_num,number_string);
    
return 0;	
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, const char * argv[]) {
    time_t czas;
    srand((unsigned int) time (&czas));
    
    char losuj_wyraz[10];
    for(int i=0;i<10;i++) {
        losuj_wyraz[i]='a' + (rand()%26);
    }
    
    char losowa = 'a' + (rand()%26);
    char *p = strchr(losuj_wyraz,losowa);
    
    if(p!= NULL) {
    printf("Litera występuje pod indeksem: %d\n",p-losuj_wyraz);
    
    int ile=0;
    for(char *i=losuj_wyraz ; strchr(i,losowa)!= NULL ; i++) {
    ile++;
    i=strchr(i,losowa);
    }
    printf("Ilość wystąpień: %d\n",ile);
    }
    else {
    printf("Litera nie występuje\n");
    }
    return 0;
}

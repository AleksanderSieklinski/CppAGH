#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){
int ile;
    if(strlen(argv[1])>strlen(argv[2])) {
    ile = strlen(argv[1]);
    }
    else {
    ile = strlen(argv[2]);
    }
    char nap_1[ile],nap_2[ile],nap_x[ile];
    
    strcpy(nap_1,argv[1]);
    strcpy(nap_2,argv[2]);
    
    printf ("A -->  napis_1 = %s napis_2 = %s\n", nap_1, nap_2);
    
    strcpy(nap_x,nap_1);
    strcpy(nap_1,nap_2);
    strcpy(nap_2,nap_x);

    printf ("B -->  napis_1 = %s napis_2 =  %s\n", nap_1, nap_2);
    
    
    return 0;	
}

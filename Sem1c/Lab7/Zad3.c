#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    int dl1 = strlen(argv[1]);
    int dl2 = strlen(argv[2]);
    char nap1[dl1];
    char nap2[dl2];
    
    strcpy (nap1,argv[1]);
    strcpy (nap2,argv[2]);
    printf ("A -->  napis_1 = %s napis_2 = %s\n", nap1, nap2);
    
    char temp[dl1];
    strcpy(temp,nap1);
    strcpy(nap1,nap2);
    strcpy(nap2,temp);
    printf ("B -->  napis_1 = %s napis_2 = %s\n", nap1, nap2);
    return 0;
}

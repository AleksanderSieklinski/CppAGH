#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    int ile = argc-1;
    char *Stringi[ile]=argv[1];
    int ilex=0;
    for(int i=0;i<ile;i++) {
        for (int j=0;j<i;j++) {
            if(strcmp(argv[i+1],argv[j+1])!=0) {
                ilex=1;
            }
        }
        printf("%s\n",argv[i+1]);
        if (ilex == 0) {
            Stringi[i]=argv[i+1];
        }
    }
    for(int i=0;i<ile;i++) {
        strcat(Stringi[0],Stringi[i]);
    }
 return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
    int ile = argc-1;
    char Stringi[ile];
    Stringi[ile-1]='\0';
    int ilepowt=0;
    int ilesuma=0;
    for(int i=0;i<ile;i++) {
    ilepowt=0;
        for(int j=0;j<i;j++) {
            if (strcmp(argv[i+1],argv[j+1])==0) {
            ilepowt++;
            ilesuma++;
            }
            
        }
        printf("%d %s\n",i,argv[i+1]);
        if(ilepowt==0) {
            Stringi[i]='1';
        }
        else {
        Stringi[i]='0';
        }
    }
    int rozmiar=0;
    for(int i=0;i<ile;i++) {
        if(Stringi[i]=='1') {
            rozmiar+=strlen(argv[i+1]);
        }
    }
    
    char final[rozmiar];
    final[0] = '\0';
    for(int i=0;i<ile;i++) {
        if(Stringi[i]=='1') {
            strcat(final,argv[i+1]);
        }
    }
    printf("%s\n",final);
return 0;	
}

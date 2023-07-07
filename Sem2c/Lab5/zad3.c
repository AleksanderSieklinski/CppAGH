#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
    char korektor[] = "  . , : ;";
    char *schowek;
    char *p=argv[1];
    int iles=0,ilel=0;
    while((p=strstr(p,argv[2]))!=NULL) {
        ilel++;
        p++;
    }
    schowek=strtok(argv[1],korektor);
    while(schowek!=NULL) {
        printf("%s\n",schowek);
        if(strcmp(argv[2],schowek)==0) {
            iles++;
        }
        schowek=strtok(NULL,korektor);
    }
    printf("Wyraz pojawi sie %d razy\nLancuch pojawi sie %d razy\n",iles,ilel);
    return 0;	
}

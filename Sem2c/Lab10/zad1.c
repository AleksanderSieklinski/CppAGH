#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
char *va_cat(int ile,...) {
    char *string=malloc(1);
    size_t size=0;
    va_list argptr;
    va_start(argptr,ile);
    char *l;
    for(int i=0;i<ile;i++) {
        l=va_arg(argptr,char*);
        size+=strlen(l);
        string=realloc(string,size);
        strcat(string,l);
    }
    va_end(argptr);
    return string;
    
}
int main(int argc,char *argv[]){
    char *s = va_cat(argc-1,argv[1],argv[2],argv[3],argv[4]);
    printf("%s\n",s);
    return 0;	
}

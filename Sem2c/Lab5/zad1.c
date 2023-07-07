#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *swapc(char *TEXT1, char *TEXT2, char *TEXT3) {
    char *TEXT4=malloc(strlen(TEXT1));
    char *p1,*p2;
    int size = strlen(TEXT4);
    strcpy(TEXT4,TEXT1);
    while((p2=strstr(TEXT4,TEXT2))!=NULL) {
        p1=strstr(p2+strlen(TEXT2),TEXT2);
        strncat(TEXT4,TEXT3,strlen(p2));
        strncat(TEXT4,strlen(p2)+strlen(TEXT3),p1);
        //memmove(strstr(TEXT4,TEXT2),strstr(TEXT4,TEXT2)+strlen(TEXT2),strlen(strstr(TEXT4,TEXT2))+strlen(TEXT2));
    }
    return TEXT4;
}



int main(void){
    char *T_1 = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char *T_2 = "sie";
    char *T_3 = "Alicja";
    printf("Łańcuch T_1: %s\n",T_1);
    printf("Łańcuch T_2 - do usunięcia: %s\n",T_2);
    printf("Łańcuch T_3 - do wstawienia: %s\n",T_3);
    char *T_4 = swapc(T_1,T_2,T_3);
    printf("Łańcuch T_4 - wynik działania funkcji: %s\n",T_4);
    free (T_4);
    return 0;	
}

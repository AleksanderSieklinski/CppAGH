#include <stdio.h>
#include <string.h>
int main() {
    char a[] = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char b[] = "sie";
    printf("Łańcuch wejściowy: %s\n",a);
    printf("Łańcuch do usunięcia: %s\n",b);
    char *x = a;
    int size = strlen(b);
    while ((strstr(a,b))!= NULL) {
        strcpy(strstr(a,b),strstr(a,b)+strlen(b));
    }
    printf("Łańcuch wyjściowy: %s\n",a);
 return 0;
}

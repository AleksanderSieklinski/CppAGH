#include <stdio.h>
#include <stdlib.h>
void file_copy (FILE *af, FILE *bf) {
    char c;
    while (c=getc(af)!=EOF) {
        putc(c,bf);
    }
    rewind(bf);
    rewind(af);
}
int file_cmp (char *, char *);
void file_cat (char *, char *);
void file_copy_t (FILE *af, FILE *bf) {
    char c;
    FILE *cf = fopen("tmp.txt","wb+");
    if (!cf) {
        printf("erooror");
        exit(-1);
    }
    while (c=getc(af)!=EOF) {
        putc(c,cf);
    }
    rewind(cf);
    rewind(af);
    while(c=getc(bf)!=EOF) {
        putc(c,af);
    }
    rewind(bf);
    while (c=getc(cf) != EOF) {
        putc(c,bf);
    }
    rewind(cf);
    fclose(cf);
}
int main(void){
    double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};
    double test1[] = {0.9,3.1,3.0,9.9,8.8,6.6,5.5,4.4,3.3,2.2,1.1};		
    FILE *ptr_bin ;
    FILE *ptr_bin1 ; //wskaznik do pliku binarnego
    int i;	
    size_t test_len = sizeof(test)/sizeof(*test);
    size_t test_len1 = sizeof(test1)/sizeof(*test1);
    
    ptr_bin = fopen ("b_1","wb");	
    fwrite(test, 1, sizeof(test), ptr_bin);	
    fclose(ptr_bin);
   
    ptr_bin1 = fopen ("b_2","wb");	
    fwrite(test1, 1, sizeof(test1), ptr_bin1);	
    fclose(ptr_bin1);
    
    ptr_bin = fopen ("b_1","rb");
    ptr_bin1 = fopen ("b_2","ab");
    
    
    file_copy(ptr_bin,ptr_bin1);
    
    fclose(ptr_bin);
    fclose(ptr_bin1);


    ptr_bin = fopen ("b_1","rb");	
    double *tab_1 = malloc (sizeof(test));
    fread(tab_1, 1, sizeof(test), ptr_bin);	
    fclose(ptr_bin);
 
    puts("_______bin__________________") ;
    for (i = 0; i < test_len; i++)
    printf ( " tab_1[%d]  %.1f  \n",i, tab_1[i]);
    printf ("\n"); 
    
    
    ptr_bin1 = fopen ("b_2","rb");	
    double *tab_2 = malloc (sizeof(test1));
    fread(tab_2, 1, sizeof(test1), ptr_bin1);	
    fclose(ptr_bin1);
 
    puts("_______bin__________________") ;
    for (i = 0; i < test_len1; i++)
    printf ( " tab_2[%d]  %.1f  \n",i, tab_2[i]);
    printf ("\n"); 
    return 0;	
}

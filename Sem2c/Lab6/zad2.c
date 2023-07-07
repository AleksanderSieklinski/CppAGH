#include <stdio.h>
#include <stdlib.h>
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

int (*trans_tab_all (int x,int y,int tab[x][y]))[] {
    int (*trans)[x]=malloc(x*y*sizeof(int));
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            trans[j][i]=tab[i][j];
        }
    }
    return trans;
}

int main(void){
    int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,6,1,44},{31,21,1,7},{1,15,13,1}};    
    int (*trans_A)[2] = trans_tab_all (2,3,tab_A);//wywolanie dla tablicy tab_A
    int (*trans_B)[3] = trans_tab_all (3,4,tab_B);//wywolanie dla tablicy tab_B
    printf("Tab_A\n");  
    print_tab_all (3,tab_A,2); //wypisanie tablicy tab_A
    printf("Trans_A\n");
    print_tab_all (2,trans_A,3); //wypisanie tablicy trans_A
    printf("Tab_B\n");
    print_tab_all (4,tab_B,3); //wypisanie tablicy tab_B
    printf("Trans_B\n");
    print_tab_all (3,trans_B,4); //wypisanie tablicy trans_B   
    free(trans_A);
    free(trans_B);
    return 0;	
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand(time(0));
    int rows1 = rand()%5+3;
    int columns1 = rand()%5+3;
    int rows2 = rand()%5+3;
    int columns2 = rand()%5+3;
    int **array_1 = calloc(rows1,sizeof(int*));
    int **array_2 = calloc(rows2,sizeof(int*));
    for(int i=0;i<rows1;i++) {
        array_1[i] = (int*)calloc(columns1,sizeof(int));
        for(int j=0;j<columns1;j++) {
            array_1[i][j]=rand()%15+1;
        }
    }
    int *tab=calloc(rows2*columns2,sizeof(int));
    for(int i=0;i<rows2;i++) {
        array_2[i]=tab+columns2*i;
    }
    for(int i=0;i<rows2;i++) {
        for(int j=0;j<columns2;j++) {
            array_2[i][j]=rand()%15+1;
        }
    }
    for(int i=0;i<rows1;i++) {
        for(int j=0;j<columns1;j++) {
            printf("TAB[%d][%d] = %d ",i,j,array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<rows2;i++) {
        for(int j=0;j<columns2;j++) {
            printf("TAB[%d][%d] = %d ",i,j,array_2[i][j]);
        }
        printf("\n");
    }
    int rows_new = rand()%5+3;
    for(int i=rows_new;i<rows1;i++) {
        free(array_1[i]);
    }
    array_1=realloc(array_1,rows_new*sizeof(int*));
    array_2=realloc(array_2,rows_new*sizeof(int*));
    if(rows_new>rows1) {
        for(int i=rows1;i<rows_new;i++) {
            array_1[i] = (int*)calloc(columns1,sizeof(int));
            for(int j=0;j<columns1;j++) {
                array_1[i][j]=rand()%15-15;
            }
        }
    }
    tab=realloc(tab,rows_new*columns2*sizeof(int));
    for(int i=0;i<rows2;i++) {
        array_2[i]=tab+columns2*i;
    }
    if(rows_new>rows2) {
        for(int i=rows2;i<rows_new;i++) {
            array_2[i]=tab+columns2*i;
        }
        for(int i=rows2;i<rows_new;i++) {
            for(int j=0;j<columns2;j++) {
                array_2[i][j]=rand()%15-15;
            }
        }
    }
    printf("ROWS_NEW\n");
    for(int i=0;i<rows_new;i++) {
        for(int j=0;j<columns1;j++) {
            printf("TAB[%d][%d] = %d ",i,j,array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<rows_new;i++) {
        for(int j=0;j<columns2;j++) {
            printf("TAB[%d][%d] = %d ",i,j,array_2[i][j]);
        }
        printf("\n");
    }
    free(tab);
    free(array_1);
    free(array_2);
    return 0;	
}

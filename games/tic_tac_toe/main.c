#include <stdio.h>
#include <time.h>
#define N 3

void matrixRand(char matrix[N][N]){
    int i,j;

    for(i = 0;i < N; i++){
        for(j = 0; j < N; j++){
            matrix[i][j] = '?';
        }
    }
}

void setRole(char matrix[N][N], char role){
    int i, j;
    
    printf("\n----- %c ROLE -----", role); 
    printf("\nSet LINE position: "); scanf("%d", &i); 
    printf("\nSet COLUMN position: "); scanf("%d", &j);

    i -= 1; j -= 1; 

    matrix[i][j] = role;


}

void writeMatrix(char matrix[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        printf("|");
        for(j = 0; j < N; j++){
            
            printf("%c", matrix[i][j]);
            if(j != (N-1)){
                printf("    ");
            }
        }
        printf("|"); printf("\n\n");
    }
}

int main(){

    int i;

    char matrix[N][N];

    matrixRand(matrix); writeMatrix(matrix);

    for(i = 0; /*a decidir*/; i++){

        setRole(matrix,'X');

        writeMatrix(matrix);

        setRole(matrix,'O');

        writeMatrix(matrix);
    }

    return 0;
}
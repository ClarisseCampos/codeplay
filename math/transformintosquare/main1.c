#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define I 3
#define J 4

void generateMatrix(int matrix[I][J]){
    srand(time(NULL));
    int i,j;

    for(i = 0;i < I; i++){
        for(j = 0;j < J; j++){
            matrix[i][j] = rand() % 100;
        }
    }
}

void writeMatrix(int matrix[I][J]){
    int i,j;

    for(i = 0;i < I;i++){
        for(j = 0;j < J; j++){
            printf("% 5d", matrix[i][j]);

        }
        printf("\n");
    }
}

void squaredMatrix(int matrix[I][J]){
    int maior, i = I, j = J;

    maior = j;
    if(I > J){
        maior = i;
    }
    int newMatrix[maior][maior];

    // o x da questao
    
    writeMatrix(newMatrix);
    
}
int main(){
    int myMatrix[I][J];

    generateMatrix(myMatrix);
    printf("\nOriginal matrix:\n");
    writeMatrix(myMatrix);

    // process

    printf("\nModified matrix:\n");
    squaredMatrix(myMatrix);

    return 0;
}
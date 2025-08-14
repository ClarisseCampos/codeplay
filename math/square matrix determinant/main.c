#include <stdio.h>

void inputProtocol(int matrix[2][2]){
    int i,j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("\nSet a number for N(%d,%d): ", i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int determinant(int matrix[2][2]){
    int principal  = matrix[0][0] * matrix[1][1], secundaria = matrix[0][1] * matrix[1][0];
    
    return principal - secundaria;
}

void writingProtocol(int matrix[2][2]){
    int i, j;
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n\n");
    }
}

int main() {

    int tabela[2][2] = {}; inputProtocol(tabela);
    
    printf("\nMatrix\n");writingProtocol(tabela);
    printf("Determinante: %d\n", determinant(tabela));

    return 0;
}
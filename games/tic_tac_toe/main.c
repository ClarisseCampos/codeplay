#include <stdio.h>
#include <time.h>
#define N 3

void matrixRand(char matrix[N][N]){
   int j;
   // primeira linha
   for(j = 0;j < N;j++){
        matrix[0][j] = 65 + j;
   }
    //segunda linha
   for(j = 3;j < N+3;j++){
        matrix[1][j-3] = 65 + j;
   }
    //terceira linha
   for(j = 6;j < N+6;j++){
        matrix[2][j-6] = 65 + j;
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

int gameOverCheckOut(char matrix[N][N], char role){
    int i;
    // checar linhas e colunas
    for(i = 0;i < N; i++){
        if((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] == role) || (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] == role)){
            return 0;
        }
    }
    // checar diagonais
    if((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] == role) || (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[2][0] == role)){
        return 0;
    }

    return 1;
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

    char matrix[N][N];

    matrixRand(matrix); writeMatrix(matrix);

    for(;;){
        setRole(matrix,'X');
        writeMatrix(matrix);

        if(!gameOverCheckOut(matrix,'X')){
            printf("\nGAME OVER! X won.");
            break;
        }

        setRole(matrix,'O');
        writeMatrix(matrix);

        if(!gameOverCheckOut(matrix,'O')){
            printf("\nGAME OVER! O won.");
            break;
        }
    }

    return 0;
}
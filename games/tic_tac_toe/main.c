#include <stdio.h>
#include <stdlib.h>
#define N 3

void generateMatrix(char m[N][N]) {
    int i, j;
    char ch = '1';
	for(i = 0; i < N; i++) {
		for(j = 0; j < N ; j++) {
			m[i][j] = ch;
            ch++;
		}
	}
}
void printMatrix(char m[N][N]) {
    int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N ; j++) {
			printf("%c\t", m[i][j]);
		}
		printf("\n\n");
	}
}

int play(char c, char m[N][N]){
    int i, j;
    char cordinates;
    printf("\n-> %c role: ", c); scanf(" %c", &cordinates);
    printf("\n");

    for(i = 0;i < N; i++){
        for(j = 0;j < N; j++){
            if(m[i][j] == cordinates){
                m[i][j] = c;break;
            }
        }
    }
    m[i][j] = c;

    if(m[0][0] == m[1][1] && m[1][1] == m[2][2]){
        return 1;
    }else if(m[0][2] == m[1][1] && m[1][1] == m[2][0]){
        return 1;
    }else{
        for(i = 0;i < N; i++){
            if(m[i][0] == m[i][1] && m[i][1] == m[i][2]){
                return 1;
            }
        }
        for(j = 0;j < N; j++){
            if(m[0][j] == m[1][j] && m[1][j] == m[2][j]){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
	char m[N][N];
	int i, verify;
	
	printf("\n====# TIC TAC TOE #====\n");
    generateMatrix(m);printMatrix(m);
	
	for(i = 0;i < 9; i++){
	    if(i % 2 == 0){
	        verify = play('X', m);
	        printMatrix(m);
            if(verify == 1){
                printf("\nGAMER OVER! Usuario X ganhou\n");break;
            }
	    }else{
	        verify = play('O', m);
            printMatrix(m);
            if(verify == 1){
                printf("\nGAMER OVER! Usuario O ganhou\n"); break;
            }
	    }
    }
    // nao ta rolando
    printf("\nPress Enter no quit\n");
    getchar(); getchar();

	return 0;
}
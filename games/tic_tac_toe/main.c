#include <stdio.h>
#include "tic_tac_toe.h"

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
                printf("\nGAMER OVER! Player X is the winner\n");break;
            }
	    }else{
	        verify = play('O', m);
            printMatrix(m);
            if(verify == 1){
                printf("\nGAMER OVER! Player O is the winner\n"); break;
            }
	    }
    }
    if(i == 8){
        printf("\nDRAW!\n");
    }

    printf("\nPress Enter no quit\n");
    getchar(); getchar();

	return 0;
}
#include <stdio.h>

int qbits(int num){
    int qtd = 0;
    while(num > 0){
        num >>= 1;
        qtd++;
    }
    return qtd;
}
 void convert(int num, int *bin){
    int i, qtd = qbits(num);
    for(i = qtd-1; num != 0; i--){
        bin[i] = num & 1;
        num >>= 1;
    }
 }

int main(){
    int num, qtd;
    printf("\nSet an integer: "); scanf("%d", &num); 

    qtd = qbits(num);

    int bin[qtd];

    convert(num, bin);

    for(int i = 0;i < qtd; i++){
        printf("%d", bin[i]);
    }

    return 0;
}
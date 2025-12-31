#include <stdio.h>
/** @brief Calcula a soma dos quadrados dos números naturais de 1 até n.
 *
 * Esta função utiliza a fórmula matemática fechada:
 *
 *      S = n(n + 1)(2n + 1) / 6
 *
 * que representa a soma:
 *
 *      1² + 2² + 3² + ... + n²
 *
 * O uso da fórmula evita laços de repetição, resultando em tempo de execução
 * constante, independentemente do valor de n.*/

typedef unsigned long long int ull;

ull sumOfNaturalSquares(int n){

    return (ull)n*(n+1)*(2*n + 1)/6;
}
int main(){
    int n = 0;
    for(;;){
        printf("\nDigite o valor de n: "); scanf("%d", &n);
        if(n >= 0){
            break;
        }else{
            printf("\nValor invalido, o numero deve ser natural");
        }
    }
    printf("\nSoma dos quadrados de 1-%d: %llu\n",n, sumOfNaturalSquares(n));

    return 0;
}
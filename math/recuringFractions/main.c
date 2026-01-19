#include <stdio.h>
void periodicFraction(float num, int * a, int * b){
    int parte_inteira, periodo, counter = 0;
    float aux;
    // extrair o periodo
    // quantos digitos em o periodo?
    parte_inteira = num;
    aux = num - (float)parte_inteira;
    
    while(aux != ((int)aux)){
        counter++;
        aux = aux * 10;
    }


    printf("\nParte inteira: %d, numeros de periodo: %d", parte_inteira, counter);

    // caso de decimal periodico simples

}
int main(){
    float num;
    int a,b;

    printf("\nSet the float number (only repeated part) ");
    scanf("%f", &num);
    periodicFraction(num, &a,&b);

    return 0;
}
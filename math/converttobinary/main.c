#include <stdio.h>
#include <math.h>

int main()
{
    int num, rest, counter = 0, numBinary = 0;
    
    printf("\nSet a number: "); scanf("%d", &num);
    
    int i = 0, numSave = num;
    do{
        rest = num % 2;
        num /= 2;
        counter++;
        
        i++;
    }while (num != 0);
    
    num = numSave;
    
    for(i = 0; i < counter; i++){
        rest = num % 2;
        num /= 2;
        
        numBinary += rest*pow(10,i);
    }
    
    printf("\nBinary representation of %d: %d", numSave, numBinary);
    
    return 0;
}
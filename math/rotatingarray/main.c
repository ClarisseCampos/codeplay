// main.c
#include <stdio.h>
#include "functions.h"

int main()
{
    int myarray[SIZE] = {};
    int timesToTurn = 1;

    randomFilling(myarray);
    printf("\nOriginal array:");
    writeArray(myarray);
    
    printf("\nTurned left:");
    turnLeft(myarray, timesToTurn);
    writeArray(myarray);

    return 0;
}

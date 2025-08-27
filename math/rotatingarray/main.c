// main.c
#include <stdio.h>
#include "functions.h"

//to run: ./output/programa

int main()
{
    int original_array[SIZE] = {}, newArray[SIZE] = {}, timesToTurn;

    for(;;){
        printf("\nTimes to turn: ");scanf("%d", &timesToTurn);
        if(timesToTurn == 0){
            break;
        }
        randomFilling(original_array);
        printf("\nOriginal array:");
        writeArray(original_array);

        for(int i = 0;i < SIZE; i++){
            newArray[i] = original_array[i];
        }
        
        printf("\nTurned left:");
        turnLeft(newArray, timesToTurn);
        writeArray(newArray);

        for(int i = 0;i < SIZE; i++){
            newArray[i] = original_array[i];
        }

        printf("\nTurned Right:");
        turnRight(newArray, timesToTurn);
        writeArray(newArray);
    }




    return 0;
}

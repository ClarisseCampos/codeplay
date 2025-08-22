#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void writeArray(int x_array[SIZE]){
    int i;
    printf("\n[");
    for(i = 0; i < SIZE; i++){
        printf(" %d ", x_array[i]);
    }
    printf("]");
}

void randomFilling(int x_array[SIZE]){
    srand(time(NULL));
    int i;
    for(i = 0; i < SIZE; i++){
        x_array[i] = (rand() % (UPPER_BOUND - LOWER_BOUND)) + LOWER_BOUND;
    }
}

void turnLeft(int x_array[SIZE], int times){
    int i, j, temp, temp0;
    for(j = 0; j < times; j++){
        temp0 = x_array[0];
        for(i = 0; i < SIZE; i++){
            temp = x_array[i];
            x_array[i] = x_array[i + 1];
            x_array[i + 1] = temp;
        }
        x_array[SIZE - 1] = temp0;        
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void IO_arr(int arr[N], int flag){
    int i;
    if(flag){
        for(i = 0;i < N;i++){
            arr[i] = (rand() % 90) + 10; 
        }
    }else{
        for(i = 0; i < N; i++){
            printf("%d ", arr[i]);
        }
    }
}
void bubblesort(int arr[N]){
    int i,j;

    for(i = 0;i < N-1; i++){
        for(j = 0; j < (N-1-i); j++){
            if(arr[j] > arr[j+1]){
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int arr[N];

    IO_arr(arr, 1);

    printf("\nBubble Sort in C");
    
    printf("\nNormal: "); IO_arr(arr, 0);
    bubblesort(arr);
    printf("\nSorted: "); IO_arr(arr, 0);

    return 0;
}
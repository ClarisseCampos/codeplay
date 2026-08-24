#include <stdio.h>

void writeArray(int * arr, int n){
    for(int i = 0;i <n;i++){
        printf("%d, ", arr[i]);
    }
    
}
void insertionSort(int * arr, int n){
    int i, j, aux;
    
    for(i = 1 ;i < n; i++)
    {
        aux = arr[i]; j = i-1;
        
        for(j = i-1; arr[j] > aux; j--)
        {
            if(j <= 0){
                break;
            }
            arr[j+1] = arr[j];
        }
        arr[j+1] = aux;
    }
        
}

int main(){
    int arr[]= {1,6,7,4,2,9,8,5,3};
    int n = sizeof(arr)/sizeof(int);
    
    insertionSort(arr,n);
    printf("\nLista ordenada: ");
    writeArray(arr, n);

    return 0;
}
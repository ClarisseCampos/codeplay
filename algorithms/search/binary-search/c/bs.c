#include <stdio.h>

int binarySearch(int arraySize, int *v, int target){
    int low = 0, high = arraySize-1;
    int mid, guess;

    while(low <= high){
        mid= (low + high)/2;
        guess = v[mid];

        if(guess == target){
            return mid;
        }
        else if(guess > target){
            high = mid - 1;

        }else{
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    int arraySize, target;
    int v[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    arraySize = sizeof(v)/sizeof(int);

    printf("\nTarget: "); scanf("%d", &target);

    int index = binarySearch(arraySize,v,target);

    index == -1? printf("\nNone\n"): printf("\nIndex on array: %d\n", index);


    return 0;
}
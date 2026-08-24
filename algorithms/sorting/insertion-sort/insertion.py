def insertionSort(arr):
    n = len(arr)

    for i in range(1,n):
        aux = arr[i]
        j = i-1
        while j >= 0 and arr[j] > aux:
            arr[j+1] = arr[j]
            j-=1
            
        arr[j+1] = aux


arr = [1,6,7,4,2,9,8,5,3]

insertionSort(arr)

print('Lista original: {}'.format(arr))

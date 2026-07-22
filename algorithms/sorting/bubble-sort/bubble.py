import random

def bubblesort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

size = 10
arr = random.sample(range(10,90),size)
     
print('Bubble Sort in Python')
print(f'Original {arr}')
bubblesort(arr)
print(f'Sorted {arr}')
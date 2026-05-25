def binarySearch(v, target):
    low = 0
    high = len(v)-1

    while low <= high:
        mid = (low + high)//2
        guess = v[mid]
        if guess == target:
            return mid
        elif guess > target:
            high = mid - 1
        else:
            low = mid + 1

    return None


v = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

target = int(input('Target: ')) # casting 'cause input() returns a str

print(binarySearch(v, target))
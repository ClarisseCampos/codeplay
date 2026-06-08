function binarySearch(size, array, target){
    let mid, guess
    high = size -1
    low = 0

    while(high >= low){
        mid = Math.floor((high + low) / 2) // rounds to an integer
        guess = array[mid]

        if(guess == target){
            return mid;
        }
        if(guess > target){
            high = mid-1
        }else{
            low = mid +1
        }
    }
    return null
}

target = 5
array = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

id = binarySearch(array.length, array, target)

if(id == null){
    console.log("None")
}else{
    console.log(id)
}
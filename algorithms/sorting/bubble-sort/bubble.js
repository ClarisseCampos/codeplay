const size = 10
let arr = [];

function input_array(arr){
    for(let i = 0;i < size; i++){
        let num = Math.floor(Math.random() * 90) + 10;
        arr.push(num)
    }
}

function bubblesort(arr){
    let i,j
    for(i = 0;i < size-1;i++){
        for(j = 0;j < (size-1-i);j++){
            if(arr[j] > arr[j+1]){
                [arr[j], arr[j+1]] = [arr[j+1], arr[j]]
            }
        }
    }
}

input_array(arr)
console.log(`Bubble Sort em Javascript\nOriginal : ${arr}`)
bubblesort(arr)
console.log(`Ordenado : ${arr}`)
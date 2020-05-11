// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');


function fulfillsReq(A, B, C, J, D){
    // console.log("D", D);
    for(let i = 0; i < A.length; i++){
        let a = A[i];
        let b = B[i];
        // console.log(a, b);
        // console.log("->", D[a-1], D[b]);
        if(D[b] == D[a - 1]){
            return false;
        }
    }
    return true;
}

function solution(A, B, C) {
    let low = 0;
    let high = C.length - 1;
    
    let answer = -1;
    
    while(low <= high){
        let mid = Math.floor((low + high) / 2);
        
        // console.log(low, mid, high);
        
        let D = new Array(2 * C.length + 1).fill(0);
        
        for(let i = 0; i <= mid; i++){
            D[ C[i] ] = 1;
        }
        for(let i = 1; i < D.length; i++){
            D[i] = D[i - 1] + D[i];
        }
        
        if(fulfillsReq(A,B,C,mid, D)){
            high = mid - 1;
            answer = high + 2;
        }
        else{
            low = mid + 1;
        }
    }
    
    return answer;
    
}
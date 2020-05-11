// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function verifyAllCompliant(max, blocks, A){
    let sum = A[0];
    let blocksCount = 0;
    
    for(let i = 1; i < A.length; i++){
        let el = A[i];
        
        // console.log("i", i,"sum", sum, "el",el, "blockcount", blocksCount);
        
        if(sum + el > max){
            sum = el;
            blocksCount++;
        }
        else{
            sum += el;
        }
    }
    
    
    
    if(sum > max){
        return false;
    }
    else{
        blocksCount++;
    }
    
    // console.log("-blockcount", blocksCount);
    
    return (blocksCount <= blocks) ;
}

function solution(K, M, A) {
    let low = Math.max(...A);
    let high = A.reduce( (total, num) => {return total + num;});
    
    while( low <= high ){
        let mid = Math.floor((low + high) / 2);
        
        // console.log("***", "low",low,"mid/max", mid,"high", high, "blocks", K,"***");
        
        if(verifyAllCompliant(mid, K, A)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    
    return low;
}
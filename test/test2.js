



function merge(arrLeft, arrRight){
	let arrSorted = [];

	console.log(arrLeft, arrRight);

	while(arrLeft.length && arrRight.length){
		if(arrLeft[0] > arrRight[0]){
			arrSorted.push( arrRight.shift() );
		}
		else{
			arrSorted.push( arrLeft.shift() );
		}
	}

	while(arrLeft.length){
		arrSorted.push(arrLeft.shift());
	}

	while(arrRight.length){
		arrSorted.push(arrRight.shift());
	}

	return arrSorted;
}

function mergesort(arr){
	if(arr.length <= 1){
		return arr;
	}

	let begin = 0;
	let end = arr.length;
	let mid = Math.ceil( (begin + end) / 2 );

	console.log(begin, mid, end);

	let arrLeft = mergesort(arr.slice(begin, mid));
	let arrRight = mergesort(arr.slice(mid, end));

	return merge(arrLeft, arrRight);
}


function swaps(arr){

	console.log(arr);

	arr = mergesort(arr);

	console.log(arr);
}

let arr = [3,5,2,1,4];
swaps(arr);
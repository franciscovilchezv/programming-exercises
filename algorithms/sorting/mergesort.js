
function merge(leftArr, rightArr){

	let leftIndex = 0;
	let rightIndex = 0;

	let sortedArray = [];

	while ( leftArr.length && rightArr.length ) {
		if( leftArr[0] < rightArr[0] ){
			sortedArray.push( leftArr.shift() );
		}
		else{
			sortedArray.push( rightArr.shift() );
		}
	}

	while( leftArr.length ){
		sortedArray.push( leftArr.shift() );
	}

	while( rightArr.length ){
		sortedArray.push( rightArr.shift() );
	}

	return sortedArray;
};

function mergeSort(arr){
	if (arr.length <= 1){
		return arr;
	}

	let middle = Math.floor(arr.length / 2);

	let left = mergeSort( arr.slice(0, middle) );
	// console.log("left", left);

	let right = mergeSort( arr.slice(middle) );
	// console.log("right", right);

	return merge( left, right );
};

let inputArr = [2,1,5,3,4];

console.log("Input array:", inputArr);

console.log("result:", mergeSort(inputArr));
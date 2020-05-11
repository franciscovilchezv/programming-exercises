function binaryPosRecursive(arr, i, j, item){
	if (i > j)	return i;

	let pos = Math.floor((j + i) / 2);

	if(item == arr[pos]){
		return pos;
	}
	else if ( item > arr[pos] ) {
		return binaryPosRecursive(arr, pos + 1, j, item);
	}
	else{
		return binaryPosRecursive(arr, i, pos - 1, item);	
	}
};

function binaryPosIterative(arr, item){
	let i = 0;
	let j = arr.length - 1;

	while(i < j){
		let pos = Math.floor(( j + i ) / 2);

		if(item == arr[pos]){
			return pos;
		}
		else if ( item > arr[pos] ) {
			i = pos + 1;
		}
		else {
			j = pos - 1;
		}
	}
	return (item > arr[i])? i + 1: i ;
}

let arr = [4];
let item = 5;
let pos = binaryPosRecursive(arr, 0, arr.length -1, item);

console.log("binary pos for:", item , " is", pos );

pos = binaryPosIterative(arr, item);

console.log("binary pos for:", item , " is", pos );

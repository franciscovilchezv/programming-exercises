function binaryPos(arr, i, j, item){
	let pos = Math.floor((j - i) / 2);

	if (i > j){
		return -1;
	}

	if(item == arr[pos]){
		return pos;
	}
	else if ( item > arr[pos] ) {
		return binaryPos(arr, pos + 1, j, item);
	}
	else{
		return binaryPos(arr, i, pos - 1, item);	
	}
};

let arr = [1,2,3];
let item = 2;
let pos = binaryPos(arr, 0, arr.length -1, item);

console.log("binary pos for:", item , " is", pos );

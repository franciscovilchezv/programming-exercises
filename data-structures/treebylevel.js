
let input = [5, 4, 3, null, 2, null ,1];

function Tree(val){
	this.val = val;
	this.left = null;
	this.right = null;
}

// class Tree {
// 	constructor(val){
// 		this.val = val;
// 		this.left = this.right = null;
// 	}
// }

function treeByLevel(input, i){
	let root = new Tree(input[i]);

	if(input[2 * i + 1]){
		root.left = treeByLevel(input, 2 * i + 1);	
	}

	if(input[2 * i + 2]){
		root.right = treeByLevel(input, 2 * i + 2);	
	}

	return root;
}

function main(input){
	let root = treeByLevel(input, 0);

	console.log(root);
}

main(input);
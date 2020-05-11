class TreeNode {
	constructor(value){
		this.value = value;
		this.left = this.right = null;
	}

	insert(value){
		if(value < this.value){
			if(this.left == null){
				this.left = new TreeNode(value);
			}
			else{
				this.left.insert(value);
			}
		}
		else {
			if(this.right == null){
				this.right = new TreeNode(value);
			}
			else{
				this.right.insert(value);
			}
		}
	}

	printInOrder(){
		if(this.left != null){
			this.left.printInOrder();
		}

		console.log(this.value);

		if(this.right != null){
			this.right.printInOrder();
		}
	}

	printLevel(n){
		if(n == 1){
			console.log(this.value);
		}
		else{
			if(this.left != null){
				this.left.printLevel(n - 1);
			}
			if(this.right != null){
				this.right.printLevel(n - 1);
			}
		}
	}
}

class Tree {
	constructor(){
		this.root = null;
	}

	insert(value){
		if(this.root == null){
			this.root = new TreeNode(value);
		}
		else{
			this.root.insert(value);
		}
	}

	printInOrder(){
		console.log("printInOrder()");
		if(this.root != null){
			this.root.printInOrder();
		}
	}

	printLevel(n){
		console.log("printLevel()");
		if(this.root != null){
			this.root.printLevel(n);
		}
	}
}


function main(input){
	let tree = new Tree();

	console.log(input);

	for(let i = 0; i < input.length; i++){
		let value = input[i];

		tree.insert(value);
	}

	console.log(tree);


	tree.printInOrder();

	tree.printLevel(3);

}


let input = [3,5,2,4,1];
main(input);
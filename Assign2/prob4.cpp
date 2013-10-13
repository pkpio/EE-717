/***********************************************************************

***********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//Define a node which supports binary tree
struct node{
	int key;
	node *lChild;
	node *rChild;
	bool isDeleted;
	int height;
};

//AVLTree variables
node *root = NULL;

void printPreOrder(node *n){
	if(n != NULL){
		cout<<n->key<<" ";
		printPreOrder(n->lChild);
		printPreOrder(n->rChild);
	}
}

void printPostOrder(node *n){
	if(n != NULL){
		printPostOrder(n->lChild);
		printPostOrder(n->rChild);
		cout<<n->key<<" ";
	}
}

void printInOrder(node *n){
	if(n != NULL){
		printInOrder(n->lChild);
		cout<<n->key<<" ";
		printInOrder(n->rChild);
	}
}

void printTree(){
	if (root != NULL){
		cout<<endl<<endl<<"The current SplayTree is: "<<endl;

		cout<<"The Pre Order traversal is: "<<endl;
		printPreOrder(root);

		cout<<endl<<"The Post Order traversal is: "<<endl;
		printPostOrder(root);
		
		cout<<endl<<"The In Order traversal is: "<<endl;
		printInOrder(root);
	} else{
		cout<<"Tree is empty"<<endl;
	}
 }

int height(node *tree){
	int lHeight, rHeight;

	if(tree == NULL)
		return 0;

	if(tree->lChild == NULL)
		lHeight = 0;
	else
		lHeight = 1 + tree->lChild->height;

	if(tree->rChild == NULL)
		rHeight = 0;
	else
		rHeight = 1 + tree->rChild->height;

	if(lHeight < rHeight)
		return rHeight;
	else
		return lHeight;
}

int balanceFactor(node *tree){
	int lHeight, rHeight;

	if(tree == NULL)
		return 0;

	if(tree->lChild == NULL)
		lHeight = 0;
	else
		lHeight = 1 + tree->lChild->height;

	if(tree->rChild == NULL)
		rHeight = 0;
	else
		rHeight = 1 + tree->rChild->height;

	return(lHeight - rHeight);
}

node * rotatLeft(node *tree){
	node *temp;
	temp = tree->rChild;
	tree->rChild = temp->lChild;
	temp->lChild = tree;
	tree->height = height(tree);
	temp->height = height(temp);
	return(temp);
}

node * rotatRight(node *tree){
	node *temp;
	temp = tree->lChild;
	tree->lChild = temp->rChild;
	temp->rChild = tree;
	tree->height = height(tree);
	temp->height = height(temp);
	return(temp);
}

node * LL(node *tree){
	tree = rotatRight(tree);
	return(tree);
}

node * RR(node *tree){
	tree = rotatLeft(tree);
	return(tree);
}

node * LR(node *tree){
	tree->lChild = rotatLeft(tree->lChild);
	tree = rotatRight(tree);
	return(tree);
}

node * RL(node *tree){
	tree->rChild = rotatRight(tree->rChild);
	tree = rotatLeft(tree);
	return(tree);
}

node * Insert(int key, node *tree){
	//Creating a new node hold this key
	node *temp = new node;
	temp->key = key;
	temp->lChild = NULL;
	temp->rChild = NULL;
	temp->isDeleted = false;

	//Root node empty. Here tree = root
	if(tree == NULL){
		tree = temp;
	} else if (key < tree->key){
		tree->lChild = Insert(key, tree->lChild);

		//Imbalance found
		if(balanceFactor(tree) == 2){

			//Case Left Left - no zigzag
			if(key < tree->lChild->key)
				tree = LL(tree);
			//Case Left Right - zigzag
			else
				tree = LR(tree);
		}

	} else{
		tree->rChild = Insert(key, tree->rChild);

		//Imbalance found
		if(balanceFactor(tree) == -2){

			//Case Right Right - no zigzag
			if(key < tree->rChild->key)
				tree = RR(tree);
			//Case Right Left - zigzag
			else
				tree = RL(tree);

		}

	}

	tree->height = height(tree);
	return tree;
}

void insertTree(int key){
	root = Insert(key, root);
}

bool search(int key, node *tree){
 	bool result = 0;

 	if(tree != NULL){
	 	if(key < tree->key)
	 		result = search(key, tree->lChild);
	 	else if(key > tree->key)
	 		result = search(key, tree->rChild);
	 	else{
	 		if(!tree->isDeleted)
	 			result = 1;
	 		else
	 			result = 0;
	 	}

	 } else{
	 	result = 0;
	 }

 	return result;
 }

 void searchTree(int key){
 	bool result = search(key, root);
 	if(result)
 		cout<<endl<<"Found !"<<endl;
 	else
 		cout<<endl<<"Not found !"<<endl;
 }

bool lazyDelete(int key, node *tree){
 	bool result = 0;

 	if(tree != NULL){
 		if(key < tree->key){
 			result = lazyDelete(key, tree->lChild);
 		}
 		else if(key > tree->key){
 			result = lazyDelete(key, tree->rChild);
		}
 		//This is node to be deleted
 		else{
 			tree->isDeleted = true;
 			result = 1;
 		}
 	}

 	return result;
 }

void deleteTree(int key){
	bool result = lazyDelete(key, root);
 	if(result)
 		cout<<endl<<"Found and deleted !"<<endl;
 	else
 		cout<<endl<<"Not found to delete !"<<endl;
}


/************************	Main program	****************************/
int main(){
	insertTree(1);
	insertTree(2);
	insertTree(3);
	insertTree(5);
	insertTree(6);

	printTree();
	
	char waitForUserAction;
	cin>>waitForUserAction;
}
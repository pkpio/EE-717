/*********************************************************
Binary search tree
Each node in the heap is a doubly linked.
It has pointers to left, right childs and parent
**********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//Define a node which supports binary tree
struct node{
	int key;
	node *parent;
	node *lChild;
	node *rChild;
};

//Heap variables
node *root = NULL;


/**********************		BST operations		*********************/
node * Insert(int key, node *tree){
	//Creating a new node hold this key
	node *temp = new node;
	temp->key = key;
	temp->lChild = NULL;
	temp->rChild = NULL;

	//Root node empty. Here tree = root
	if(tree == NULL){
		tree = temp;
	} else if (key < tree->key){
		tree->lChild = Insert(key, tree->lChild);
	} else{
		tree->rChild = Insert(key, tree->rChild);
	}

	return tree;
}

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

void printBST(){
	if (root != NULL){
		cout<<"The current BST is: "<<endl;

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


 /******************************** Main program ********************************/

int main(){
    //First insert needs root
	root = Insert(10, root);
	Insert(9, root);
	Insert(8, root);
	Insert(11, root);
	Insert(13, root);
	Insert(12, root);
	Insert(15, root);
	Insert(16, root);

	printBST();

	int c;
	cin>>c;
}

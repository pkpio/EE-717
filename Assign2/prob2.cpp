/*****************************************************************************************************************************
Author:		Praveen Kumar Pendyala
Created:	17th Oct.,2013
github:		https://github.com/praveendath92/EE-717/

NOTE:
The below code is written by aforementioned author independently and any reseblence to other code(s) is pure coincidence or 
the code might have been referred to this. The below code, as developed through various fixes, can be found on github.
*****************************************************************************************************************************/

/*
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
This is special case of a 2-3 tree with level of the leaf node being same ignored.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
#include <iostream>
#include <cmath>
using namespace std;

struct node{
	node *left;
	node *middle;
	node *right;
	int key1;
	int key2;
	bool key1isDel;
	bool key2isDel;
};

node *root = NULL;

void printPreOrder(node *n){
	if(n != NULL){

		if(!n->key1isDel && !n->key2isDel)
			cout<<"("<<n->key1<<","<<n->key2<<")";
		else if(n->key1isDel && !n->key2isDel)
			cout<<"("<<n->key2<<")";
		else if(!n->key1isDel && n->key2isDel)
			cout<<"("<<n->key1<<")";
		else
			cout<<"";

		printPreOrder(n->left);
		printPreOrder(n->middle);
		printPreOrder(n->right);
	}
}

void printTree(){
	if (root != NULL){
		cout<<endl<<endl<<"The current 2-3 Tree is: "<<endl;
		cout<<"The Pre Order traversal is: "<<endl;
		printPreOrder(root);		
	} else{
		cout<<"Tree is empty"<<endl;
	}
 }

node *Insert(int key, node *tree){

	//Reached leaf node
	if(tree == NULL){
		//Creating a new node to hold this key
		node *temp = new node;
		temp->left = NULL;
		temp->middle = NULL;
		temp->right = NULL;
		temp->key1 = key;
		temp->key2 = 0;
		temp->key1isDel = 0;
		temp->key2isDel = 0;
		//root is NULL case
		if(tree == root)
			root = temp;
		else
			tree = temp;
	}
	//key < key1 => Insert in left sub-tree
	else if (key < tree->key1){
		//There is no Key2 for that node. Insert this as key1 and make earlier key1 as key2
		if(tree->key2 == 0){
			tree->key2 = tree->key1;
			tree->key1 = key;
		}
		//Node has both keys. Continue to it's children
		else{
			tree->left = Insert(key, tree->left);
		}
	}
	//key >= key1 => There are further sub conditions. Dealt inside this else block
	else{
		//There is no Key2 for that node. Insert this as key2
		if(tree->key2 == 0){
			tree->key2 = key;
		} else if(key <= tree->key2){
			tree->middle = Insert(key, tree->middle);
		} else{
			tree->right = Insert(key, tree->right);
		}
	}

	return tree;
}

bool deleteNode(int key, node *tree){
	//Reached leaf node
	if(tree == NULL){
		if(tree == root)
			cout<<"Tree is empty !"<<endl;
		return 0;
	}
	
	int i = 0;
	if(key == tree->key1){
		tree->key1isDel = 1;
		return 1;
	} else if(key == tree->key2){
		tree->key2isDel = 1;
		return 1;
	} else if(key < tree->key1){
		return (deleteNode(key, tree->left));
	}
	else if((tree->key2 != 0) && (key <= tree->key2))
		return (deleteNode(key, tree->middle));
	else 
		return (deleteNode(key, tree->right));
}

void deleteTree(int key){
	if(deleteNode(key, root))
		cout<<"Found and deleted !"<<endl;
	else
		cout<<"Not found to delete !"<<endl;
}

void insertTree(int key){
	Insert(key, root);
}

int main(){
	//Initialization
	cout<<"Initializing 2-3 tree with numbers 1-32. In that order";
	for(int i=1; i<33; i++){
		insertTree(i);
		cout<<endl<<"Inserted key: "<<i<<endl;
	}
	cout<<endl<<"Initialization complete !"<<endl;
	printTree();

	//Deleting operations on {15 -- 8}
	cout<<endl<<endl<<"Performing delete operations for keys 15 - 8. In that order"<<endl;
	for(int i=15; i>7; i--){
		cout<<endl<<"Deleting key: "<<i<<endl;
		deleteTree(i);
	}
	cout<<endl<<"Batch delete operation complete !"<<endl;
	printTree();

	//Inserting keys {33-36}
	cout<<"Inserting into tree, keys with numbers 33-36. In that order";
	for(int i=33; i<37; i++){
		insertTree(i);
		cout<<endl<<"Inserted key: "<<i<<endl;
	}
	cout<<endl<<"Batch insert operation complete !"<<endl;
	printTree();

	cout<<endl<<endl<<"This is special case of a 2-3 tree with level of the leaf node being same ignored."<<endl;


	int i;
	cin>>i;
}

/*****************************************************************************************************************************
Author:		Praveen Kumar Pendyala
Created:	13th Oct.,2013
github:		https://github.com/praveendath92/EE-717/

NOTE:
The below code is written by aforementioned author independently and any reseblence to other code(s) is pure coincidence or 
the code might have been referred to this. The below code, as developed through various fixes, can be found on github.
*****************************************************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define delSize 5 //# of deletions after which garbage collection takes place

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
int delCount = 0;
int deletedNodes[delSize];

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
		cout<<endl<<endl<<"The current AVLTree is: "<<endl;

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

/*
           K3
          /  \                          K2
         A   k2                        /  \
            /  \          ==>         K3   K1
           B   k1                    /  \  / \
              /  \                  A   B C   D
             C    D 


*/
node * rotatLeft(node *k3){
	node *k2 = k3->rChild;
	k3->rChild = k2->lChild;
	k2->lChild = k3;
	k3->height = height(k3);
	k2->height = height(k2);
	return(k2);
}

/*
           K3
          /  \                          K2
         k2   D                        /  \
        /  \              ==>         K1   K3
       k1   C                        /  \  / \
      /  \                          A   B C  D
     A    B 


*/
node * rotatRight(node *k3){
	node *k2;
	k2 = k3->lChild;
	k3->lChild = k2->rChild;
	k2->rChild = k3;
	k3->height = height(k3);
	k2->height = height(k2);
	return(k2);
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
			if(key > tree->rChild->key)
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

 node * norDelete(node *tree, int key){
 	if(tree != NULL){
 		if(key < tree->key){
 			tree->lChild = norDelete(tree->lChild, key);

 			//AVL balancing
 			if(balanceFactor(tree) == -2){
 				if(balanceFactor(tree->rChild) <= 0)
 					tree = RR(tree);
 				else
 					tree = RL(tree);
 			}

 		} else if(key > tree->key){
 			tree->rChild = norDelete(tree->rChild, key);

 			//AVL balancing
 			if(balanceFactor(tree) == 2){
 				if(balanceFactor(tree->lChild) >= 0)
 					tree = LL(tree);
 				else
 					tree = LR(tree);
 			}

 		} else{
 			if(tree->rChild != NULL){
 				node *temp = tree->rChild;
 				while(temp->lChild != NULL)
 					temp = temp->lChild;
 				tree->key = temp->key;
 				tree->rChild = norDelete(tree->rChild, temp->key);

 				//AVL balancing
 				if(balanceFactor(tree) == 2){
 					if(balanceFactor(tree->lChild) >= 0)
 						tree = LL(tree);
 					else
 						tree = LR(tree);
 				}

 			} else{
 				return(tree->lChild);
 			}
 		}
 	}else{
 		return(NULL);
 	}

 	tree->height = height(tree);
 	return(tree);

 }

 void delDeleted(node *tree){
 	for(int i=0; i<=delCount; i++){
 		norDelete(root, deletedNodes[i]);
 		deletedNodes[i] = 0; //Not required. Just for my clarity
 	}
 	delCount = 0;
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
 			deletedNodes[delCount] = key;
 			delCount++;
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

	//Garbage collection
	if(delCount == 5){
		delDeleted(root);
		cout<<"Garbage collected !"<<endl;
	}
}


/************************	Main program	****************************/
int main(){
	//Initialization - with numbers from 1-20
	cout<<"Initializing tree with numbers 1-20";
	for(int i=20; i>=1; i--){
		insertTree(i);
		cout<<endl<<"Inserted key: "<<i<<endl;
	}
	cout<<endl<<"Initialization complete !"<<endl;
	printTree();

	//Deleting operations on 3, 4, 8, 9
	cout<<endl<<endl<<"Performing delete operations"<<endl;
	cout<<endl<<"Deleting 3..."<<endl;
	deleteTree(3);
	cout<<endl<<"Deleting 4..."<<endl;
	deleteTree(4);
	cout<<endl<<"Deleting 8..."<<endl;
	deleteTree(8);
	cout<<endl<<"Deleting 9..."<<endl;
	deleteTree(9);
	printTree();

	//Insering values 21, 22, 8
	insertTree(21);
	cout<<endl<<endl<<"Inserted key: 21"<<endl;
	insertTree(22);
	cout<<endl<<"Inserted key: 22"<<endl;
	insertTree(8);
	cout<<endl<<"Inserted key: 8"<<endl;
	printTree();

	//Deleting operation on 10, 12, 14
	cout<<endl<<endl<<"Performing delete operations"<<endl;
	cout<<endl<<"Deleting 10..."<<endl;
	deleteTree(10);
	cout<<endl<<"Deleting 12..."<<endl;
	deleteTree(12);
	cout<<endl<<"Deleting 14..."<<endl;
	deleteTree(14);
	printTree();

	//Inserting values 23, 24
	insertTree(23);
	cout<<endl<<endl<<"Inserted key: 23"<<endl;
	insertTree(24);
	cout<<endl<<"Inserted key: 24"<<endl;
	printTree();

	//Deleting operation on 24, 8, 23
	cout<<endl<<endl<<"Performing delete operations"<<endl;
	cout<<endl<<"Deleting 24..."<<endl;
	deleteTree(24);
	cout<<endl<<"Deleting 8..."<<endl;
	deleteTree(8);
	cout<<endl<<"Deleting 23..."<<endl;
	deleteTree(23);
	printTree();

	//Inserting values 24, 25
	insertTree(24);
	cout<<endl<<endl<<"Inserted key: 24"<<endl;
	insertTree(25);
	cout<<endl<<"Inserted key: 25"<<endl;
	printTree();
	
	char waitForUserAction;
	cin>>waitForUserAction;
}
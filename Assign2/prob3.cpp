/******************************************************************************************************************************************
Author:		Praveen Kumar Pendyala
Created:	11th Oct.,2013
github:		https://github.com/praveendath92/EE-717/

NOTE:
The below code is written by aforementioned author independently and any reseblence to other code(s) is pure coincidence or 
the code might have been referred to this. The below code, as developed through various fixes, can be found on github.


Binary search tree
Each node in the heap is a doubly linked.
It has pointers to left, right childs and parent
*******************************************************************************************************************************************/

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

//SplayTree variables
node *root = NULL;
node *curSplay = NULL;


/**********************		BST operations		*********************/
void twoStepSplayOp(node *splayNode){
	node *splayP = splayNode->parent;
	node *splayGP = splayP->parent;

	//splay parent is left child of splays' grand parent
	if(splayGP->lChild == splayP){


		/* Case 1

		        gp                   s
		       /  \                 / \
		      p   d     ==>        a  p
		     / \                     / \
		    s   c                   b   gp		
		   / \                         / \
		  a   b                       c   d

		*/
		if(splayP->lChild == splayNode){
			node *temp = splayP->rChild;

			//Interchanging gpp with splayNode
			//Case: splayGP is not root
			if(splayGP->parent != NULL){			
				if(splayGP->parent->lChild == splayGP)
					splayGP->parent->lChild = splayNode;
				else if(splayGP->parent->rChild == splayGP)
					splayGP->parent->rChild = splayNode;

				//Setting new splay parents
				splayNode->parent = splayGP->parent;
			}
			//Case: splayGP is root
			else{
				//Setting parents
				splayNode->parent = NULL;
				root = splayNode;
			}

			//Setting others parents
			splayP->parent = splayNode;
			splayGP->parent = splayP;

			splayP->rChild = splayGP;
			splayGP->lChild = temp;

			//Splay's rChild change
			temp = splayNode->rChild;
			splayNode->rChild = splayP;
			splayP->lChild = temp;

			//Set parents for new children
			if(splayGP->lChild != NULL)
				splayGP->lChild->parent = splayGP;
			if(splayP->lChild != NULL)
				splayP->lChild->parent = splayP;

		}
		

		/* Case 2

	        	gp                   s
		       /  \                /   \
		      p   d     ==>       p     gp
		     / \                 / \   / \
		    a   s               a   b c   d		
		       / \
		      b   c

		*/
		else if(splayP->rChild == splayNode){
			node *temp = splayNode->rChild;

			//Interchanging gpp with splayNode
			//Case: splayGP is not root
			if(splayGP->parent != NULL){			
				if(splayGP->parent->lChild == splayGP)
					splayGP->parent->lChild = splayNode;
				else if(splayGP->parent->rChild == splayGP)
					splayGP->parent->rChild = splayNode;

				//Setting new splay parents
				splayNode->parent = splayGP->parent;
			}
			//Case: splayGP is root
			else{
				//Setting parents
				splayNode->parent = NULL;
				root = splayNode;
			}

			//Setting others parents
			splayP->parent = splayNode;
			splayGP->parent = splayNode;

			//Splay's lChild as GP and rChild as splayP
			splayP->rChild = splayNode->lChild;
			splayNode->lChild = splayP;
			splayNode->rChild = splayGP;
			splayGP->lChild = temp;

			//Set parents for new children
			if(splayGP->lChild != NULL)
				splayGP->lChild->parent = splayGP;
			if(splayP->rChild != NULL)
				splayP->rChild->parent = splayP;
		}
	}



	//splay parent is right child of splays' grand parent
	else if(splayGP->rChild == splayP){
		

		/*Mirror to Case 1

		        gp                   s
		       /  \                 / \
		      p   d     ==>        a  p
		     / \                    /  \
		    s   c                  b    gp		
		   / \                         / \
		  a   b                       c   d


		*/
		if(splayP->rChild == splayNode){
			node *temp = splayP->lChild;

			//Interchanging gpp with splayNode
			//Case: splayGP is not root
			if(splayGP->parent != NULL){			
				if(splayGP->parent->lChild == splayGP)
					splayGP->parent->lChild = splayNode;
				else if(splayGP->parent->rChild == splayGP)
					splayGP->parent->rChild = splayNode;

				//Setting new splay parents
				splayNode->parent = splayGP->parent;
			}
			//Case: splayGP is root
			else{
				//Setting parents
				splayNode->parent = NULL;
				root = splayNode;
			}

			//Setting others parents
			splayP->parent = splayNode;
			splayGP->parent = splayP;

			splayP->lChild = splayGP;
			splayGP->rChild = temp;

			//Splay's rChild change
			temp = splayNode->lChild;
			splayNode->lChild = splayP;
			splayP->rChild = temp;

			//Set parents for new children
			if(splayGP->rChild != NULL)
				splayGP->rChild->parent = splayGP;
			if(splayP->rChild != NULL)
				splayP->rChild->parent = splayP;
		}

		
		/*Mirror to Case 2

	         	gp                   s
		       /  \                /   \
		      p   d     ==>       p     gp
		     / \                 / \   / \
		    a   s               a   b c   d		
		       / \
		      b   c	

		*/
		else if(splayP->lChild == splayNode){
			node *temp = splayNode->lChild;

			//Interchanging gpp with splayNode
			//Case: splayGP is not root
			if(splayGP->parent != NULL){			
				if(splayGP->parent->lChild == splayGP)
					splayGP->parent->lChild = splayNode;
				else if(splayGP->parent->rChild == splayGP)
					splayGP->parent->rChild = splayNode;

				//Setting new splay parents
				splayNode->parent = splayGP->parent;
			}
			//Case: splayGP is root
			else{
				//Setting parents
				splayNode->parent = NULL;
				root = splayNode;
			}

			//Setting others parent
			splayP->parent = splayNode;
			splayGP->parent = splayNode;

			//Splay's lChild as GP and rChild as splayP
			splayP->lChild = splayNode->rChild;
			splayNode->rChild = splayP;
			splayNode->lChild = splayGP;
			splayGP->rChild = temp;

			//Set parents for new children
			if(splayGP->rChild != NULL)
				splayGP->rChild->parent = splayGP;
			if(splayP->lChild != NULL)
				splayP->lChild->parent = splayP;

		}
	}
}

void oneStepSplayOp(node *splayNode){
	node *splayP = splayNode->parent;

	/*Case 1

     	p                  s
       / \                / \
      s   c     ==>      a  p
     / \                   / \
    a   b                 b   c
	*/
	if(splayP->lChild == splayNode){
		//NOTE : splay will be the root node after this operation
		//Setting parents
		splayNode->parent = NULL;
		splayP->parent = splayNode;

		node *temp = splayNode->rChild;
		splayNode->rChild = splayP;
		splayP->lChild = temp;

		//Setting other parents
		if(temp != NULL)
			temp->parent = splayP;

		root = splayNode;
	}

	/*Case 2

     	p                  s
       / \                / \
      c   s     ==>      p   a
         / \            / \
        b   a          c   b
	*/
     else if(splayP->rChild == splayNode){
     	//NOTE : splay will be the root node after this operation
		//Setting parents
		splayNode->parent = NULL;
		splayP->parent = splayNode;

		node *temp = splayNode->lChild;
		splayNode->lChild = splayP;
		splayP->rChild = temp;

		//Setting other parents
		if(temp != NULL)
			temp->parent = splayP;

		root = splayNode;
     }

}

void splayOp(node *splayNode){
	node *splayP = splayNode->parent;
	if(splayP != NULL){
		node *splayGP = splayP->parent;

		//splayNode at level >2
		if(splayGP != NULL){
			//Keep doing splay operation as long as there is a grand parent
			//NOTE: In the while loop we are checking P instead of GP because 
			//		we will get a NULL pointer exception for GP checking.
			//		Ex.: Consider while looping we got splayNode->parent = NULL
			//		Then trying to access splayNode->parent->parent throws nullptr exception		
			while(splayNode->parent != NULL){
				//Still in level >2
				if(splayNode->parent->parent != NULL)
					twoStepSplayOp(splayNode);
				//splayNode at level 2
				else{
					oneStepSplayOp(splayNode);
					break;
				}
			}				
		}

		//splayNode at level 2
		else{
			oneStepSplayOp(splayNode);
		}

	}else{
		//splay already root. Nothing to be done.
	}
}

node * Insert(int key, node *tree, node *treeP){
	//Creating a new node hold this key
	node *temp = new node;
	temp->key = key;
	temp->lChild = NULL;
	temp->rChild = NULL;
	temp->parent = NULL;

	//Root node empty. Here tree = root
	if(tree == NULL){
		tree = temp;
		tree->parent = treeP;
		curSplay = temp;
	} else if (key < tree->key){
		tree->lChild = Insert(key, tree->lChild, tree);
	} else{
		tree->rChild = Insert(key, tree->rChild, tree);
	}

	return tree;
}

void insertTree(int key){
	root = Insert(key, root, NULL);
	splayOp(curSplay);
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

 bool search(int key, node *tree, node *treeP){
 	bool result = 0;

 	if(tree != NULL){
	 	if(key < tree->key)
	 		result = search(key, tree->lChild, tree);
	 	else if(key > tree->key)
	 		result = search(key, tree->rChild, tree);
	 	else{
	 		result = 1;
	 		curSplay = tree;
	 	}

	 } else{
	 	result = 0;
	 	curSplay = treeP;
	 }

 	return result;
 }

 void searchTree(int key){
 	bool result = search(key, root, NULL);
 	splayOp(curSplay);

 	if(result)
 		cout<<endl<<"Found !"<<endl;
 	else
 		cout<<endl<<"Not found !"<<endl;
 }

 node * getLeftMostChild(node *tree, node *treeP){
 	node *leftMostChild = NULL;

 	//To continue in sub tree
 	if(tree != NULL){
 		leftMostChild = getLeftMostChild(tree->lChild, tree);
 	}
 	//Reached the left most tree
 	//In this case we need to do some house keeping :P
 	//If the leftMostChild has a right child then,
 	//Assign it as left child to the leftMostChilds parent
 	//and then return the leftMostChild
 	else{
 		//leftMostChild has a right child
 		if(treeP->rChild != NULL){
 			treeP->parent->lChild = treeP->rChild;
 			treeP->rChild->parent = treeP->parent;
 		}

 		//Delete the reference from its parent to this node as we are going to take this away
 		//NOTE: If the deleting node is root and its rChild has no children then the leftMostNode will
 		//be its parents right node. So, we can't assume that tree->parent->lChild = NULL would do the thing
 		else{
 			//Normal case
 			if(treeP->parent->lChild == treeP)
 				treeP->parent->lChild = NULL;
 			//Special case - root being deleted with rChild has no childs case
 			else
 				treeP->parent->rChild = NULL;
 		}
 		leftMostChild = treeP;
 	}

 	return leftMostChild;
 }

 bool deleteNode(int key, node *tree, node *treeP){
 	bool result = 0;

 	if(tree != NULL){
 		if(key < tree->key){
 			result = deleteNode(key, tree->lChild, tree);
 		}
 		else if(key > tree->key){
 			result = deleteNode(key, tree->rChild, tree);
		}
 		//This is the delete node
 		else{
 			//Case 1: Delete node has no childs
 			if(tree->lChild == NULL && tree->rChild == NULL){

 				//Ensure that the node itself is not root. In which case the tree will be empty
 				//Normal case
 				if(treeP != NULL){
	 				if(treeP->lChild == tree){
	 					treeP->lChild = NULL;
	 				}
	 				else if(treeP->rChild == tree){
	 					treeP->rChild = NULL;
	 				}
	 			}
	 			//Deleting root with no childs
	 			else{
	 				root = NULL;
	 			}
 			}
 			//Case 2: Delete node has two child
 			else if(tree->lChild != NULL && tree->rChild != NULL){
 				node *replacingNode = getLeftMostChild(tree->rChild, tree);

 				//We now have the replacing node with all necessary house keeping done.
 				//All we need to do is just put it in place of the deleting node

 				//Ensure the parent of deleting node (tree) is not NULL. i.e., tree is not root.
				if(treeP != NULL){

					//Deleting node is its parents lChild
					if(treeP->lChild == tree){
						treeP->lChild = replacingNode;
						replacingNode->parent = treeP;
					}

					//Deleting node is its parents rChild
					else if(treeP->rChild == tree){
						treeP->rChild = replacingNode;
						replacingNode->parent = treeP;
					}

					replacingNode->lChild = tree->lChild;
					tree->lChild->parent = replacingNode;

					//tree->rChild is tricky because rChild could be the replacing node
					//In which case the present rChild of tree will be set to NULL by getMostLeftChild() call

					//Normal case
					if(tree->rChild != NULL){
						replacingNode->rChild = tree->rChild;
						tree->rChild->parent = replacingNode;
					}
					//The special discussed above
					else{
						replacingNode->rChild = NULL;
					}
				}

				//If deleting node's parent is NUll => Deleting node is root and also it has two childs 
				else{
					root = replacingNode;
					root->parent = NULL;

					//Updating lChild and lChilds parent as new root
					root->lChild = tree->lChild;
					tree->lChild->parent = root;


					//root->rChild is tricky because rChild could be the replacing node
					//In which case the present rChild of root will be set to NULL by getMostLeftChild() call
					//Normal case
					if(tree->rChild != NULL){
						root->rChild = tree->rChild;
						//Updating parent reference from rChild to new root
						tree->rChild->parent = root;
					}
					//The special discussed above
					else{
						root->rChild = NULL;
					}
					
				}
 			}

 			//Case 3: Delete node has only one child
 			else{
 				//Case 31: That one child is lChild
 				if(tree->lChild != NULL){

 					//Ensure the parent of deleting node (tree) is not NULL. i.e., tree is not root.
 					if(treeP != NULL){

 						//Deleting node is its parents lChild
	 					if(treeP->lChild == tree){
	 						treeP->lChild = tree->lChild;
	 						tree->lChild->parent = treeP;
	 					}

	 					//Deleting node is its parents rChild
	 					else if(treeP->rChild == tree){
	 						treeP->rChild = tree->lChild;
	 						tree->lChild->parent = treeP;
	 					}
	 				}

	 				//If deleting node's parent is NUll => Deleting node is root and also it has 
	 				else{
	 					root = tree->lChild;
	 					root->parent = NULL;
	 				}
 				}
 				//Case 32: That one child is rChild
 				else if(tree->rChild != NULL){

 					//Ensure the parent of deleting node (tree) is not NULL. i.e., tree is not root.
 					if(treeP != NULL){

 						//Deleting node is its parents lChild
	 					if(treeP->lChild == tree){
	 						treeP->lChild = tree->rChild;
	 						tree->rChild->parent = treeP;
	 					}

	 					//Deleting node is its parents rChild
	 					else if(treeP->rChild == tree){
	 						treeP->rChild = tree->rChild;
	 						tree->rChild->parent = treeP;
	 					}
	 				}

	 				//If deleting node's parent is NUll => Deleting node is root and also it has 
	 				else{
	 					root = tree->rChild;
	 					root->parent = NULL;
	 					tree->rChild->parent = tree;
	 				}
 				}
 			}
 			
 			result = 1;
 			if(treeP != NULL)
 				splayOp(treeP);
 		}
 	}else{
 		result = 0;
 		splayOp(treeP);
 	}

 	return result;
 }

 void deleteTree(int key){
 	bool result = deleteNode(key, root, NULL);
 	if(result)
 		cout<<endl<<"Found and deleted !"<<endl;
 	else
 		cout<<endl<<"Not found to delete !"<<endl;

 }

 void init1to15(){
 	root = Insert(8, root, NULL);
 	root = Insert(4, root, NULL);
 	root = Insert(12, root, NULL);
 	root = Insert(2, root, NULL);
 	root = Insert(6, root, NULL);
 	root = Insert(10, root, NULL);
 	root = Insert(14, root, NULL);
 	root = Insert(1, root, NULL);
 	root = Insert(3, root, NULL);
 	root = Insert(5, root, NULL);
 	root = Insert(7, root, NULL);
 	root = Insert(9, root, NULL);
 	root = Insert(11, root, NULL);
 	root = Insert(13, root, NULL);
 	root = Insert(15, root, NULL);
 }


 /******************************** Main program ********************************/

int main(){
	cout<<endl<<"Intialising tree with as a 15 node full try with keys 1-15"<<endl;
	init1to15();
	printTree();

	//Searching from 15-1
	cout<<endl<<endl<<"Performing search operations"<<endl;
	for (int i = 15; i > 0; i--){
		cout<<endl<<endl<<"Searching for key: "<<i<<endl;
		searchTree(i);
		printTree();
	}
	cout<<endl<<"Search operation complete"<<endl;

	cout<<endl<<endl<<"Performing delete operations"<<endl;
	cout<<"Deleting 15.."<<endl;
	deleteTree(15);
	printTree();

	cout<<endl<<endl<<"Deleting 14..";
	deleteTree(14);
	printTree();

	cout<<endl<<endl<<"Deleting 4..";
	deleteTree(4);
	printTree();

	cout<<endl<<endl<<"Deleting 5..";	
	deleteTree(5);
	printTree();

	cout<<endl<<endl<<"Deleting 1..";
	deleteTree(1);
	printTree();

	char waitForUserAction;
	cin>>waitForUserAction;
}

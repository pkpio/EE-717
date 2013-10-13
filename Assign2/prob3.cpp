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
	//if(key != 6)
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
		cout<<endl<<endl<<"The current BST is: "<<endl;

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

 bool delete(int key, node *tree, node *treeP){
 	bool result = 0;

 	if(tree != NULL){
 		if(key < tree->key)
 			delete(key, tree->lChild, tree);
 		else if(key > tree->key)
 			delete(key, tree->rChild, tree);
 		else{
 			//Case 1: Delete node has no childs
 			if(tree->lChild == NULL && tree->lChild == NULL){
 				if(treeP->lChild == tree){
 					tree->lChild = NULL;
 					splayOp(treeP);
 					result = 1;
 				}
 				else if(treeP->rChild == tree){
 					tree->rChild = NULL;
 					splayOp(treeP);
 					result = 1;
 				}
 			}

 			//Case 2: Delete node has two child
 			else if(tree->lChild != NULL && tree->rChild != NULL){

 			}

 			//Case 3: Delete node has only one child
 			else{
 				//Case 31: That one child is lChild
 				if(tree->lChild != NULL){
 					if(treeP->parent != NULL){
	 					treeP->lChild = tree
	 				}
 				}
 				//Case 32: That one child is rChild
 				else if(tree->rChild != NULL){

 				}
 			}
 		}
 	}else{
 		result = 0;
 		splayOp(treeP);
 	}
 }

 void deleteTree(int key){

 }


 /******************************** Main program ********************************/

int main(){
    //First insert needs root
	insertTree(9);
	insertTree(5);
	insertTree(4);
	insertTree(6);
	insertTree(8);
	insertTree(15);
	insertTree(13);
	insertTree(11);
	insertTree(12);
	insertTree(18);
	insertTree(17);
	insertTree(19);
	
	printTree();

	searchTree(13);
	printTree();


	/*insertTree(13);
	insertTree(12);
	insertTree(15);
	insertTree(16);*/



	int c;
	cin>>c;
}

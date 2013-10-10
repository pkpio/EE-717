/*********************************************************
Heap used for this problem is a min Heap
Each node in the heap is a doubly linked.
It has pointers to left, right childs and parent
**********************************************************/

#include <iostream>
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
node *fLeaf = NULL; //Last leaf that is filled


/***********	Queue operations - used in level order traversal	********/
//Assumed max # of root nodes as 50. Just to make Queue implementation easy
#define width 50

node* queue[width];
int qPtr = 0;
int qFrntPtr = 0;	//For implementing Queues using circular array

void enqueue(node* val){
	if(qPtr != width){
		queue[qPtr] = val;
		qPtr++;
	} else{
		cout<<"Queue is full !"<<endl;
	}
}

int dequeue(){
	node* val;
	if(qFrntPtr < qPtr){
		val = queue[qFrntPtr];
		queue[qFrntPtr] = 0;
		qFrntPtr++;
	} else{
		cout<<"Queue is empty !"<<endl;
		qFrntPtr = 0;
		qPtr = 0;
	}
	return val;
}

bool qEmpty(){
	if(qPtr == qPtr)
		return true
	else
		return false
}



/**********************		Heap operations		*********************/
void Insert(int key){
	//Creating a new node hold this key
	node *temp = new node;
	temp->key = key;

	//Just Insertion of root node as a left. Max checking will follow after this
	if(root != NULL){
		//Case 1: Leaf node has no childs
		if(fLeaf->lChild == NULL){
			fLeaf->lChild = temp;
			temp->parent = fLeaf;
			fLeaf = temp;
		} 
		//Case 2: Leaf node has no sibling
		else if((fLeaf->parent)->RChild == NULL){
			fLeaf->rChild = temp;
			temp->parent = fLeaf;
			fLeaf = temp;
		}
		//Not possible case
		else{
			cout<<"Error ! Reached an impossible state. Please recheck the code !"<<endl;
		}
	}else{
		root = temp;
		fLeaf = temp;
	}

	//Checking for proper position for the new leaf
	//Condition is no parent's key should be smaller than child
	temp = fLeaf;

	while(temp->key > (temp->parent)->key){
		node *temp2 = temp->parent;

		temp->parent = temp2->parent;

		//Case 1: Newly inserted node is inserted as a right node to its parent
		if(temp2->rChild != NULL){
			temp->lChild = temp2->lChild;
			temp->rChild = temp2;		} 
		//Newly inserted node is inserted as a left child
		else{
			temp->lChild = temp2;
		}
		temp2->parent = temp;
		temp2->lChild = NULL;
		temp2->rChild = NULL;
	}

	////////////	NEEDED CONDITION FOR TEMP REACHING ROOT ????

}

void printHeap(){
	node* temp = root;
	cout<<"The current heap is: "<<endl;
	cout<<temp->key<<endl;
	enqueue(temp->lChild);
	enqueue(temp->rChild);

	i = 0; //to insert a line break
	while(!qEmpty){
		temp = dequeue();
		cout<<temp->key<<" ";

		if(temp->lChild != NULL)
			enqueue(temp->lChild);
		if(temp->rChild != NULL)
			enqueue(temp->rChild);

		//Below lines are just to ensure a line break after a level
		i++;
		if(i%2 == 0)
			cout<<endl;
	}
 }


 /******************************** Main program ********************************/

node *temp = new node;
temp->key = 3;

node *temp1 = new node;
temp1->key = 2;

node *temp2 = new node;
temp2->key = 1;

root = temp;
root->lChild = temp1;
root->rChild = temp2;

printHeap();
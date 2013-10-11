/*********************************************************
Heap used for this problem is a min Heap
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
node *fLeaf = NULL; //Last leaf that is filled


/***********	Queue operations - used in level order traversal	********/
//Assumed max # of root nodes as 50. Just to make Queue implementation easy
#define width 50

node *queue[width];
int qPtr = 0;
int qFrntPtr = 0;	//For implementing Queues using circular array

void enqueue(node *val){
	if(qPtr != width){
		queue[qPtr] = val;
		qPtr++;
	} else{
		cout<<"Queue is full !"<<endl;
	}
}

node * dequeue(){
	node *val;
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
    bool output = false;
	if(qPtr == qFrntPtr){
		output = true;
	} else{
		output = false;
    }
    return output;
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
		else if((fLeaf->parent)->rChild == NULL){
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
	node *temp = root;
	cout<<"The current heap is: "<<endl;
	cout<<temp->key<<endl;
	enqueue(temp->lChild);
	enqueue(temp->rChild);

	int i = 1; //to insert a line break
	int j = 1;
	while(qPtr != qFrntPtr){
		temp = dequeue();
		cout<<temp->key<<" ";

		if(temp->lChild != NULL){
			enqueue(temp->lChild);
		}
		if(temp->rChild != NULL){
			enqueue(temp->rChild);
		}

		//Below lines are just to ensure a line break after a level
		i++;
		if((i+1)%((int)pow(2.0, j)) == 0){
			cout<<endl;
			j++;
		}
	}
 }


 /******************************** Main program ********************************/

int main(){
    
    // Test nodes...........
	node *temp = new node;
	temp->key = 10;
	temp->lChild = NULL;
	temp->rChild = NULL;

	node *temp1 = new node;
	temp1->key = 9;
	temp1->lChild = NULL;
	temp1->rChild = NULL;

	node *temp2 = new node;
	temp2->key = 8;
	temp2->lChild = NULL;
	temp2->rChild = NULL;

	node *temp3 = new node;
	temp3->key = 7;
	temp3->lChild = NULL;
	temp3->rChild = NULL;

	node *temp4 = new node;
	temp4->key = 6;
	temp4->lChild = NULL;
	temp4->rChild = NULL;

	node *temp5 = new node;
	temp5->key = 5;
	temp5->lChild = NULL;
	temp5->rChild = NULL;

	node *temp6 = new node;
	temp6->key = 4;
	temp6->lChild = NULL;
	temp6->rChild = NULL;

	node *temp7 = new node;
	temp7->key = 14;
	temp7->lChild = NULL;
	temp7->rChild = NULL;

	node *temp8 = new node;
	temp8->key = 15;
	temp8->lChild = NULL;
	temp8->rChild = NULL;

	node *temp9 = new node;
	temp9->key = 16;
	temp9->lChild = NULL;
	temp9->rChild = NULL;

	node *temp10 = new node;
	temp10->key = 17;
	temp10->lChild = NULL;
	temp10->rChild = NULL;

	root = temp;
	root->lChild = temp1;
	root->rChild = temp2;
	temp1->lChild = temp3;
	temp1->rChild = temp4;
	temp2->lChild = temp5;
	temp2->rChild = temp6;
	temp3->lChild = temp7;
	temp3->rChild = temp8;
	temp4->lChild = temp9;
	temp4->rChild = temp10;

	printHeap();

	int c;
	cin>>c;
}

#include <iostream>
using namespace std;

#define size 10

//Stack variables
int stackArray[size];	//An array to hold the stack
int stackIndex = 0;		//Index for stack

/*****************	Stack operations	*********************/
int pop(int stack){
	int value;
	if (stackIndex != 0){
		stackIndex--;
		value = stackArray[stackIndex];
		stackArray[stackIndex] = 0;
	}
	else{
		cout << "No more values to POP" << endl;
	}

	return value;
}

void push(int value){
	if (stackIndex != size){
		stackArray[stackIndex] = value;
		stackIndex++;
	}
	else{
		cout << "Stack overflow !" << endl;
	}
}
/*********************		End of stack operations		*********************/


/**********************		Linked list operations		*********************/
//Define a node
typedef struct node{
	int data;
	node *next;
};

//Initialize a linked list with NULL for head node
node *head = NULL;

void Insert(int value){
	node *temp;
	temp = (node*) malloc(sizeof(node));
	temp->data = value;
	temp->next = head;
	head = temp;
}

void Remove(int index){
	node *prevNode;	//Node just before node to be removed
	node *curNode;	//Node to be removed
	int removedVal;	//Value removed

	if (head != nullptr){
		prevNode = head;
		curNode = head->next;
	}
	else
	{
		cout << "There is nothing left to remove ! We are prepared for all possibilities :P" << endl;
		return;
	}

	if (index == 0){
		removedVal = head->data;
		if (head->next != nullptr)
			head = head->next;
		else
			head = nullptr;
	}
	else{
		for (int i = 0; i < index - 1; i++){
			prevNode = curNode;//1
			if (curNode->next != nullptr){
				curNode = curNode->next;//2
			}
			else{
				cout << "Invalid index ! We are prepared for all possibilities :P" << endl;
				return;
			}
		}
		if (curNode->next != nullptr)
			prevNode->next = curNode->next;
		else
			prevNode->next = nullptr;

		removedVal = curNode->data;
	}

	cout << "Removed value : " << removedVal << " from index : " << index << endl;
}

/***********************	End of linked list	operations*************************/

/***********************	Queue operations		**********************/
void enque(int value){
	Insert(value);
}

int deque(){
	Remove(0);
}


void main(){
	int value;	//To remember value given (Data or Index)
	int opSel;	//To remember operation choice
	while (1){
		cout << "Select an operation on the list." << endl;
		cout << "1. Insert" << endl << "2. Remove" << endl;
		cin >> opSel;

		switch (opSel){
		case 1:
			cout << "Enter value to be inserted" << endl;
			cin >> value;
			Insert(value);
			break;

		case 2:
			cout << "Enter the index of element to be removed" << endl;
			cin >> value;
			Remove(value);
			break;
		}
	}
}
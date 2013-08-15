#include <iostream>
using namespace std;

//Define a node
typedef struct node{
	int data;
	node *next;
};

//Initialize linked list with NULL for head node
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
		for (int i = 0; i < index-1; i++){
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

void main(){
	int value;	//To remember value given (Data or Index)
	int opSel;	//To remember operation choice
	while(1){
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
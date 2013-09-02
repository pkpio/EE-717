#include <iostream>
using namespace std;

int size = 0;//To keep track of the size of the linkedlist
int deleteCount = 0;//To keep track of psuedo deleted elements

/**********************		Linked list operations		*********************/

//Define a node
struct node{
	int data;
	bool deleted;	//True => This is a deleted node
	node *next;
};


//Initialize a linked list with NULL for head node
node *head = NULL;

void Insert(int value){
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
	size++;
}

void lazyRemove(int index){
	int valueRemoved = 0;
	node *temp = head;
	if(head != NULL){
		if(head->deleted == true)
			index++;	//Because the below loop doesn't check for delete state of 0th node
		for(int i=0; i<index; i++){
			temp = temp->next;
			if(temp->deleted == true)
				i--;
		}
		valueRemoved = temp->data;
		temp->deleted = true;	//Mark that node as deleted. temp points to the node to be deleted
		cout<<"Removed element value : "<<valueRemoved<<endl;
		deleteCount++;
	} else{
		cout<<"Linked list is empty bro. !"<<endl;
	}		
}

void doStndDelete(){
	if(head != NULL){
		bool keepLooping = true;
		while(keepLooping && head != NULL){
			if(head->deleted == true){
				head = head->next;
				size--;
			}
			else{
				node *temp = head;
				while(temp->next != NULL){
					if((temp->next)->deleted == true){
						if((temp->next)->next != NULL){
							temp->next = (temp->next)->next;
							size--;
						} else{
							temp->next = NULL;
							size--;
						}
					} else{
						temp = temp->next;
					}
				}
				keepLooping = false;
			}
		}
		deleteCount = 0;
		cout<<"Standard deletion completed !"<<endl;
	} else{
		cout<<"Linked list is empty bro. !"<<endl;
	}
}

/***********************	End of linked list	operations*************************/


//****************	Main program	*********************//

int main(){
	//Structure of linked list implemented
	cout<<endl<<endl<<endl<<"NOTE :"<<endl;
	cout<<"Head always points to a newly inserted value"<<endl<<endl;

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
			cout << "Enter the index of the element to be removed. "<<endl;
			cin >> value;
			lazyRemove(value);
			if(deleteCount > size/2){
				cout<<"Time to perform a standard deletion operation"<<endl;
				doStndDelete();
			}				
			break;
		}
	}
}

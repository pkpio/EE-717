#include <iostream>
using namespace std;

/**********************		Linked list operations		*********************/

//Define a node
struct node{
	int data;
	node *next;
};


//Initialize a linked list with NULL for head node
node *head = NULL;

void Insert(int value){
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

void Get(int index){
	int valueGot = 0;
	node *temp = head;
	if(head != NULL){
		if(index>0){
			for(int i=0; i<index-1; i++){
				if(temp->next != NULL){
					temp = temp->next;
				} else{
					cout<<"Invalid index !" << endl;
				}
			}
			//By now temp will be the node before node we are trying to get
			node *temp2 = temp->next;	//temp2 is the node we are trying to get		
			temp->next = temp2->next;	//Point node prev to get node to the node next to get node
			temp = head;	//Saving head
			head = temp2;	//Get node to first of linked list
			temp2->next = temp;	//Get nodes next as earlier next
			valueGot = head->data;
			cout<<"Moved element to index '0'. Value got : "<< valueGot << endl;
			cout<<"To verify, use Pop"<<endl;			
		} else{
			valueGot = head->data;
			cout<<"That was an easy get index :P Value got : "<< valueGot << endl;
		}
	} else{
		cout<<"Linked list is empty bro. !"<<endl;
	}
}


void Pop(){
	int valueRemoved = 0;
	if(head != NULL){
		valueRemoved = head->data;
		head = head->next;
		cout<<"Popped value : "<<valueRemoved<<endl;
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
		cout << "Select an operation on the list. NOTE : POP deletes the first element" << endl;
		cout << "1. Insert" << endl << "2. Fetch" << endl << "3. Pop" << endl;
		cin >> opSel;

		switch (opSel){
		case 1:
			cout << "Enter value to be inserted" << endl;
			cin >> value;
			Insert(value);
			break;

		case 2:
			cout << "Enter the index of the element. Index is the key."<<endl;
			cin >> value;
			Get(value);	
			break;
			
		case 3:
			Pop();				
			break;
		}
	}
}

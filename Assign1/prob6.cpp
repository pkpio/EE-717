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

void Remove(){
	int valueRemoved = 0;
	if(head != NULL){
		valueRemoved = head->data;
		head = head->next;
		cout<<"Removed element value : "<<valueRemoved<<endl;
	} else{
		cout<<"Linked list is empty bro. !"<<endl;
	}		
}

/***********************	End of linked list	operations*************************/


//****************	Main program	*********************//

int main(){
	//Structure of linked list implemented
	cout<<endl<<endl<<endl<<"NOTE :"<<endl;
	cout<<"This linked list is made to work well for a stack"<<endl;
	cout<<"Head always points to a newly inserted value"<<endl;
	cout<<"A remove operation always removes the top element. i.e., latest inserted"<<endl;

	int value;	//To remember value given (Data or Index)
	int opSel;	//To remember operation choice
	bool dataEntry = true; //false => Done with entry of data

	cout<<"Inorder to test, you need to enter some data into linked list first !"<<endl;
	cout<<"NOTE : Atleast 3 data points are required !"<<endl;

	loop:
		while (dataEntry){
			cout << "Select an operation on the list." << endl;
			cout << "1. Insert" << endl << "2. Remove"  << endl << "3. Done with entering data" << endl;
			cin >> opSel;

			switch (opSel){
			case 1:
				cout << "Enter value to be inserted" << endl;
				cin >> value;
				Insert(value);
				break;

			case 2:
				cout << "Please be informed that this will remove latest inserted value."<<endl;
				Remove();
				break;
			
			case 3:
				dataEntry = false;
				cout << "commencing reversal operation..." << endl;
				break;
			}
		}
	
		//Reversal operation
		node *temp1;
		node *temp2;
		node *temp3;
	
		temp1 = head;
		temp2 = temp1->next;
		temp3 = temp2->next;
	
		temp1->next = NULL;
	
		while(temp3->next != NULL){
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp3->next;
		}
		head = temp3;
		temp3->next = temp2;
		temp2->next = temp1;
		
		cout<<"Reversal operation completed successfully !"<<endl;
		cout<<"You may verify the operation by removing values. First inserted value should come out first !"<<endl;
		dataEntry = true;
	goto loop;
}

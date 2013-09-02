#include <iostream>
using namespace std;

#define size 10
int queue[size];
int stack[size];
int stkPtr = 0;
int qPtr = 0;

//This additional variable is because we are using an Array for Queue implementation
//So when we remove from front we won't shift everything. Rather we just keep a pointer saying next element is new front
//When end of Queue is reached we reset qPtr and qFrntPtr to 0
int qFrntPtr = 0;


/***************** Queue operations *************/
void enqueue(int val){
	if(qPtr != size){
		queue[qPtr] = val;
		qPtr++;
	} else{
		cout<<"Queue is full !"<<endl;
	}
}

int dequeue(){
	int val = 0;
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

/***************** Stack operations *************/
void push(int val){
	if(stkPtr != size){
		stack[stkPtr] = val;
		stkPtr++;
	} else{
		cout<<"Stack is full bro. !"<<endl;
	}
}

int pop(){
	int val = 0;
	if(stkPtr != 0){
		stkPtr--;
		val = stack[stkPtr];
		stack[stkPtr] = 0;
	} else{
		cout<<"Stack is empty !"<<endl;
	}
	return val;
}


/****************   Print operations    *******************/
void printQueue(){
	cout<<"[ ";
	for(int i=0;i<size-1;i++){
		cout<<queue[i]<<", ";
	}
	cout<<queue[size-1]<<" ]"<<endl;
}

void printStack(){
	cout<<"[ ";
	for(int i=0;i<size-1;i++){
		cout<<stack[i]<<", ";
	}
	cout<<stack[size-1]<<" ]"<<endl;
}


////******************** Main program *********************///////////

int main(){
	//Building a queue for testing...
	cout<<endl<<endl<<endl<<"Bulding a queue for testing."<<endl;
	cout<<"Queue size is : "<<size<<endl;
	cout<<"You may change it in source code."<<endl;
	for(int i=0;i<size;i++){
		enqueue(i);
	}


	cout<<"The contents of Queue are : "<<endl;
	printQueue();

	cout<<"Present contents of stack : "<<endl;
	printStack();

	//Idea is to push everything all Queue elements to stack first	- N steps -same order
	//Then POP each of them back to Queue from stack				- N steps -order reverses
	//Later push them to stack again 								- N steps -same order as previous - acheives required task

	//Pushing everything to stack
	cout<<"Pushing elements to stack..."<<endl;
	for(int i=0;i<size;i++){
		push(dequeue());	
	}

	cout<<"New contents of stack : "<<endl;
	printStack();

	//Popping back everything to queue. NOTE : here order changes
	qFrntPtr = 0;
	qPtr = 0;	//To say that we are actually pushing it into a empty Queue. All this because I used an Array :P
	for(int i=0;i<size;i++){
		enqueue(pop());	
	}

	cout<<"New contents of Queue : "<<endl;
	printQueue();

	//Now a final Push of everything to Stack
	cout<<"Pushing elements to stack..."<<endl;
	for(int i=0;i<size;i++){
		push(dequeue());	
	}

	cout<<"Final contents of stack : "<<endl;
	printStack();
	
	cout<<"Working ! Isn't it ?"<<endl;
	cout<<endl<<endl<<endl;
	return 0;
}

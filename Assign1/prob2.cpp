#include <iostream>
using namespace std;

#define size 4
int deque[size];
int frontPtr = size/2;//Pushing happens from center to the right of the array	NOTE: No circular filling
int backPtr = (size/2)-1;//Inject happens from center to the left of the array

void printDeque(){
	cout<<"[ ";
	for(int i=0; i<size; i++){
		cout<<deque[i]<<" ";
	}
	cout<<"]"<<endl;
}

void push(int val){
	if(frontPtr != size){
		deque[frontPtr] = val;
		frontPtr++;
		cout<<"The new deque is : "<<endl;
	} else{
		cout<<"Deque overflow ! Try injecting instead !"<<endl;
		cout<<"The current deque is : "<<endl;
	}
	printDeque();
}

void pop(){
	if(backPtr - frontPtr != -1){
		frontPtr--;
		cout<<"Popped : "<<deque[frontPtr];
		deque[frontPtr] = 0;
		cout<<"The new deque is : "<<endl;
	} else{
		cout<<"No more values to POP !"<<endl<<"The current deque is : "<<endl;
	}
	printDeque();
}

void inject(int val){
	if(backPtr != -1){
		deque[backPtr] = val;
		backPtr--;
		cout<<"The new deque is : "<<endl;
	} else{
		cout<<"Deque overflow ! Try pushing instead !"<<endl;
		cout<<"The current deque is : "<<endl;
	}
	printDeque();
}

void eject(){
	if(backPtr - frontPtr != -1){
		backPtr++;
		cout<<"Ejected : "<<deque[backPtr];
		deque[backPtr] = 0;
		cout<<"The new deque is : "<<endl;
	} else{
		cout<<"No more values to POP !"<<endl<<"The current deque is : "<<endl;
	}
	printDeque();
}

int main(){
	int opSel = 1;//current operation to be performed
	int opVal = 0;//Value to be operated upon. push/inject

	while(1){
		cout<<"Select an operation to perform on the deque"<<endl;
		cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Inject"<<endl<<"4. Eject"<<endl;

		cin>>opSel;
		switch(opSel){
			case 1: 
				cout<<"Enter value to be PUSHED"<<endl;
				cin>>opVal;
				push(opVal);
				break;
			case 2:
				pop();
				break;
			case 3:
				cout<<"Enter value to be INJECTED"<<endl;
				cin>>opVal;
				inject(opVal);
				break;
			case 4:
				eject();
				break;
			}
	}
}

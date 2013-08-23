#include <iostream>
using namespace std;

#define size 20

//One stack fills array from left while other from right
int s1Ptr = 0;			//Stack 1 pointer
int s2Ptr = size-1;		//Stack 2 pointer
int stackArray [size];

void printArray(){
	cout<<"[ ";
	for(int i=0; i<size; i++){
		cout<<stackArray[i]<<" ";
	}
	cout<<"]"<<endl;
}

bool isEmpty(int stack){
	bool stackEmpty = true;
	switch(stack){
	case 1:
		if(s1Ptr == 0)
			stackEmpty = true;
		else
			stackEmpty = false;
		break;
	case 2: 
		if(s2Ptr == size)
			stackEmpty = true;
		else
			stackEmpty = false;
		break;
	}

	return stackEmpty;
}

int sizeOfStack(int stack){
	int sSize = 0;
	switch(stack){
	case 1:
		sSize = s1Ptr;
		break;
	case 2: 
		sSize = size - s2Ptr;
		break;
	}

	return sSize;
}

void pop(int stack){
	switch(stack){
	case 1: 
		if(s1Ptr != 0){
			s1Ptr--;
			cout<<"Popped : "<<stackArray[s1Ptr]<<endl;
			stackArray[s1Ptr] = 0;
		} else{
			cout<<"No more values to POP"<<endl;
		}
		break;
	case 2: 
		if(s2Ptr != size-1){
			s2Ptr++;
			cout<<"Popped : "<<stackArray[s2Ptr]<<endl;
			stackArray[s2Ptr] = 0;
		} else{
			cout<<"No more values to POP"<<endl;
		}
		break;
	}

	cout<<"New array is :"<<endl;
	printArray();
}

void push(int stack, int value){
	if(s2Ptr-s1Ptr != -1){
		switch(stack){
		case 1: 
			stackArray[s1Ptr] = value;
			s1Ptr++;
			break;
		case 2: 
			stackArray[s2Ptr] = value;
			s2Ptr--;
			break;
		}

		cout<<"New array is :"<<endl;
		printArray();
	} else{
		cout<<"Stack overflow !"<< endl;
		cout<<"Current array is :"<<endl;
		printArray();
	}
}

int main(){
	int sSel = 1; //Stack selector variable
	int opSel = 1; //operation selector i.e., PUSH or POP or isEmpty
	int pushVal = 0;

	while(1){
		cout<<endl<<"Select a stack to do an operation. Enter 1 or 2"<<endl;
		cin>>sSel;
		cout<<"Select an operation"<<endl;
		cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. isEmpty"<<endl<<"4. sizeOf"<<endl;
		cin>>opSel;
		switch(opSel){
		case 1: 
			cout<<"Enter value to be PUSHED"<<endl;
			cin>>pushVal;
			push(sSel,pushVal);
			break;
		case 2:
			pop(sSel);
			break;
		case 3:
			cout<<isEmpty(sSel)<<endl;
			break;
		case 4:
			cout<<sizeOfStack(sSel)<<endl;
			break;

		}
	}
}



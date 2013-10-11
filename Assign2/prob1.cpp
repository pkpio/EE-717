/*********************************************************
Heap used for this problem is a max Heap
Heap implemented using a circular array

Index starts from 1.
For element i,
parent_index = i/2
lChild = i*2 	rChild = i*2 + 1
**********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define size 50

int heap[size];
int ptr = 1;//Current location in the array to be filled with new values
int keyDiff = 0;

/************ Other functions ****************/
void exchange(int i, int j){
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}


/**************	Heap operations ******************/
void insertHeap(int val){
	//Normal insertion at the end
	if(ptr != size){
		heap[ptr] = val+keyDiff;
		ptr++;
	}

	//Checking for the right position
	int chld = ptr-1;
	int prnt = chld/2;
	while(prnt != 0){
		if(heap[chld]>heap[prnt]){
			int temp = heap[prnt];
			heap[prnt] = heap[chld];
			heap[chld] = temp;
			chld = prnt;
			prnt = chld/2;
		}else{
			break;
		}
	}
}


void printHeap(){
	cout<<"Level order traversal of current heap is: "<<endl;

	int j = 1; //Line number
	for(int i=1; i<ptr; i++){
		//Print element
		cout<<heap[i]-keyDiff<<" ";

		//For a line break
		int k = (int) pow(2.0,j);
		if((i+1)%k == 0){
			cout<<endl;
			j++;			
		}
	}
	cout<<endl<<endl;
}


void delHeap(){
	int prnt = 1;
	int lChild = prnt*2;
	int rChild = prnt*2+1;

	//Replace root with bottom most element
	heap[1] = heap[ptr-1];
	ptr--;

	while(lChild < ptr){
		//Case 1: Right child exists
		if(rChild < ptr){
			//Case 1: lChild < rChild
			if(heap[lChild] < heap[rChild]){
				//Case 1: p < l < r 
				if(heap[prnt] < heap[lChild]){
					exchange(prnt, rChild);
					prnt = rChild;
					lChild = prnt*2;
					rChild = prnt*2 +1;
				} 
				//Case 2: l < p < r
				else if(heap[prnt] < heap[rChild]){
					exchange(prnt, rChild);
					prnt = rChild;
					lChild = prnt*2;
					rChild = prnt*2 +1;
				}
				//case 3: l < r < p
				else{
					//Get out of loop
					break;
				}
			}
			//Case 2: lChild > rChild
			else{
				//Case 1: p < r < l 
				if(heap[prnt] < heap[rChild]){
					exchange(prnt, lChild);
					prnt = lChild;
					lChild = prnt*2;
					rChild = prnt*2 +1;
				} 
				//Case 2: r < p < l
				else if(heap[prnt] < heap[lChild]){
					exchange(prnt, lChild);
					prnt = lChild;
					lChild = prnt*2;
					rChild = prnt*2 +1;
				}
				//case 3: r < l < p
				else{
					//Get out of loop
					break;
				}
			}

		}
		//rChild doesn't exit
		else{
			//lChild > prnt
			if(heap[lChild] > heap[prnt]){
				exchange(lChild, prnt);
			}
			//lChild < prnt
			else{
				//Get out of loop
				break;
			}
		}
	}
}


int decreaseAllKeys(int val){
	keyDiff = keyDiff+val;
}


int main(){
	//Initialization with given values
	for(int i=5; i<19; i++){
		insertHeap(i);
	}
	printHeap();

	decreaseAllKeys(2);
	printHeap();

	insertHeap(19);
	printHeap();

	insertHeap(18);
	printHeap();

	decreaseAllKeys(1);
	printHeap();

	delHeap();
	printHeap();

	delHeap();
	printHeap();
	
	delHeap();
	printHeap();


	int k;
	cin>>k;
	return 0;
}

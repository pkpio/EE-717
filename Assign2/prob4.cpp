/***********************************************************************

***********************************************************************/

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
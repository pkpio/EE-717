EE-717
======

Assignment 1
-------------

Advanced computing course assignments done in C++

These are my solutions. I bear no resposibility for your loss in using my codes or any actions for plagiarism.

1. Each problem in the codes also have additional functions to test the working of the code.
2. Logic can be verified by executing the g++ generated executables for each problem


Questions

1. Write a routine to implement two stacks using one array. Your stack should not declare overflow unless every slot in the array is used.




2. A deque is a data structure consisting of a list of items, on which the following operations are possible:
   Push (X, D): Insert item X on the front end of deque D.

   Pop (D): Remove the front item from deque D and return it.

   Inject (X, D): Insert item X on the rear end of deque D

   Eject (D): Remove the rear item from deque D and return it.

   Write routines to support deque that take O(1) time per operation
   
   
  
   
3. Skip list is an efficient linked list based data structure that attempts to implement binary search on linked list. Develop programs to implement search, insert, and delete operations in skip lists.




4. A queue Q contains the items a1, a2, . . . , an-1, in the ordered with  a1 at front  and an-1 at the back.  It is required to transfer these items on to a stack S (initially empty) so that a1 is at the top of the stack and the order of all the items is preserved. Using enqueue and dequeue operations for the queue and push and pop operations for stack, design and implement an efficient O(n) algorithm to accomplish the above task, using only constant amount of additional storage.




5. An alternative to the deletion strategy we have given is to use lazy deletion. To delete an element, we merely mark it deleted (using an extra bit field). The number of deleted or non deleted elements in the list is kept as part of the data structure. If there are many deleted elements as nondeleted elements, we traverse the entire list, performing the standard deletion algorithm on all marked nodes. Write a program to implement the standard linked list operations using lazy deletion. 




6. Write a program that will reverse a linked list while traversing it only once. At the conclusion, each node should point should point to the node which was previously its predecessor: the head should point to a node which was formerly at the end, and the node which was formerly first should have a null link.




7. Write an array implementation of self-adjusting lists. A self-adjusting list is like a regular list is like a regular list, except that all insertions are performed at the front, and when the element is accessed by a get(), it is moved to the front of the list without changing the relative order of the other item. 





Assignment 2
-------------

Questions

1. Suppose we want to add the DecreaseAllkeys (Δ) operation to the heap repertoire. The result of this is that all keys in the heap have their value decrease by an amount Δ. Implement all the heap operations including DecreaseAllkeys (Δ). It should retain the same run time of all other operations and run time of DecreaseAllkeys(Δ) is O(1). Test Input: Initialize {5 – 18}, DecreaseAllKeys(2), Add{19, 18}, DecreaseAllkeys(1), Delete, Delete, Delete. Show tree after every operation. Note that the Initialization is a single operation.




2. A modification we could make to 2-3 tree is to keep only keys at interior nodes, but do not require that the keys k1 and k2 at node truly be minimum keys of the second and third subtrees, just that all keys k of the third subtree satisfy k ≥ k2, all keys k of the second satisfy k1 ≤ k ≤ k2, and all keys k of the first satisfy k < k1. Implement such a tree. Test Input: Initialize {1 – 32}, Delete{15 -- 8}, Insert/Add{33 – 36}.




3. Write a program to implement a splay tree which performs standard tree operations, i.e. find, add, and delete. Start with a splay tree that is 15 node full tree, the keys are 1 – 15. Search keys in order 15, 14, 13, 12, 11, 10, . . . ., 2, 1, and then delete nodes 15, 14, 4, 5, and 1. Draw the tree after each operation. Compute the average number of operations carried out.




4. One of the most expensive operations in an AVL tree is delete operation. One way to reduce average case complexity is use lazy deletion strategy. To delete a node, merely mark it as deleted. Actual deletion operation is performed periodically to collect garbage, say using Deldeleted operation. Implement tree operations. Test Input: Initialize {1 – 20}, Delete{3, 4, 8, 9}, Insert/Add{21, 22, 8}, Delete{10, 12, 14}, Add{23, 24}, Delete{24, 8, 23}, Add {24, 25}. Assume that the garbage collection is performed after 5 deletion operations. Show results after every operation after initialization.

# MyCppTasks
This is the scalable codes I finished using efficient data structures and implemented in C++. 
The first task is to implement Stack DataStructure using linked list. 
The second task is to merge multiple arrays and sort them using merge sort algorithms, it is useful to sort large size arrays.

# Task1-Mystack.cpp
###
/* Implementing Stack DataStructure using linked list
Stacks works on the principle of LIFO(Late-in-first-out)
hence the function we are implementing are:
1. push() to denote the queue is forming hence all the node added from top.
2. pop() removes the first element that was inserted at the starting.
3. display() show all the elements in the queue.
4. peek() returns the topElement in the stack.

 50-->20-->30-->20-->10
topElement         bottomElement */
###

# Task2-MyMergeSort.cpp
###
/*
-----------
Merge k sorted arrays (of different length), merge them into a single
array such that the merged array is also sorted.
Input: {1, 4}, {2, 5}, {3, 6, 7}
Output: {1,2,3,4,5,6,7}
---------
For large size array, to sort it
1. divide the (array)file into runs such that the size of a run
is small enough to fit into main memory.
2. sort each run in main memory using merge sort sorting algorithm
3. merge the resulting runs together into successively bigger runs
*/
###

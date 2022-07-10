//Approach - 1
//we can divide the array into k equal sizes and allot each part for one queue.
//but in this method, there will be wastage of space as we might have empty space in
//the array, but still there may be an overflow because some queues alloted space is
//full.

//complexities for enqueue and dequeue functions
//Time Complexity: O(1)
//Space Complexity: O(1) //the array uses space but the functions themselves don't use
//any space



//Approach - 2
//this approach is similar to the approach-2 of implementing k stacks in an array.

//we create an array arr in which we store the elements.
//Apart from arr, we create three other arrays:
//front: stores the index of first elment of all the queues. size = k
//initialized to -1 for all the elements.
//rear: stores the index of last element of all the queues. size = k
//next: used to link elements. stores the index of next element linked to the
//element at current index. the link might be for queues or for stack of free index.
//size = n
//initialized to next element for every element i.e., next[i]=i+1 and next[n-1]=-1

//apart from these we also have int free which stores the index of the first free
//element in arr. free is initialized to 0.

//complexities for enqueue and dequeue functions
//Time Complexity: O(1)
//Space Complexity: O(1) //the array uses space but the functions themselves don't use
//any space


void enqueue(int n, int qn)
{
	if(isFull())
		return;
	int i = free;  
	free = next[i]; //updating first element of stack of free elements
	if(isEmpty(qn)) 
		front[qn] = i;
	else
		next[rear[qn]] = i;
	rear[qn] = i; //updating index of last element of queue qn
	next[i] = -1; //important because while dequeuing if the queue gets empty then
	//front[qn] should point at -1. so, if the next[i] for the last element in a queue
	//does not point to -1 then after emptying the queue, front[qn] will not point to -1
	//and that will be an error hence, we do this.
	//if we want to avoid doing this, then before dequeuing, check if front[qn]==rear[qn]
	//if yes then make front[qn]=-1.  
	arr[i] = n;
}

int dequeue(int qn)
{
	if(isEmpty(qn))
		return INT_MAX;
	int i = front[qn];
	front[qn] = next[i]; //updating the front index of queue qn
	next[i] = free; //linking the freed index to the stack of free elements
	free = i; //updating first element of stack of free elements.
	return arr[i];
}

bool isEmpty(int qn)
{
	if(front[qn]==-1) //if front[qn]==-1 only then, will the queue qn be empty.
		return true;
	return false;
}

bool isFull()
{
	if(free = -1) //if free becomes -1, then there is no space more space left in 
		//arr and hence all the queues are now full.
		return true;
	return false;
}


//Although we are using more space by using three extra arrays but:
//firstly, this method avoids space wastage
//secondly, it may not make much sense for integer arrays but for other types of arrays
//for queues of employees, students, etc. where each item is of hundreds of byte, there, 
//extra space used is very less as we are only using three integer arrays(front, rear
//and next). But are saving a lot of space by using a efficient method to implement K
//queues in the same array.
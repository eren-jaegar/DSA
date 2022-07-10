//Approach - 1
//first approach is to initialize top and rear to 0.
//for inserting element do rear = (rear+1)%size and insert the element at that index.
//for deleting element do front = (front+1)%size and delete the element at that index.
//if front==rear then the queue is empty.
//if (rear+1)%size == front then, the queue is full.

//before inserting element check if list is full or not and before deleting element
//check whether the list is empty or not.

//we can get first element using arr[(front+1)%size] if the queue is not empty.
//we can get the last element using arr[rear] if the queue is not empty.

//in this approach, one index of the underlying array is always empty. the index
//pointed by front is always empty, even when the queue is full.

//Time Complexity: O(1)
//Space Complexity: O(1) //the array requires space but functions themselves don't 
//require any extra space.



//Approach - 2
//initialize front and rear to -1.
//for inserting elements, do rear=(rear+1)%size and insert the element.
//if front=-1 then, do front=0

//for deleting element, delete the element from index pointed by front.
//if front==rear then, do front=-1, rear=-1.
//else if front!=rear, then do front=(front+1)%size.

//for checking if the queue is empty, check if front=-1. if yes, then queue is empty
//else it isn't.

//for checking if the queue is full or not, check if (rear+1)%size==front. if yes, then
//queue is full else it isn't.

//before inserting and deleting elements check whether queue is full and empty respectively

//we can get first element using arr[front] if the queue is not empty.
//we can get the last element using arr[rear] if the queue is not empty.

//in this approach if the queue is full then it is actually full. every index of
//the underlying array is full. unlike the above approach, not a single index is 
//left empty.

//Time Complexity: O(1)
//Space Complexity: O(1) //the array requires space but functions themselves don't 
//require any extra space.
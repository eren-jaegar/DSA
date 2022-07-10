//Approach - 1
//we can divide the array in n/k partititons and give one partititon to each stack.
//first stack will be from 0 to n/k-1, second from n/k to 2n/k-1 and so on.
//if we want to push an element in say third stack then we will first call pushGeneral 
//function. This function  will use switch case to determie which stack stack's top
//is to be used. We know third stack's top is to be used but we how to tell this to
//computer? we do this using switch case.
switch sn
case 1 : top = top1; break;
case 2 : top = top2; break;
//and so on. Then we can just call another function pushSpecific with top, sn and x to
//push x into the required stack.
//sn will be used to determine the alloted range of the stack(in which we are pushing)
//in the array. we need to know the range to determine whether that stack has empty
//space or not.
//This approach wastes space as one array might get full and throw overflow error 
//while pushing more elements even when all other arrays might be completely empty.



//Approach - 2
// we create a total of 3 arrays.
//first is of size n to store the elements(lets call it arr)
//second is of size k to store the top of every stack(lets call it tops)
//third is of size n to store the next element pointed by every element(call it next)
//we also need a free pointer that keeps track of the stack of empty nodes.

//in tops, all are initially -1 as all are empty
//initially all the elements are empty so, they form a stack of empty elements so,
//in next all the elements point to the next element, i.e., next[i] = i+1. the last
//element is -1
//initially all the elements are empty so free points to 0. if free is ever -1 then
//that means there is no free space.

//basically what we do is that we insert elements into arr at the first free space
//which is pointed by free.
//then we move free so that it points to the next free space.
//in the next array, we link this element to the element pointed by top of the stack
//for which we have inserted the element.
//in tops, we update the value for the top of that stack for which we have inserted
//the element.

//example:
//push(3,5) //push 3 in 5th stack(considering there is a 0th stack).
if(free == -1)
	"no space available"
else
{
	int y = free; //free holds the index of the first free node
	arr[y] = 3; //we insert 3 at the first free node
	free = next[y]; //we move free to the next free node as the current node has 
	//now been occupied. next[y] contained the index of the next free node
	next[y] = top[5] //the element pointed by top[5] will now become the second element
	//after we have inserted the current element so, we now link it. new element is inserted
	//at y so next[y] now contains the address of the second node in the 5th stack.
	top[5] = y //updating top[5] to point at the topmost element.
}

//for pop: example: pop(6) //pop element from 6th stack.
if(top[6] == -1)
	stack is already empty;
else
{
	int y = top[6]; //y holds the index of the element to be popped
	int x = arr[y]; //the element popped out is taken in x.
	top[6] = next[y]; //making top[6] point at the new top of 6th stack
	next[y] = free; //since arr[y] is now free so we are linking it to the stack of 
	//empty elements
	free = y; //free is updates to point at the first empty node.
}

//the elements of free stack are not necessarily in order. it is possible that
//first element is index 6, then next element is index 3 and then next element is 
//index 10 and so on. 
//it could be in any order. its just that the elements will point to each other in
//next array so it can act like a stack.


//Although we are using more space by using two extra arrays but:
//firstly, this method avoids space wastage
//secondly, it may not make much sense for integer arrays but for other types of arrays
//for stacks of employees, students, etc. where each item is of hundreds of byte, there 
//extra space used is very less as we are only using two integer arrays(top and next).
//but are saving a lot of space by using a efficient method to implement K stacks
//in the same array.



//Push and Pop are done in O(1) time and space complexity
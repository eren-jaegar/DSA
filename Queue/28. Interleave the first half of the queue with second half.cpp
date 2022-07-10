//Approach - 1
//let size of queue be n.
//pop out the first half elements into an array.
//run a loop that runs for n/2 times.
//in the loop:
//first enqueue the element from array and then enqueue the front element and then
//dequeue the front element.
//this process will interleave the first half of the queue with the second half.

//ex: 1,2,3,4
//elements in array: 1,2
//elements in queue: 3,4
//run the loop:
//first enqueue the element from array, list becomes: 3,4,1
//then enqueue the front element, list becomes: 3,4,1,3
//dequeue the front element. list becomes: 4,1,3
//first iteration of loop ends and second iteration starts: 
//enqueue the element from array queue becomes: 4,1,3,2
//then enqueue the front element, list becomes: 4,1,3,2,4
//dequeue the front element. list becomes: 1,3,2,4
//loop ends
//list has been interleaved.

//Time Complexity: O(N)
//Space Complexity: O(N)



//Approach - 2
//in the question, we are only allowed to use one stack as in auxillary space
//so we do the same process with a few changes
//for interleaving, we need to pop out the first half elements and while inserting
//we need to insert them in the same order in which they were popped out.

//so, we first pop out the first half elements from the queue and push them into stack.
//now, if we access these elements from the stack, they will be in reverse order but 
//we need them in the same order in which they were inserted. So, what we do is
//we pop the elments from stack and enqueue them in the queue.
//now, if we push these elments into the stack again then we will be able to access
//them in the desired order.
//in order to push them in back into the stack, we first remove the enqueue and 
//dequeue the first half elements from list(originally these were the second half
//elements.)
//now, we again push the first half elements back into the stack.
//now, we can access them in desired order.
//now run a loop, while(!stack.empty())
//first enqueue the top element from the stack into the queue and then pop the top
//element of stack
//now, enqueue the front element of queue into the queue and then dequeue it.
//After loop ends, we will have the interleaved queue.

//Time Complexity: O(N)
//Space Complexity: O(N)

void interleave(queue <int> &s)
{
	stack <int> s;
	int n = queue.size()/2;
	for(int i=0; i<n; i++)
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	for(int i=0; i<n; i++)
	{
		q.push(q.front());
		q.pop();
	}
	for(int i=0; i<n; i++)
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}



//Approach - 3
//using two stacks.
//push first half elements into stack1 and other half into stack2
//while(!stack1.empty())
//push the element first from stack1 into q and then from stack2 into q

//after the loop, reverse the queue by pushing all the elements into stack1 and then
//pushing them back into the queue.

//Time Complexity: O(N)
//Space Complexity: O(N)
//NOTE: we can make either push costly(O(N) time complexity) and pop efficient(O(1)
//time comlpexity) or we can do vice versa. Here I have made push costly.

//Approach - 1
//to push element into stack. first enqueue all the elements of queue1 into queue2 and
//dequeue them from queue1, then enqueue the element to be pushed into queue1. Now
//enqueue all the elements of queue2 into queue1 and dequeue them from queue2.

//for poppig just if queue1 is empty then return -1 else return the front element
//of queue1 and then dequeue the first element.

//Time Complexity: O(N) for push, O(1) for pop
//Space Complexity: O(1) the 2 queues use space but the functions themselves don't
//need any extra space.

void QueueStack :: push(int x)
{
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int x = -1;
    if(q1.empty())
        return x;
    x = q1.front();
    q1.pop();
    return x;
}



//Approach - 2
//while pushing, we enqueue the element to be pushed into queue2 and then, we enqueue
//all the elements from queue1 into queue2 while qequeuing them from queue1.
//now, we swap the names of queue1 and queue2.
//This would have been more efficient then approach 1 if we were passing the queues
//by address as then, only the address contained by pointers would have to be exchanged
//but now, i think it swaps all the elements one by one.



//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int x = -1;
    if(q1.empty())
        return x;
    x = q1.front();
    q1.pop();
    return x;
}



//NOTE: we can also implement stack using only one queue. to make push costly,
//before pushing an element, take the size of q(say a). now push the element.
//now dequeue all other elements one by one and enqueue them.
//for popping just take the front element and pop it.

//it can be done by making popping costly and pushing efficient too.
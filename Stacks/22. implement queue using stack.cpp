//Approach - 1
//make push function costly and pop function efficient.
//while s1 is not empty, push all its elements to s2, then push the element to be pushed
//into s1 and then while s2 is not empty, push all the elements into s1.
//for popping, just take the top element of s1.

//Time Comlexity: O(N) for pushing and O(1) for popping
//Space Complexity: O(1) two stack are used but the functions themselves dont use 
//any extra space.

void StackQueue :: push(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    int x = -1;
    if(s1.empty())
        return x;
    else
    {
        x = s1.top();
        s1.pop();
        return x;
    }
}



//Approach - 2
//making the push function efficient and pop function costly
//for pushing, just push the element in s1.
//for popping: if both the stacks s1 and s2 are empty, then return -1 as there are,
//no elements.
//else if only stack s2 is empty, then push all the elements from stack s1 into s2
//and then return the top element of s2.
//else if stack s2 is also not empty, then just return the top element of s2.

//this method is better than approach-1 as in approach-1 enqueue requires shifting
//of elements from s1 to s2 and then back to s1.
//but in approach-2, in dequeue, elements are shifted from s1 to s2 and that too only
//when s2 is empty, so the amortized complexity of the dequeue operation becomes 
//theta(1)

//Time Complexity: O(1) for pushing and theta(1) is amortized complexity for popping
//Space Complexity: O(1) two stack are used but the functions themselves dont use 
//any extra space.

void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty() && s2.empty())
        return -1;
    else if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    else
    {
        int x = s2.top();
        s2.pop();
        return x;
    }
}



//NOTE: queue can also be implemented using a single user defined stack. this can be 
//done using recursion. we hold the elements of stack in the recursion stack and then
//do out popping or pushing.
//same here, either popping or pushing will be costly, other will be efficient.

//Time Complexity: O(1) and O(N)
//Space Complexity: O(1) and O(N) //O(N) for the one which uses recursion and is costly.
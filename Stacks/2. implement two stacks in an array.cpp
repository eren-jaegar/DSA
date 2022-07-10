//These are normal push and pop functions. The stack was already implemented in the
//driver code.

//Time Complexity: O(1)
//Space Complexity: O(1) the push and pop functions dont require any additional space,
//it is the stack itself that requires an array to be implemented.

void twoStacks :: push1(int x)
{
    top1++;
    arr[top1] = x;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    top2--;
    arr[top2] = x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    int x = -1;
    if(top1 == -1)
        return x;
    x = arr[top1];
    top1--;
    return x;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 == size)
        return -1;
    int x = arr[top2];
    top2++;
    return x;
}



//NOTE: we can also implement two stacks in an array by implementing one stack from
//0 to n\2 and other from n/2+1 to n-1.
//This method is inefficient though, as there may be space available in one stack yet
//the other stack may overflow.

//So, the most efficient way to implement two stacks is to start them from the two
//extremes. one from 0 and other from n-1.
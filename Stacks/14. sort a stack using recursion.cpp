//Approach - 1
//call a recursive function to pop out all the elements from the stack and store them
//in the recursive stack.
//while returning this function calls another function which inserts elements in the 
//stack in sorted manner.
//the other function(say function2) is also a recursive function.
//it recursively calls itself and pops the top element of the stack until the top
//element is no longer greater than the element for which the functions1 has called
//it.
//after that function2 pushes the element for which it was called and then starts
//returning and pushes all the elements that it had popped out.

//Time Complexity: O(N^2)
//Space Complexity: O(N) for recursive stack

void arrangesort(stack <int> &s, int a)
{
    if(s.empty() || s.top()<=a)
    {
        s.push(a);
    }
    else
    {
        int b = s.top();
        s.pop();
        arrangesort(s,a);
        s.push(b);
    }
}

void SortedStack :: sort()
{
   
   if(!s.empty())
   {
       int a = s.top();
       s.pop();
       sort();
       arrangesort(s,a);
   }
   
}



//Approach - 2
//just like above our functon first calls itself recursively and pops out all the
//elements one by one and then while returning,
//in the above method, instead of using recursion to insert the elements in sorted
//manner, we create a temporary stack and pop out the elements from out main stack into
//it till the top element is greater than the element to be inserted.
//then we push the element to be inserted and then push all the elements that were
//popped out into temp back into the main stack.

//Time Complexity: O(N^2)
//Space Complexity: O(N) both recursion and temporary stack require memory.

void arrangesort(stack <int> &s)
{
    if(s.empty())
        return;
    int a = s.top();
    s.pop();
    arrangesort(s);
    
    stack <int> temp;
    while(!s.empty() && s.top()>a)
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(a);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}


void SortedStack :: sort()
{
   arrangesort(s);
}



//Approach - 3
//just use stl sort.

//Time Complexity: O(NlogN)
//Space Complexity: O(1) //O(N) if you consider space used by the sort



//If you have to do without using recursion and stl sort then,
//link to article: https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
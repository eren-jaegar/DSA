//since we don't have to use any other data structure so, we dont have anything to hold
//the elements of stack while we pop them out to insert the required element in the end.
//So, we use a recursive function.
//it first pops the elements and then calls itself.
//this goes in until the stack is empty and then it inserts the required element at
//the bottom and then while returning it pushes back all the elements that were popped 
//out.
//it holds all the elements in the recursion stack so, we dont have to use any other
//data structure.

//Time Complexity: O(N)
//Space Complexity: O(N) space used by recursion stack

void insert_at_bottom(stack <int> &s,int x)
{
	if(s.empty())
		s.push(x);
	else
	{
		int a = s.top();
		s.pop();
		insert_at_bottom(s,x);
		s.push(a);
	}
}
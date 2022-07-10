//Approach - 1
//one way to do it is to go through all the elements of the stack by popping them and
//finding the minimum value. But this destroys the stack as these values will now be
//lost.

//Time Complexity: O(N)
//Space Complexity: O(1)

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


void push(stack<int>& s, int a){
	
	s.push(a);
	
}


bool isFull(stack<int>& s,int n){
	
	if(s.size() == n)
	    return true;
    return false;
	
}

bool isEmpty(stack<int>& s){
	
	return s.empty();
}

int pop(stack<int>& s){
	
	int x = s.top();
	s.pop();
	return x;
}

int getMin(stack<int>& s){
	
	int x = s.top();
	while(!s.empty())
	{
	    x = min(x,s.top());
	    s.pop();
	}
	return x;
	
}

//NOTE: This method is not good at all because it destroys the stack which means we 
//can only use getmin() once before losing all the numbers.



//Approach - 2
//What we can do is to store the minimum element found till now in another stack.
//while pushing if the element being pushed is equal to or smaller than the current 
//minimum element then, push it into the minimum stack. while popping, if the element
//being popped is equal to top element of minimum stack then pop the top element of 
//minimum stack as well.
//This way we can keep track of the minimum element in stack.
//At anytime the minimum element in stack will be the top element in the minimum stack.

//Time Complexity: O(1)
//Space Complexity: O(N) for worst case when the elements are pushed in non-increasing
//order, for other cases it could be quite less



//Approach - 3
//we take a dummy value d. and maintain a variable that stores the minimum value found
//till now.
//while inserting any value say x, insert it as x*d+min.
//so while popping it we recover it by (x*d+min)/d.
//while pushing elements we can update min by simply comparing the element being
//pushed to the current minimum element(stored in min)
//while popping we can update min by taking the new top element after the current top
//element has been popped and then taking its mod with d.

//Time Complexity: O(1)
//Space Complexity: O(1)

//Choose d carefully, d should be choosen as such so that it is always greater than the
//current min element. this can be done by taking d as x+1 where x is the first element
//to be pushed in the stack. if d ever gets smaller then min then this solution will 
//give wrong results.

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int minn = -1;
int d = 1;

void push(stack<int>& s, int a){
    
	if(s.empty())
	{
	    minn = a;
	    d = a+1;
	    s.push(a*d+minn);
	}
	else
	{
	    minn = min(minn,a);
	    s.push(a*d+minn);
	}
}


bool isFull(stack<int>& s,int n){
	
	if(s.size() == n)
	    return true;
    return false;
	
}

bool isEmpty(stack<int>& s){
	
	return s.empty();
}

int pop(stack<int>& s){
	
// 	if(isEmpty(s))  //didnt have to check because driver code already takes care of it
// 	    return -1;
	
	int x = s.top();
	x = (x/d);
	s.pop();
	if(!s.empty())
	    minn = (s.top()%d);
	else 
	    minn = -1;
	return x;
}

int getMin(stack<int>& s){
	
	return minn;
	
}
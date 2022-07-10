//Approach - 1
//call recursive function and pop out the elements one by one. while popping them out,
//save them in a vector.
//Now, while returning push the elements from the beginning of vector into the stack
//one by one.
//the stack is reversed.

//Time Complexity: O(N)
//Space Complexity: O(N) //recursive stack and vector use space


//NOTE: Here we have not returned the reversed stack but have returned the vector
//because that's what the question asked but we could have returned the stack as well.

class Solution{
public:

    void reverseStack(stack <int> &st, vector <int> &ans, int &ii)
    {
        
        if(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            reverseStack(st,ans,ii);
            st.push(ans[ii]);
            ii++;
        }
    }
    
    vector<int> Reverse(stack<int> St){
        
        int ii=0;
        vector <int> ans;
        reverseStack(St,ans,ii);
        return ans;
        
    }



//Approach - 2
//In case we do not want to use any space other than the recursive stack, then what
//we can do is to call a recursive function which pops all the elements of the stack
//and stores them in recursive stack. and while returning it pushes those elements to
//the bottom of the stack. for pushing elements to the bottom of the stack, we will
//have to write a new function as dicussed in previous question.

//Time Complexity: O(N^2)
//Space Complexity: O(N) //because the recursive stack of push_to_bottom is created 
//and then deleted before returning to previous call of reverse function(the function
//which pops the elements initially and stores them in the recursive stack)

//link for this approach: https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/ 
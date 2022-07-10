//Approach - 1
//Brute force approach is to check if each substring is balanced or not.
//if it is balanced and its length is more than the length of the current maximum
//length of balanced substring then, update the current maximum length of balanced
//substring.
//we run two nested loops in its implementation.

//Time Complexity: O(N^2)
//Space Complexity: O(1)



//Approach - 2
//we iterate through the entire string.
//for ( increase count and for ) decrease count.
//cases for when we encounter ):
//if count<0 i.e. ) are more than (, then string cant be valid and hence take max of
//number of pairs and result in result.
//reset the pairs and count to 0.
//else if count == 0, then take max of pairs and result in result, and do pair++.
//else if count>0 then just do pair++.


//after this, iterate in reverse order from end to beginning with conditions for ( and 
//) swapped.


//consider this case: ()())()()(()()(), if we don't iterate in reverse and only
//iterate in forward direction then, it will give no. of pairs as 2 but the answer
//should be no. of pairs = 3.

//answer is ans*2 becuse we have counted pairs and length will be double of pairs.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
  public:
    int findMaxLen(string s) {
        
        int ans = 0;
        int pair = 0;
        int count = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
                count++;
            else
            {
                count--;
                if(count < 0)
                {
                    ans = max(ans,pair);
                    pair = 0;
                    count = 0;
                }
                else if(count == 0)
                {
                    pair++;
                    ans = max(ans,pair);
                }
                else
                    pair++;
            }
        }
        
        pair = 0;
        count = 0;
        
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == ')')
                count++;
            else
            {
                count--;
                if(count < 0)
                {
                    ans = max(ans,pair);
                    pair = 0;
                    count = 0;
                }
                else if(count == 0)
                {
                    pair++;
                    ans = max(ans,pair);
                }
                else
                    pair++;
            }
        }
        
        return ans*2;
        
    }
};



//Approach - 2
//we create a stack, and push -1 in it.
//if we encounter (, then we push its index into the stack
//if we encounter ), then we pop out an element from stack(generally popped out
//element is '(' ).
//after popping out, if the stack is not empty, the top element is index of the last
//unclosed '(' or -1. subtract top element the current index. this will give the 
//length of the longest balanced substring, take its max with ans and store it in ans.
//if the stack is empty, then that means ')' are more than '(', so just push the 
//current index i.e., index of current ')' as now we will check the length of
//balanced substring from this point.


//Time Complexity: O(N)
//Space Complexity: O(N)


class Solution {
  public:
    int findMaxLen(string s) {
        
        stack <int> nums;
        nums.push(-1);
        int ans = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
                nums.push(i);
            else
            {
                nums.pop();
                if(!nums.empty())
                {
                    ans = max(ans,i-nums.top());
                }
                else
                    nums.push(i);
            }
        }
        return ans;
        
    }
}; 
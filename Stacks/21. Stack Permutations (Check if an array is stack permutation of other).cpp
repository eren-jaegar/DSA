//Approach - 1
//make a stack.
//to iterate thorugh array b, initialize an int j=0
//iterate through all the elements for array a.
//while iterating, if the stack is not empty and the top element of the stack matches
//the j element of array b then pop the top element and do j++.
//else push the i element of array a into stack and do i++.
//after the loop is over, if the stack is empty that means all the elements matched 
//to the elements of array b and were popped out and hence, b is a stack permutation 
//of a.
//else if the stack is not empty then b is not a stack permutation of a.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack <int> nums;
        int j=0;
        for(int i=0; i<=N;)
        {
            if(!nums.empty() && nums.top() == B[j])
            {
                nums.pop();
                j++;
            }
            else
            {
                if(i == N)
                    break;
                nums.push(A[i]);
                i++;
            }
        }
        if(nums.empty())
            return 1;
        return 0;
        
    }
};



//same solution, different implementation

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack <int> nums;
        int j=0;
        for(int i=0; i<N; i++)
        {
            nums.push(A[i]);
            while(!nums.empty() && nums.top() == B[j])
            {
                nums.pop();
                j++;
            }
        }
        if(nums.empty())
            return 1;
        return 0;
        
    }
};
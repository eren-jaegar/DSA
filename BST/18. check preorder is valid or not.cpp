//Link to question: https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1/#


/*
Approach - 1
we follow the same process that we do for constructing a tree from its preorder traversal.
in the end, if we have iterated through the entire array then, it is a valif preorder 
traversal else it will not be a valid preorder traversal.

if we do it by following the min and max approach then, if the preorder is not valid
then we will enciunter a element which will not fit in any rnage and eventually no more
calls will be made and the function will return without ever going completely through
the entire preorder.

Time Complexity: O(N)
Space Complexity: O(height) */

//NOTE: this solution gets runtime error on one of the test cases but when run on leetcode,
//it throws no error for that testcase. still it might be possible that there is some 
//error in this method.

class Solution {
  public:
  
    void check(int* arr, int &i, int size, int min, int max)
    {
        if(min > max)
            return;
        if(i >= size)
            return;
        if(arr[i]>=min && arr[i]<=max)
        {
            int x = arr[i];
            i++;
            check(arr, i, size, min, x-1);
            check(arr, i, size, x+1, max);
        }
    }
  
    int canRepresentBST(int arr[], int N) {
        
        int i = 0;
        check(arr, i, N, INT_MIN, INT_MAX);
        if(i >= N)
            return 1;
        return 0;
    }
};



/*
Approach - 2
we can use stack. once we have encountered a element greater than the current element then
it means that we are in the right of the current element in inorder traversal so now, if we
encounter a smaller element then, it means that the given preorder is not valid.

we use stack for its implementation.

Time Complexity: O(N)
Space Complexity: O(N) */

//NOTE: this Solution gets accepted.

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        
        int *pre = arr;
        int n = N;
        stack <int> nums;
        int root = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(pre[i] < root)
                return 0;
            while(!nums.empty() && nums.top() < pre[i])
            {
                root = nums.top();
                nums.pop();
            }
            nums.push(pre[i]);
        }
        return 1;
        
    }
};
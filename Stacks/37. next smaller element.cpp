//Link to question: https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/
//Link to article: https://www.geeksforgeeks.org/next-smaller-element/



//Approach - 1
//brute force approach
//scan through the array for every element and find the first smaller number. if not found
//then its -1.

//Time Complexity: O(N^2)
//Space Complexity: O(1)



//Approach - 2
//create a stack
//start iterating through all the elements.
//while the stack is not empty and the element at the top index is greater than the
//current element then, we pop it and the current element is the next smaller element for
//the popped element.
//push the index of the current element in the stack.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector <int> ans(n);
        stack <int> nums;
        for(int i=0; i<n; i++)
        {
            while(!nums.empty() && arr[nums.top()]>arr[i])
            {
                ans[nums.top()] = arr[i];
                nums.pop();
            }
            nums.push(i);
        }
        while(!nums.empty())
        {
            ans[nums.top()] = -1;
            nums.pop();
        }
        return ans;
    } 
};



//NOTE: There are other methods using the segment tree but they have a worse time complexity
//than approach-2.
//refer the article whose link has been posted at the top.
//Brute force approach is to use two nested loops and scan through entire vector for
//each element until you find a number greater than the number pointed by outside loop

//Time Complexity: O(N^2)
//Space Complexity: O(1) make changes in the same given vector



//Approach - 1
//start itearting the given array from beginning.
//if the stack is empty(true for only first element), push the index of the current 
//element into the stack.
//else if the stack is not empty, then for the current element, check the element
//whose index is at top of stack. if that element is smaller then the current element
//then the current element is the next greater element for that element.
//So, go to the index on top of stack in asn vector and make its value equal to current 
//element.
//Now, pop the topmost index and check for the next index(while loop is used for this)
//after coming out of while loop, push the index of the current element in stack.
//after we are done iterating thorugh all the elements, put -1 in the elements of ans
//vector, whose index are still present in the stack. These elements do not have any
//next greater element.

//NOTE: The stack only contains the index of those elements whose next greater element
//hasn't been found yet.

//Time Complexity: O(N) //every element is operated on twice, once while pushing and 
//once while popping. accessing through top() is ignored because it is very random.
//Space Complexity: O(N)

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector <long long> ans(n);
        stack <long long> nums;
        for(int i=0; i<n; i++)
        {
            if(nums.empty())
                nums.push(i);
            else
            {
                while(!nums.empty() && arr[i] > arr[nums.top()])
                {
                    ans[nums.top()] = arr[i];
                    nums.pop();
                }
                nums.push(i);
            }
        }
        while(!nums.empty())
        {
            ans[nums.top()] = -1;
            nums.pop();
        }
        return ans;
        
    }
};



//Instead of using ans, we can make changes in arr only.

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack <long long> nums;
        for(int i=0; i<n; i++)
        {
            if(nums.empty())
                nums.push(i);
            else
            {
                while(!nums.empty() && arr[i] > arr[nums.top()])
                {
                    arr[nums.top()] = arr[i];
                    nums.pop();
                }
                nums.push(i);
            }
        }
        while(!nums.empty())
        {
            arr[nums.top()] = -1;
            nums.pop();
        }
        return arr;
        
    }
};



//Approach - 2
//We iterate from the rightmost element.
//if the stack is empty push the element in it
//in stack we only store the elements which are greater than the current element.

//Time Complexity: O(N)
//Space Complexity: O(N)

//easy to understand, thoda sochlo samjh aa jaaega

//LINK-1: https://www.geeksforgeeks.org/next-greater-element/
//LINK-2: https://www.geeksforgeeks.org/next-greater-element-in-same-order-as-input/

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack <long long> nums;
        long long temp;
        
        for(int i=n-1; i>=0; i--)
        {
            while(!nums.empty() && arr[i] > nums.top())
                nums.pop();
            
            temp = arr[i];
            
            if(nums.empty())
                arr[i] = -1;
            else
                arr[i] = nums.top();
            nums.push(temp);
        }
        
        return arr;
    }
};
//Approach - 1
//brute force spproach is to scan elements for every element.
//use nested for loops.
//the first inner loop starts from the current element and moves right till we encounter
//the end of array or the first element that is smaller than the current element.
//similarly second inner loop starts from current element and moves left till we
//encounter the start of array or the first element that is smaller than the current 
//element.
//now we know the size of the rectangle for the current element.
//find the maximum of all such areas for all the elements.

//Time Complexity: O(N^2)
//Space Complexity: O(1)

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        
        long long int count1 = 0;
        long long int count2 = 0;
        long long int area = 0;
        for(int i=0; i<n; i++)
        {
            count1 = 0;
            count2 = 0;
            for(int j=i; j<n; j++)
            {
                if(arr[j]>= arr[i])
                    count1++;
                else
                    break;
            }
            for(int j=i-1; j>=0; j--)
            {
                if(arr[j]>=arr[i])
                    count2++;
                else 
                    break;
            }
            area = max(area,arr[i]*(count1+count2));
        }
        return area;
    }
};



//Approach - 2

//for largest rectangle for every bar, we need the indexes of the first element 
//smaller then the bar on its left and right. then we can subtract them to find 
//the width of rectangle and the height of the rectangle will be the height of the 
//current bar.

//we create a stack. we will store indexes of elements in the stack.
//start iterating through the elements.
//if the element at stack.top() index is smaller than the current element than
//push the current element.
//if the elment at stack.top() index is greater than equal to the current element
//then the index of the right smaller element is given by the current index and the 
//index of the left smaller element is given by the next index in stack.
//take the difference of two indexes and multiply by y to find the area of the rectangle
//for that element.
//in case the stack only had one element then that means it is the smallest element till
//the current index so its left index can be considered as -1(in calculation we only
//require current index)

//after the loop is over we do the same process on the remaining elements in stack.
//we do the procedure that we did if the element in stack was greater or equal to the 
//current element.

//Time Complexity: O(N)
//Space Complexity: O(N)


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack <long long int> nums;
        long long int x,y;
        long long int ans = 0;
        long long int area;
        for(int i=0; i<n; i++)
        {
            if(nums.empty() || arr[nums.top()]<arr[i])
            {
                nums.push(i);
            }
            else
            {
                while(!nums.empty() && arr[nums.top()] >= arr[i])
                {
                   y = arr[nums.top()];
                   nums.pop();
                   if(!nums.empty())
                   {
                       x = nums.top();
                       area = (i-x-1)*y;
                   }
                   else
                   {
                       area = i*y;
                   }
                   ans = max(ans,area);
                }
                nums.push(i);
            }
        }
        while(!nums.empty())
        {
           y = arr[nums.top()];
           nums.pop();
           if(!nums.empty())
           {
               x = nums.top();
               area = (n-x-1)*y;
           }
           else
           {
               area = n*y;
           }
           ans = max(ans,area);
        }
        return ans;
    }
};



//Approach - 3
//there's a O(NlogN) solution for this, using segment tree.

//Approach - 1
//brute force approach
//run two nested for loop and find the maximum element in all the subarrays.

//Time Complexity: O(N*K)
//Space Complexity: O(1)



//Approach - 2
//create a deque
//consider the case for finding maximum element in the all the subarrays of size k.
//we first iterate the first k elements and push_back them in the deque.
//while pushing, if the deque is empty then push_back them in the deque.
//else if the deque is not empty then while the last element of deque is smaller than
//the current element, we pop_back it. when the last element is no longer smaller than
//the current element then we push_back the current element.
//after this, we follow the sliding window approach.
//we start iterating from kth element. for every subarray the front element is the
//maximum element in that subarray.
//while moving forward if the front element goes out of bounds of the subarray then
//pop_front it. and to push the current element, follow the same procedure, i.e.,
//check if the deque is empty, it is then push else while the last element is smaller 
//than the current element, we pop_back it and then push the current element.

//for minimum element we, follow the procedure as above, the only difference is that
//instead of checking whether the last element is smaller than the current element or
//not, we check if the last element is greater than the current element or not.

//elements are stored in non-increasing order in maximum element in deque.
//elements are stored in non-decreasing order in minimum element in deque.

//the front element of maximum element deque always contains the maximum element for
//that subarray.
//the front element of minimum element deque always contains the minimum element for
//that subarray.


//Time Complexity: O(N)
//Space Complexity: O(K) //we can store a maximum of k elements only in either of the 
//array.


//solution only for finding max is as follows:
//it can be modified so that in the same loops, we can find the minimum elements
//as well simultaneously.


class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        deque <int> maxx;
        vector <int> ans;
        
        int i=0;
        for(i=0; i<k; i++)
        {
            if(maxx.empty())
                maxx.push_back(i);
            else
            {
                while(!maxx.empty() && arr[maxx.back()]<=arr[i])
                    maxx.pop_back();
                maxx.push_back(i);
            }
        }
        
        for(; i<=n; i++)
        {
            ans.push_back(arr[maxx.front()]);
            
            if(i==n)
                break;
                
            if(maxx.front() == i-k)
                maxx.pop_front();
                
            while(!maxx.empty() && arr[maxx.back()]<=arr[i])
                maxx.pop_back();
            
            maxx.push_back(i);
        }
        return ans;
    }
};


//link to the question where we have to find only the maximum: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/



//there's another approach using stacks but for them we have to define a new struct
//is of same space and time complexity as above.

//link: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

//its method-4 is for stack based approach


//NOTE: there's another approach discussed in the above link's method-5
//it uses max heap.
//see it
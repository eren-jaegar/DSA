/*
Approach - 1

it is clear that some ropes will be added to cost multiple times as after merging their
resultant rope is also merged.
its obvious that to reduce the cost, we first need to merge smaller ropes.
so we create a priority queue and sort it so that smallest element is on top.
insert all the elements in it.
now, we take the top two elements as they will be the smallest.
add them and add their sum to total cost. push their sum back into the queue.
do this until there is only 1 element left in the queue.
return the total cost.

Time Complexity: O(NlogN) //insertion of n elements in queue takes NlogN time, also
we will make N-1 merge so total insertions will be 2*N-1. hence NlogN time complexity.

Space Complexity: O(N) */



class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        long long int ans = 0;
        priority_queue <long long int, vector<long long int>, greater<long long int> > nums;
        for(int i=0; i<n; i++)
            nums.push(arr[i]);
        
        long long int a,b;
        while(nums.size() != 1)
        {
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            ans += a+b;
            nums.push(a+b);
        }
        return ans;
    }
};


//NOTE: see its minheap solution.
//ask about disjoint set solution.


//NOTE: Approach-1 gives tle but approach-2 gets accepted even though either both should
//be accepted or both should give tle.



/*
Approach - 1
sort the array in descending order of the profit.
create an unordered map to keep track of which slot has been filled and which slot is
empty.
run two nested loops.
the outer loops iterates throught the given array.
we start searching for a slot for the current element. if we find a slot then we make slot 
as true to indicate that slot is taken and we increase the count and add its profit.
for finding the slot, we start iterating backwards from the current element's deadline
towards 1. that is because in this range, if any slot is empty then the element can be
picked up. though we try to assign the highest possible slot so that the lower slots remain 
empty for the elements with lower deadlines.

Time Complexity: O(N*maximum deadline)
Space Complexity: O(N) */

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr+n, [](Job a, Job b)
        {
            return a.profit > b.profit;
        });
        unordered_map <int,bool> done;
        int maxtime = 0;
        int profit = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            maxtime = arr[i].dead;
            for(int j=maxtime; j>0; j--)
            {
                if(done[j] == false)
                {
                    profit += arr[i].profit;
                    count++;
                    done[j] = true;
                    break;
                }
            }
        }
        vector <int> ans = {count, profit};
        return ans;
    } 
};



/*
Approach - 2 
//different application of the same approach

//Time Complexity: O(min(N*N,N*maximum deadline)) */


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr+n, [](Job a, Job b)
        {
            return a.profit > b.profit;
        });
        bool done[n];
        for(int i=0; i<n; i++)
            done[i] = false;
        int maxtime = 0;
        int profit = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            maxtime = arr[i].dead;
            for(int j=min(n,maxtime)-1; j>=0; j--)
            {
                if(done[j] == false)
                {
                    profit += arr[i].profit;
                    count++;
                    done[j] = true;
                    break;
                }
            }
        }
        vector <int> ans = {count, profit};
        return ans;
    } 
};



/*
Approach - 2
sort the array in decreasing order of deadline.
create a priority queue that stores the elements with profit as priority.
highest profit should be on top.
iterate through the array and find if slot is available by subtracting deadline of next
element from deadline of current element.
push the current element of in the queue.
as long as the slot is available keep popping out the elements from the queue.
these are elements that we have selected.

this works because if the slot is available then out of all the elements that can be
in that slot we are choosing those that have maximum profit.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

struct jobprofit
{
    bool operator()(Job a, Job b)
    {
        return a.profit < b.profit;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [](Job a, Job b){
            return a.dead > b.dead;
        });
        
        priority_queue <Job, vector<Job>, jobprofit> nums;
        
        int count = 0;
        int profit = 0;
        int slot = 0;
        for(int i=0; i<n; i++)
        {
            if(i == n-1)
                slot = arr[i].dead;
            else
            {
                slot = arr[i].dead - arr[i+1].dead;
            }
            nums.push(arr[i]);
            while(!nums.empty() && slot)
            {
                count++;
                profit += nums.top().profit;
                nums.pop();
                slot--;
            }
        }
        vector <int> ans = {count, profit};
        return ans;
    } 
};
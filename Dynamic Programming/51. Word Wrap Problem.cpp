/*
Approach - 1

create a recursive function.
create a dp which stores the minimum cost when ith element is stored in j space.

now, for every element if size available is equal to k then we are adding the element in
new line and we don't have a choice so we add it and call for the next element in remaining
space.
if size available is less than 1+size of current word then we return the remaining space's
square along with the cost of current word in new line(i.e., call for current word in new line).
if size is sufficient then we have two choices, either to take the word in current line or 
to put in the next line. call for both the scenarios and return the minimum.


Time Complexity: O(N^2)
Space Complexity: O(N^2) */


class Solution {
public:

    int solve(int index, int numsize, int size, int k, vector <int> &nums, vector <vector <int> > &dp)
    {
        if(index >= numsize)
            return 0;
        if(dp[index][size] != -1)
            return dp[index][size];
        if(size == k)
            return dp[index][size] = solve(index+1, numsize, size-nums[index], k, nums, dp);
        if(size < nums[index]+1)
            return dp[index][size] = size*size + solve(index, numsize, k, k, nums, dp);
        else
            return dp[index][size] = min(size*size + solve(index, numsize, k, k, nums, dp), solve(index+1, numsize, size-1-nums[index], k, nums, dp));
    }

    int solveWordWrap(vector<int>nums, int k) 
    {
        int n = nums.size();
        vector <vector <int> > dp(n, vector <int> (k+1, -1));
        return solve(0, n, k, k, nums, dp);
    } 
};



/*
Approach - 2

we create a dp that stores the minimum cost for if the current word is the first word that
we start with.
so, this wat we just have to find and return dp[0].

realize that dp[n-1]=0 as there is no cost for last element. so even if it is the only 
element there will be no cost for it.
now we run a loop from n-2 to 0. within it, we run a nested loop from i to n-1.
we start adding elements one by one. each time we calculate the cost.
when the calculated cost becomes less than the current cost then we update it in the dp.
when the length limit(k) is exceeded, we break the loop.

last[i] stores the last element in the line when we take i as the first element in that
line.
though it is not required for solution. it is only needed if we want to print the solution.


Time Complexity: O(N^2)
Space Complexity: O(N) */


class Solution {
public:

    int solve(vector <int> &nums, int k, int n)
    {
        int dp[n];
        int last[n];
        for(int i=0; i<n; i++)
            dp[i] = INT_MAX;
        dp[n-1] = 0;
        last[n-1] = n-1;
        int cost = 0;
        int current = 0;
        int i,j;
        for(i=n-2; i>=0; i--)
        {
            current = 0;
            for(j=i; j<n; j++)
            {
                current += nums[j];
                if(current > k)
                    break;
                if(j == n-1)
                    cost = 0;
                else
                    cost = (k-current)*(k-current) + dp[j+1];
                if(cost < dp[i])
                {
                    dp[i] = cost;
                    last[i] = j;
                }
                current++;
            }
        }
        return dp[0];
    }

    int solveWordWrap(vector<int>nums, int k) 
    {
        int n = nums.size();
        return solve(nums, k, n);
    } 
};
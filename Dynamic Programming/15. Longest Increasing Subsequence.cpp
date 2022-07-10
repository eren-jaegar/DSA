/*
Approach - 1
we can just sort the array and then find the longest common subsequence.


Time Complexity: O(N^2)
Space Complexity: O(N^2) */



/*
Approach - 2
for every element make a dp which stores the length of the longest increasing subsequence 
till the current element.
then for every element, iterate over the dp of previous elements. if the element being currently
iterated is smaller than the current element then tkae the value stored in its dp.
find the miximum dp. add 1 to it and store it in the dp of the current element.


Time Complexity: O(N^2)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n+1] = {0};
        dp[1] = 1;
        int maximum = 0;
        for(int i=2; i<=n; i++)
        {
            maximum = 0;
            for(int j=1; j<i; j++)
            {
                if(a[j-1] < a[i-1])
                    maximum = max(maximum,dp[j]);
            }
            dp[i] = 1+maximum;
        }
        maximum = 0;
        for(int i=1; i<=n; i++)
            maximum = max(maximum,dp[i]);
        return maximum;
    }
};



/*
Approach - 3
using patience sort.
see the article: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/


Time Complexity: O(NlogN)
Space Complexity: O(N) */


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector <int> nums(n,0);
        nums[0] = a[0];
        int length = 1;
        for(int i=1; i<n; i++)
        {
            if(a[i] < nums[0])
                nums[0] = a[i];
            else if(a[i] > nums[length-1])
            {
                nums[length] = a[i];
                length++;
            }
            else
            {
                auto it = lower_bound(nums.begin(), nums.begin()+length, a[i]);
                *it = a[i];
            }
        }
        return length;
    }
};
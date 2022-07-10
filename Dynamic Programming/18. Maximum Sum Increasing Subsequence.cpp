/*
Approach - 1

instead of storing the length of the longest increasing subsequence, we can store the
largest sum of the increasing subsequence.


Time Complexity: O(N^2)
Space Complexity: O(N) */


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{
	    int dp[n+1] = {0};
	    dp[1] = arr[0];
	    int sum = 0;
	    for(int i=2; i<=n; i++)
	    {
	        sum = 0;
	        for(int j=1; j<i; j++)
	        {
	            if(arr[j-1] < arr[i-1])
	                sum = max(sum,dp[j]);
	        }
	        dp[i] = arr[i-1]+sum;
	    }
	    sum = 0;
	    for(int i=1; i<=n; i++)
	        sum = max(sum,dp[i]);
	    return sum;
	}  
};
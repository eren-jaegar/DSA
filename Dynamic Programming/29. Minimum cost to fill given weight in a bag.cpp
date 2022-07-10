/*
Approach - 1
standard way.
initialize with 10e8 not with int_max else it overflows.


Time Complexity: O(N*W)
Space Complexity: O(N*W) */


class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
	    int w = W;
	    int n = N;
	    int dp[n+1][w+1];
	    memset(dp, 0, sizeof(dp));
	    for(int i=0; i<=w; i++)
	        dp[0][i] = 100000000;
	    for(int i=0; i<=n; i++)
	        dp[i][0] = 0;
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=1; j<=w; j++)
	        {
	            if(cost[i-1] == -1 || i > j)
	                dp[i][j] = dp[i-1][j];
	            else
	                dp[i][j] = min(dp[i-1][j], cost[i-1]+dp[i][j-i]);
	        }
	    }
	    if(dp[n][w] >= 100000000)
	        dp[n][w] = -1;
	    return dp[n][w];
	} 
};
/*
Approach - 1

usual way.

Time Complexity: O(N*M)
Space Complexity: O(N*M) */


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[n+1][W+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=W; j++)
            {
                if(wt[i-1] > j) //wt[i-1] because wt has 0 based indexing
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]); //val[i-1] because val has 0 based indexing
                }
            }
        }
        return dp[n][W];
    }
};
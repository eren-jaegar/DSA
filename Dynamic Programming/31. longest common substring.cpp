/*
Approach - 1

Time Complexity: O(N*M)
Space Complexity: O(N*M) */


class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(S1[i-1] == S2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
                ans = max(ans,dp[i][j]);
        }
        return ans;
    }
};
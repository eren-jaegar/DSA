/*
Approach - 1

usual method as taught in video.


Time Complexity: O(x*y)
Space Complexity: O(x*y) */


class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=x; i++)
        {
            for(int j=1; j<=y; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};
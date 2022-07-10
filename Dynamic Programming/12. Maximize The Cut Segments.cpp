/*
Approach - 1
focus on initialization.

since we want the maximum so we initiaize first row with int_min.
when you think about initializing the first row then it doesn't make much sense as the
problem is absurd. but we have to initialize it with something so we initialize it with 
int_min because we have to find maximum. incase we had to find minimum, i would have
initialized it with int_max.

Time Complexity: O(N) //(n+1)*4 actually
Space Complexity: O(N) //(n+1)*4 actually */


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[4][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n; i++)
            dp[0][i] = -1*10e8;
        
        int a;
        for(int i=1; i<=3; i++)
        {
            if(i==1)
                a=x;
            else if(i==2)
                a=y;
            else
                a=z;
            for(int j=1; j<=n; j++)
            {
                if(a>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j],1+dp[i][j-a]);
            }
        }
        if(dp[3][n] < 0)
            dp[3][n] = 0;
        return dp[3][n];
    }
};
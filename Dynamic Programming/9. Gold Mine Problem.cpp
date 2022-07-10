/*
Approach - 1
we create a dp that stores the maximum gold that we can get till the current cell.

then take the ans as the maximum that we can collect for the cells in the last column. 
this is because last column is where the miner will stop.

Time Complexity: O(N*M)
Space Complexity: O(N*M) */

class Solution{
public:

    
    int gold(vector <vector<int> >&M, vector <vector<int> >&dp, int n, int m, int i)
    {
        if(m==-1)
            return 0;
        if(dp[i][m] != -1)
            return dp[i][m];
        int a = gold(M, dp, n, m-1, i);
        int b = 0;
        int c = 0;
        if(i>0)
            b = gold(M, dp, n, m-1, i-1);
        if(i<n-1)
            c = gold(M, dp, n, m-1, i+1);
        dp[i][m] = M[i][m] + max(a,max(b,c));
        return dp[i][m];
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector <vector <int> > dp(n, vector <int> (m,-1));
        for(int i=0; i<n; i++)
        {
            ans = max(ans, gold(M, dp, n, m-1, i));
        }
        return ans;
    }
};



/*
Approach - 2
top down dp approach


Time Complexity: O(N*M)
Space Complexity: O(N*M) */


class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector <vector <int> > dp(n+2, vector <int> (m+1, 0));
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                dp[i][j] = M[i-1][j-1] + max(dp[i][j-1],max(dp[i-1][j-1],dp[i+1][j-1]));
            }
        }
        for(int i=1; i<=n; i++)
            ans = max(ans, dp[i][m]);
        return ans;
    }
};
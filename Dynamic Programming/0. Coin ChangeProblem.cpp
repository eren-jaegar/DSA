/*
Approach - 1

usual approach.

Time Complexity: O(M*N)
Space Complexity: O(M*N) */

class Solution {
  public:
    long long int count(int S[], int m, int n) {
        
        long long int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=m; i++)
            dp[i][0] = 1;
        for(long long int i=1; i<=m; i++)
        {
            for(long long int j=1; j<=n; j++)
            {
                if(S[i-1] > j) //S[i-1] because S has 0 based indexing
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-S[i-1]];
                }
            }
        }
        return dp[m][n];
    }
};



/*
Approach - 2

we iterate through all the elements and keep updating/adding the number of ways by which
we can get a certain amount of change using only the current element.

it requires use of a 1D array.

Time Complexity: O(N*M)
Space Complexity: O(N) */

class Solution {
  public:
    long long int count(int S[], int m, int n) {
        
        long long int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(long long int i=0; i<m; i++)
        {
            for(long long int j=S[i]; j<=n; j++)
            {
                dp[j] += dp[j-S[i]];
            }
        }
        return dp[n];
    }
};
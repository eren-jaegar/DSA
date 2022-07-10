/*
Approach - 1

we construct a matrix that stores the size of the biggest square that has its bottom most
and right most vertex at the current element of matrix.

if the element is 0 then dp[i][j] = 0
else if element is 1 then,
dp[i][j] = min(dp[i][j-1], dp[i-1][j-1], dp[i][j-1])+1


Time Complexity: O(N*M)
Space Complexity: O(N*M) */


class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int dp[n][m];
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = mat[i][j];
                    ans = max(ans,dp[i][j]);
                    continue;
                }
                if(mat[i][j] == 1)
                {
                    dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
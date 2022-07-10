/*
Approach - 1
create a dp which stores the maximum value that can be attained till a certian cell.

call the recursive function for every column in (N-1)th row and then take their maximum.
that will be the answer.


Time Complexity: O(N^2)
Space Complexity: O(N^2) */

//Note: It can be done in O(N) space as we only require information of previous row for 
//finding current row's data.


class Solution{
public:


    int solve(int row, int column, vector <vector <int> >&dp, vector<vector<int>>&matrix, int size)
    {
        if(row < 0)
            return 0;
        if(column < 0 || column>=size)
            return 0;
        if(dp[row][column] != -1)
            return dp[row][column];
        return dp[row][column] = matrix[row][column] + max({solve(row-1, column-1, dp, matrix, size),solve(row-1, column, dp, matrix, size),solve(row-1, column+1, dp, matrix, size)});
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector <vector <int> > dp(N, vector <int>(N,-1));
        int ans = 0;
        for(int i=0; i<N; i++)
            ans = max(ans,solve(N-1, i, dp, Matrix, N));
        return ans;
    }
};
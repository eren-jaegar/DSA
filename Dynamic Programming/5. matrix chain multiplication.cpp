/*
Approach - 1

usual method as taught.


Time Complexity: O(N^3)
Space Complexity: O(N^2) */


class Solution{
public:

    int multiply(int start, int end, vector <vector <int> >&dp, int *arr)
    {
        if(start >= end)
            return dp[start][end] = 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        int ans = INT_MAX;
        int temp = 0;
        for(int i=start; i<end; i++)
        {
            temp = multiply(start,i,dp,arr)+multiply(i+1,end,dp,arr)+arr[start-1]*arr[i]*arr[end];
            ans = min(ans,temp);
        }
        return dp[start][end] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector <vector <int> > dp(N, vector <int> (N,-1));
        return multiply(1,N-1,dp,arr);
    }
};
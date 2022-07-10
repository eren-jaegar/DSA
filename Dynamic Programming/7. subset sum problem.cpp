/*
Approach - 1

done as usual.

Time Complexity: O(N*sum)
Space Complexity: O(N*sum) */


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int n = N;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
        }
        if(sum%2 == 1)
            return 0;
        sum = sum/2;
        int dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[N][sum];
    }
};
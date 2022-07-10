/*
Approach - 1

just sort the array in decreasing order and start traversing the array.
if the sum of consecutive elements is less than k then take them and then move the pointer
by 2 places.
else don't take them and move the pointer by 1 place.


Time Complexity: O(NlogN)
Space Complexity: O(1) */


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        int n = N;
        int k = K;
        sort(arr, arr+n, greater <int>());
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]-arr[i+1] < k)
            {
                ans += arr[i]+arr[i+1];
                i++;
            }
        }
        return ans;
    }
};



/*
Approach - 2

dp solution


Time Complexity: O(N)
Space Complexity: (N) */


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        int n = N;
        int k = K;
        sort(arr, arr+n);
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=n; i++)
        {
            if(arr[i-1] - arr[i-2] < k)
            {
                dp[i] = max(dp[i-1],arr[i-1]+arr[i-2]+dp[i-2]);
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
};
//link to question: https://www.codingninjas.com/codestudio/problems/maximum-subsequence-sum-such-that-no-three-are-consecutive_1215007?leftPanelTab=1


/*
Approach - 1

our dp stores the maximum sum till the current number when the number is the first in the
pair and when it is the second in the pair.

we have two choices for every number either to take it or not.
if we take it and if it is the first number then call the for the next number as the second
number and and if we don't take the current number then call for the next number as the
first number.


if the current number is second number then if we take it then call for next to next number
as first number and if we don't take the current element then call for the next number as
the first number.


Time Complexity: O(N)
Space Complexity: O(N) */



int solve(vector <int> &a, int dp[][2], int n, int number)
{
    if(n<=0)
           return 0;
    if(dp[n][number] != -1)
           return dp[n][number];
    int temp = 0;
    if(number == 0)
    {
        temp = max(solve(a,dp,n-1,0), a[n-1]+solve(a,dp,n-1,1));
    }
    else
    {
        temp = max(solve(a,dp,n-1,0), a[n-1]+solve(a,dp,n-2,0));
    }
    return dp[n][number] = temp;
}

int maxSum(vector<int> &a, int n) 
{
    int dp[n+1][2];
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    return solve(a, dp, n, 0);
}



/*
Approach - 2

iterative approach


Time Complexity: O(N)
Space Complexity: O(N) */


int maxSum(vector<int> &a, int n) 
{
    int dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = a[0];
    dp[1][1] = a[0];
    for(int i=2; i<=n; i++)
    {
        dp[i][0] = max(dp[i-1][0], a[i-1]+dp[i-1][1]);
        dp[i][1] = max(dp[i-1][0], a[i-1]+dp[i-2][0]);
    }
    return max(dp[n][0], dp[n][1]);
}
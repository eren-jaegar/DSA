/*
Approach - 1

sort the array in increasing order of the second element.
then start from beginning and find the maximum length of chain for each element.


Time Complexity: O(N^2)
Space Complexity: O(N) */


bool compare(val a, val b)
{
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, compare);
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    int ans = 0;
    for(int i=2; i<=n; i++)
    {
        ans = 0;
        for(int j=1; j<i; j++)
        {
            if(p[i-1].first > p[j-1].second)
                ans = max(ans, dp[j]);
        }
        dp[i] = 1 + ans;
    }
    ans = 0;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[i]);
    return ans;
}



/*
Approach - 2

we could have done it in NlogN time if we do it like activity selection problem.

first element is the start time of activity and second element is the end time.


Time Complexity: O(NlogN)
Space Complexity: O(N) */



/*
Approach - 3
using recursion
/*
Approach - 1

do as taught.


Time Complexity: O(N*M)
Space Complexity: O(N*M) */


class Solution{
public:

    bool ispalindrome(string &s, int start, int end)
    {
        int i = start;
        int j = end;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }

    int solve(string &s, int start, int end, vector <vector <int> > &dp)
    {
        if(start==end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        if(ispalindrome(s, start, end))
            return dp[start][end] = 0;
        int temp = INT_MAX;
        for(int i=start; i<end; i++)
        {
            temp = min(temp, solve(s, start, i, dp)+solve(s, i+1, end, dp)+1);
        }
        return dp[start][end] = temp;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector <vector <int> > dp(n, vector<int> (n,-1));
        return solve(str, 0, n-1, dp);
    }
};
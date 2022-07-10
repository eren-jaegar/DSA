/*
Approach - 1
we can simply use MCM to find the answer.

Time Complexity: O(N^3)
Space Complexity: O(N^2) */

class Solution
{
public:


    int solve(string &a, int start, int end, unordered_map <string, int>&ump, vector <vector <int> > &dp)
    {
        if(dp[start][end] != -1)
            return dp[start][end];
        if(ump.find(a.substr(start, end-start+1)) != ump.end())
            return dp[start][end] = 1;
        int temp = 0;
        int ans = 0;
        for(int i=start; i<end; i++)
        {
            temp = solve(a, start, i, ump, dp) && solve(a, i+1, end, ump, dp);
            ans = max(ans,temp);
        }
        return dp[start][end] = ans;
    }

    int wordBreak(string A, vector<string> &B) {
        
        unordered_map <string, int> ump;
        for(int i=0; i<B.size(); i++)
            ump[B[i]]++;
        vector <vector <int> > dp(A.size(), vector <int> (A.size(), -1));
        return solve(A, 0, A.size()-1, ump, dp);
        
    }
};



/*
Approach - 2
realize that for the word to be broken up, there must be a prefix that is available in the
given string set.
so we try every possible way to break the string from the beginning, and check whether it 
is present in the given string set or not.

dp represents whether we can make a break at that point such that the string is present
in the given set.
if yes, then we can break it in such a way that till that point the string is breakable
into set of given strings.

Time Complexity: O(N^2)
Space Complexity: O(N) */


class Solution
{
public:

        bool present(vector <string>&b, string p)
    {
        for(int i=0; i<b.size(); i++)
        {
            if(b[i].compare(p) == 0)
                return true;
        }
        return false;
    }

    int solve(string &s, vector <string> &b)
    {
        int n = s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        string x;
        for(int i=1; i<=n; i++)
        {
            x = s.substr(0, i);
            if(dp[i]==0);
            {
                if(present(b, x))
                {
                    dp[i] = 1;
                }
            }
            if(dp[i] == 1)
            {
                if(i==n)
                    return 1;
                for(int j=i+1; j<=n; j++)
                {
                    x = s.substr(i, j-i);
                    if(dp[j]==0)
                    {
                        if(present(b, x))
                        {
                            dp[j] = 1;
                        }
                    }
                    if(j==n && dp[j]==1)
                        return 1;
                }
            }
        }
        return 0;
    }

    int wordBreak(string A, vector<string> &B) {
        
        return solve(A, B);
        
    }
};
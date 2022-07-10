/*
Approach - 1
we create a dp which stores the total number of palindromic subsequences between the current
two indexes.

the recursive relation is as follows:

if the characters at the current indexes are not same:
then, we call for f(start+1, end) + f(start, end-1). in this palindromic subsequences in
range start+1,end-1 are counted twice so, we subtract it once. finally we get:
f(start, end) = f(start+1, end) + f(start, end-1) + f(start+1, end-1).

if the characters at the current indexes are same:
then we call for f(start+1, end)+f(start, end-1) but we don't subtract f(start+1, end-1).
this is because all the palindromic subsequences in f(start+1, end-1) will also form a 
palindromic subsequence with the current elements. so we don't subtract it.
also add 1 as the current elements by themselves also form a palindromic subsequence.


Time Complexity: O(N*N)
Space Complexity: O(N*N) */


class Solution{
    public:
    /*You are required to complete below method */
    
    long long int solve(string &s, long long int start, long long int end, vector <vector <long long int> > &dp, long long int x)
    {
        long long int y;
        if(start == end)
            return y=1;
        if(start > end)
            return y=0;
        if(dp[start][end] != -1)
            return dp[start][end];
        if(s[start] == s[end])
            dp[start][end] = (((((solve(s, start, end-1, dp, x)%x)+(solve(s, start+1, end, dp, x)%x))%x)+1)%x);
        else
            dp[start][end] = (((((solve(s, start, end-1, dp, x)%x)+(solve(s, start+1, end, dp, x)%x))%x)-(solve(s, start+1, end-1, dp, x)%x))%x);
        return dp[start][end];
    }
    
    long long int  countPS(string str)
    {
        long long int x = 1000000007;
        long long int n = str.size();
        vector <vector <long long int> > dp(n, vector <long long int> (n,-1));
        return solve(str, 0, n-1, dp, x);
    }
     
};



/*
Approach - 2

iterative version

Time Complexity: O(N*N)
Space Complexity: O(N*N) */


class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        long long int n = str.size();
        long long int x = 1000000007;
        long long int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i == j)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if(str[i] == str[j])
                    dp[i][j] = (dp[i+1][j]%x + dp[i][j-1]%x + 1)%x;
                else
                    dp[i][j] = (dp[i+1][j]%x + dp[i][j-1]%x - dp[i+1][j-1]%x)%x;
            }
        }
        return dp[0][n-1];
    }
     
};


/*
don't know why but neither of the solution passes test case 102..!!
ask about it 
*/
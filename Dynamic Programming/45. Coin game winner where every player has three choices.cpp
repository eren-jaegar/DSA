/*
Approach - 1

we make an array and fill it with 1 and 0.
1 signifies that the player going first can win and 0 signifies that he cannot win.

now for i coins if i-1 || i-x || i-y coins result in losing then geek can win else he cannot.

Time Complexity: O(N)
Space Complexity: O(N) */


class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
	    int n = N;
	    int x = X;
	    int y = Y;
	    int dp[n+1];
	    memset(dp, 0, sizeof(dp));
	    dp[1] = 1;
	    for(int i=2; i<=n; i++)
	    {
	        if(dp[i-1] == 0)
	            dp[i] = 1;
	        else if(i-x>=0 && dp[i-x] == 0)
	            dp[i] = 1;
	        else if(i-y>=0 && dp[i-y] == 0)
	            dp[i] = 1;
	        else
	            dp[i] = 0;
	    }
	    return dp[n];
	}

};
/*
Approach - 1
call for all the choices for a given key and and add them to get the answer for that key.


Time Complexity: O(N)
Space Complexity: O(N) */

s Solution{


	public:
	
	long long int solve(int n, long long int dp[][10], int number)
	{
	    if(n <= 0)
	        return 0;
	    if(n == 1)
	        return 1;
	    if(dp[n][number] != -1)
	        return dp[n][number];
	    if(number == 1)
	        return dp[n][1] = solve(n-1, dp, 1) + solve(n-1, dp, 2) + solve(n-1, dp, 4); 
	    else if(number == 2)
	        return dp[n][2] = solve(n-1,dp,1)+solve(n-1,dp,2)+solve(n-1,dp,3)+solve(n-1,dp,5);
	    else if(number == 3)
	        return dp[n][3] = solve(n-1,dp,2)+solve(n-1,dp,3)+solve(n-1,dp,6);
	    else if(number == 4)
	        return dp[n][4] = solve(n-1,dp,1)+solve(n-1,dp,4)+solve(n-1,dp,5)+solve(n-1,dp,7);
	    else if(number==5)
	        return dp[n][5] = solve(n-1,dp,4)+solve(n-1,dp,2)+solve(n-1,dp,6)+solve(n-1,dp,8)+solve(n-1,dp,5);
	    else if(number==6)
	        return dp[n][6] = solve(n-1,dp,3)+solve(n-1,dp,6)+solve(n-1,dp,5)+solve(n-1,dp,9);
	    else if(number == 7)
	        return dp[n][7] = solve(n-1,dp,4)+solve(n-1,dp,7)+solve(n-1,dp,8);
	    else if(number==8)
	        return dp[n][8] = solve(n-1,dp,5)+solve(n-1,dp,7)+solve(n-1,dp,9)+solve(n-1,dp,0)+solve(n-1,dp,8);
	    else if(number == 9)
	        return dp[n][number] = solve(n-1,dp,6)+solve(n-1,dp,9)+solve(n-1,dp,8);
	    else
	        return dp[n][0] = solve(n-1,dp,8)+solve(n-1,dp,0);
	}
	
	
	long long getCount(int N)
	{
	    long long int dp[N+1][10];
	    memset(dp, -1, sizeof(dp));
	    long long int ans = 0;
	    for(int i=0; i<=9; i++)
	    {
	        ans += solve(N, dp, i);
	    }
	    return ans;
	}


};



/*
Approach - 2

since we only require data of previous row for the current row. So, we can optimize space
and make do with only two rows of length 10.
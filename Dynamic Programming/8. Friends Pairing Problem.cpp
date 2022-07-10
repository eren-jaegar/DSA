/*
Approach - 1

think of recursive function.
the recursive function for this case is:
f(n) = f(n-1) //incase nth element remains single + (n-1)*f(n-2) //incase we pair up nth element

we have n-1 choices to pair up the nth element hence we multiply by n-1.


Time Complexity: O(N)
Space Complexity: O(N) */


class Solution
{
public:
    int countFriendsPairings(int n) 
    {
        long long int x = 1000000007;
        long long int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = ((dp[i-1]%x) + (((i-1)%x)*(dp[i-2]%x))%x)%x;
        }
        return dp[n];
    }
};



/*
Approach - 2
it is like fibonacci so we can do it in O(1) space.


Time Complexity: O(N)
Space Complexity: O(1) */


class Solution
{
public:
    int countFriendsPairings(int n) 
    {
        if(n==0)
            return 1;
        if(n<3)
            return n;
        long long int a = 1;
        long long int b = 2;
        long long int c;
        long long int x = 1000000007;
        for(int i=3; i<=n; i++)
        {
            c = ((b%x) + (((i-1)%x)*(a%x))%x)%x;
            a = b%x;
            b = c%x;
        }
        return c;
    }
};    
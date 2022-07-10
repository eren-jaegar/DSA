/*
Approach - 1
we try dropping the egg from every floor.
it has two outcomes. either the egg breaks or it doesn't.
call for function for both the scenarios with appropriate parameters.
if egg breaks then call for number of floors less than the current floor and number of eggs 
1 less.
if the egg doesn't break then call for the number floors gretaer than the current floor 
with same number of eggs.

base case:
if(k==0)
then we have no floor to test hence we can know the answer with certainity in 0 moves.
if(k==1) then we have to try k moves to find the answer for k floors.


the answer for a particular call will be the maximum number of moves required.
as it means that in worst case we may require this many moves.
other scenarios are more or less ideal and do not convey the true number of moves.
so we take max(egg breaks, egg doesn't break).
now, to find the final answer, we have to find the minimum number of such calls required.
so we store the result in a temporary variable and take the minimum.
temp = min(temp, max(egg breaks, egg doesn't break)).


Time Complexity: O(N*K*K)
Space Complexity: O(N*K) */


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve(int n, int k, vector <vector <int> >&dp)
    {
        if(n==1)
            return k;
        if(k==0)
            return 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        int temp = INT_MAX;
        for(int i=1; i<=k; i++)
        {
            temp = min({temp, max(1+solve(n,k-i,dp), 1+solve(n-1,i-1,dp))});
        }
        return dp[n][k] = temp;
    }
    
    int eggDrop(int n, int k) 
    {
        vector <vector <int> > dp(n+1, vector <int>(k+1,-1));
        return solve(n, k, dp);
    }
};



/*
Approach - 2
realize that if we create a function f such that f(t,n) represents the maximum number of
floors for which answer can be determined with certainity in a maximum of t tries and with
n eggs.
then we have to find t such that f(t,n) >= k.
now we also need to realize that f(t,n) = f(t-1,n-1)+f(t-1,n)
this is because when we drop egg, it either breaks or it does not. so depending on that
the number of eggseither reduces or remains same. either way, the number of tries reduces
by 1 so, we reduce t by 1.

as it turns out the answer to this recursive relation comes out to be the binomial
sum of tCn.


Time Complexity: O(N*logK)
Space Complexity: O(logK) //because recursion is used. if we don't use it then it can be
done in O(1) complexity. */


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int binomialcoeff(int t, int n, int k)
    {
        int sum = 0;
        int term = 1;
        for(int i=1; i<=n; i++)
        {
            term *= t-i+1;
            term /= i;
            sum += term;
            if(sum >= k)
                return sum;
        }
        return sum;
    }
    
    int solve(int n, int k)
    {
        int low = 1;
        int high = k;
        int mid;
        int x = 0;
        while(low<high)
        {
            mid = (low+high)/2;
            x = binomialcoeff(mid, n, k);
            if(x < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
    
    int eggDrop(int n, int k) 
    {
        return solve(n,k);
    }
};
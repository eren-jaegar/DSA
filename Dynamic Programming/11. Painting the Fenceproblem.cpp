/*
Approach - 1
find the recursion function which comes out to be:

f(n) = (k-1)*(f(n-1)+f(n-2))

explanation: if we choose a different color then we have k-1 colors to choose from, and 
there will be f(n-1) possible combinations for rest of the elements.
if we choose the same color as previous fence then we have k-1 colors to choose from for
these two fences. rest all elements will have f(n-2) combinations.
so we get the recursive function as:
		
		f(n) = (k-1)*(f(n-1)+f(n-2))


Time Complexity: O(N)
Space Complexity: O(N) */


class Solution{
    public:
    long long countWays(int n, int k){
        
        long long int x = 1000000007;
        long long int dp[n+1];
        dp[1] = k;
        if(n>1)
            dp[2] = k*k;
        for(int i=3; i<=n; i++)
        {
            dp[i] = (((k-1)%x)*((dp[i-1]%x + dp[i-2]%x)%x))%x;
        }
        return dp[n];
    }
};



/*
Approach - 2
space optimized version of approach - 1


Time Complexity: O(N)
Space Complexity: O(1) */


class Solution{
    public:
    long long countWays(int n, int k){
        
        long long int x = 1000000007;
        long long int a = k;
        long long int b = k*k;
        long long int c;
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        for(int i=3; i<=n; i++)
        {
            c = (((k-1)%x)*((b%x + a%x)%x))%x;
            a = b;
            b = c;
        }
        return c;
    }
};
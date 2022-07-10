/*
Approach - 1

create a dp of size [n+1][r+1].
use the recursive formula: C(n,r) = C(n-1,r-1)+C(n-1,r)

Time Complexity: O(n*r)
Space Complexity: O(n*r) */


class Solution{
public:
    int nCr(int n, int r){
        
        long long int x = 1000000007;
        if(r>n)
            return 0;
        long long int dp[n+1][r+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=r; j++)
            {
                dp[i][j] = ((dp[i-1][j-1]%x)+(dp[i-1][j]%x))%x;
            }
        }
        return dp[n][r];
    }
};



/*
Approach - 2
we use pascal's triangle.
in pascals triangle, the new element at ith position is equal to the sum of element at
ith and (i-1)th position.


Time Complexity: O(N*K)
Space Complexity: O(K) */


class Solution{
public:
    int nCr(int n, int r){
        
        long long int x = 1000000007;
        int k = r;
        long long int dp[k+1] = {0};
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=min(i,k); j>0; j--)
            {
                dp[j] = (dp[j]+dp[j-1])%x;
            }
        }
        return dp[k];
    }
}



/*
Approach - 3
we can do it the normal way. (n-r)! gets cancelled.
ew find the inverse of the r! and multiply it with ans. then we multiply all number from
n-r+1 to n.
finally we return the result.


Time Complexity: O(N+K)
Space Complexity: O(K) */


class Solution{
public:
    int nCr(int n, int r){
        
        long long int x = 1000000007;
        long long int inv[r+1];
        inv[0] = 1;
        if(r>0)
            inv[1] = 1;
        for(int i=2; i<=r; i++)
            inv[i] = x-(x/i)*(inv[x%i])%x;
        long long int ans = 1;
        for(int i=0; i<=r; i++)
            ans = ((ans%x) * (inv[i]%x))%x;
        for(int i=n; i>=n-r+1; i--)
            ans = ((ans%x)*(i%x))%x;
        return ans;
    }
};
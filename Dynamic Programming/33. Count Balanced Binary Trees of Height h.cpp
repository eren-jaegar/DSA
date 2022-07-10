/*
Approach - 1

for a tree of height h, its children can both have height h-1 or either one can have height
h-1 and other can have height h-2.


Time Complexity: O(N)
Space Complexity: O(N) */



class Solution {
  public:
    long long int countBT(int h) {
        
        long long int dp[h+1];
        long long int x = 1000000007;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=h; i++)
        {
            dp[i] = ((dp[i-1]*dp[i-1])%x + 2*((dp[i-1]*dp[i-2])%x))%x;
        }
        return dp[h];
    }
};
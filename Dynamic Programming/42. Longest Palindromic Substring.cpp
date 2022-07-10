//NOTE: it can be done in O(N) time also, see manacher's algorithm


/*
Approach - 1

we create a dp that stores all the possible combinations of the indexes.

if the index are same then length of paindromic string will be 1.
else if indexes differ by 1 and the characters are same then the length will be 2.
else if the characters are same and dp[i+1][j-1] is palindrome then dp[i][j] will be palindrome
with length 2+dp[i+1][j-1].

for this we take i as starting index and j as ending index.
since we need i+1 in the recursive relation so we start iterating from i = n-1.

find the maximum length and the indexes for which it is maximum and then return that
substring.


Time Complexity: O(N^2)
Space Complexity: O(N^2) //can be reduced to O(N) as we require only two rows. */

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int len = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i == j)
                    dp[i][j] = 1;
                else if(s[i]==s[j] && j-i == 1)
                    dp[i][j] = 2;
                else if(s[i] == s[j])
                {
                    if(dp[i+1][j-1])
                        dp[i][j] = 2+dp[i+1][j-1];
                }
                len = max(len, dp[i][j]);
            }
        }
        int p,q;
        bool condition = false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dp[i][j] == len)
                {
                    p = i;
                    q = j;
                    condition = true;
                    break;
                }
            }
            if(condition)
                break;
        }
        return s.substr(p, q-p+1);
    }
};



/*
Approach - 2

we can do it in constant space.
for every element consider it as the centre for the plaindromic substring.
now, expand around it and find the size of the largest palindromic substring around it.
if the size is greater than the current size then update it and the starting index.

return the substring with the found starting index and maxlength.


Time Complexity: O(N^2)
Space Complexity: O(1) */


class Solution {
public:
    string longestPalindrome(string s) {
        
        
        int maxlen = 0;
        int p;
        int low,high;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            low = i-1;
            high = i+1;
            while(low>=0 && s[low] == s[i])
                low--;
            while(high<n && s[high] == s[i])
                high++;
            while(low>=0 && high<n && s[low] == s[high])
            {
                low--;
                high++;
            }
            if(maxlen < high-low-1)
            {
                maxlen = high - low - 1;
                p = low;
            }
        }
        return s.substr(p+1, maxlen);
    }
};
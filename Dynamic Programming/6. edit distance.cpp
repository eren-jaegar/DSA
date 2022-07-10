/*

Approach - 1

we try to make the match the last element of the strigs.
we have three ways to try to do it.
firstly, we can replace the current element and call for rest of the string.
secondly. we can insert a new element and call for the rest of the strings.
thirdly, we can delete the current element and call for the rest of the strings.

in case the elements are equal then we don't have to do anything to make them equal so we 
skip them.

base case is when string 1 is empty so we have to insert all the elements and other base
case is when string 2 is empty so we have to delete all the elements from string 1.


Time Complexity: O(N*M)
Space Complexity: O(M) //can be made as O(min(N,M)) */


class Solution {
  public:
    int editDistance(string s, string t) {
        
        int x = 1003;
        int dp[2][t.size()+1];
        
        int bi;
        for(int i=0; i<=s.size(); i++)
        {
            bi = i&1;
            for(int j=0; j<=t.size(); j++)
            {
                if(i == 0)
                    dp[bi][j] = j;
                else if(j == 0)
                    dp[bi][j] = i;
                else if(s[i-1] == t[j-1])
                    dp[bi][j] = dp[1-bi][j-1];
                else
                    dp[bi][j] = 1+min({dp[1-bi][j-1], dp[bi][j-1], dp[1-bi][j]});
            }
        }
        return dp[bi][t.size()];
    }
};

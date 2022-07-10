/*
Approach - 1

do as taught.


Time Complexity: O(N^3)
Space Complexity: O(N^2) */


class Solution{
public:
    int x = 1003;
    
    int mcm(string &s, int start, int end, bool condition, vector <vector <pair<int, int> > >&dp)
    {
        if(start > end)
            return 0;
        if(start == end)
        {
            if(condition)
                return s[start] == 'T';
            else
                return s[start] == 'F';
        }
        if(condition && dp[start][end].first != -1)
            return dp[start][end].first;
        if(!condition && dp[start][end].second != -1)
            return dp[start][end].second;
        int temp = 0;
        for(int k=start+1; k<end; k+=2)
        {
            int lt = (mcm(s, start, k-1, true, dp))%x;
            int rt = (mcm(s, k+1, end, true, dp))%x;
            int lf = (mcm(s, start, k-1, false, dp))%x;
            int rf = (mcm(s, k+1, end, false, dp))%x;
            if(s[k] == '&' && condition)
                temp = ((temp%x) + (lt*rt)%x)%x;
            else if(s[k] == '&')
                temp = ((lf*rf)%x + (lf*rt)%x + (lt*rf)%x + temp%x)%x;
            else if(s[k] == '|' && condition)
                temp = (temp%x + (lt*rf)%x + (rt*lf)%x + (lt*rt)%x)%x;
            else if(s[k] == '|')
                temp = ((lf*rf)%x + temp%x)%x;
            else if(s[k] == '^' && condition)
                temp = ((lt*rf)%x + (rt*lf)%x + temp%x)%x;
            else
                temp = ((lt*rt)%x + (lf*rf)%x + temp%x)%x;
        }
        if(condition)
            return dp[start][end].first = temp;
        else
            return dp[start][end].second = temp;
    }

    int countWays(int N, string S){
        
        vector <vector <pair<int, int> > >dp(N, vector <pair <int,int> > (N,make_pair(-1,-1))); 
        return mcm(S, 0, N-1, true, dp);
        
    }
};
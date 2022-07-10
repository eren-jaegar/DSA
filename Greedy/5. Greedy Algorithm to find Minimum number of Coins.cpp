/*
Approach - 1
start from the biggest denomination and keep finding the max. number of coins that we can
use of that denomination.

Time Complexity: O(N)
Space Complexity: O(1) */

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector <int> money = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int count = 0;
        vector <int> ans;
        for(int i=0; i<money.size(); i++)
        {
            count = N/money[i];
            if(count)
            {
                N %= money[i];
            }
            while(count)
            {
                ans.push_back(money[i]);
                count--;
            }
        }
        return ans;
    }
};
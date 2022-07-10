/*
Approach - 1
ina a single purchase we can buy k+1 candies as we buy 1 and get k candies for free.
so we first we find the total number of purchases that is given by ceil(n/(k+1))(lets call it x).
sort the array in ascending order of price.
now for min amount, we buy the first x candies and for the max amount, we buy the last
x candies.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int n = N;
        int purchase = ceil((float)N/(float)(K+1));
        sort(candies, candies+n);
        int minn = 0;
        int maxx = 0;
        for(int i=0; i<purchase; i++)
            minn += candies[i];
        int j = n-1;
        while(purchase--)
        {
            maxx += candies[j];
            j--;
        }
        vector <int> ans = {minn, maxx};
        return ans;
    }
};

//NOTE: for the given range of values, long long int should be used instead of int.
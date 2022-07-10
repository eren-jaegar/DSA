/*
Approach - 1
make a vector of pairs. let the first element of pair be the price and second element be
the day of that price.
sort the vector according to the price.
now start iterating the vector and picking as many stocks as you can.
for a given price you can pick the min between these two:
either the stock limit for that day
or the number of stocks that you can buy for remaining money.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        
        vector <pair <int,int> > nums(n);
        for(int i=0; i<n; i++)
        {
            nums[i].first = price[i];
            nums[i].second = i+1;
        }
        sort(nums.begin(), nums.end());
        int count = 0;
        int stocks;
        for(int i=0; i<n; i++)
        {
            if(nums[i].first > k)
                break;
            stocks = k/nums[i].first;
            stocks = min(nums[i].second, stocks);
            count += stocks;
            k -= stocks*nums[i].first;
        }
        return count;
        
    }
};
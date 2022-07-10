//start iterating the array assuming minimum value in the array as the first element.
//now if the next element is less than currently assumed minimum element then,
//update the assumed minimum element with it.
//in case the next element is not less than the currently assumed minimum element
//than find their difference and take it as profit.
//iterate through entire array and take max profit value as answer.

int minind = 0;
        int profit = 0;
        int maxprofit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[minind] >= prices[i])
                minind = i;
            else
            {
                profit = prices[i] - prices[minind];
                maxprofit = max(maxprofit,profit);
            }
        }
        return maxprofit;
/*
Approach - 1
we sort the array according to the value/weight ratio of the elements.
this way we can ensure that we first pick the items that add most to the value and least
to the weight.
keep adding the elements till their weight is less than W. if we can't add the last element
fully then we add it partially as much as W allows.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, [](Item a, Item b)
        {
            double x = ((double)a.value/(double)a.weight); //necessary to take ratio in double
            double y = ((double)b.value/(double)b.weight); //if we take in int then it wiil roundoff
            return (x > y); //and we might end up with the element with smaller ratio apearing first 
        });//in the array. for ex. for ratios 1.5 and 1.6, int will treat them both as 1 and then its
        //possible that the element with ratio 1.5 might appear first which can give the wrong answer,
        //in case it is the last element to be added in the knapsack.
        double ans = 0;
        int weight = 0;
        int i = 0;
        while(i<n && weight < W)
        {
            weight += arr[i].weight;
            ans += arr[i].value;
            i++;
        }
        i--;
        if(weight <= W)
            return ans;
        double diff = weight - W;
        double frac = (diff*arr[i].value)/arr[i].weight;
        ans -= frac;
        return ans;
    }
        
};
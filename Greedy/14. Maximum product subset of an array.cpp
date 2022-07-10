/*
Approach - 1
count the number of positive and negative numbers.
while counting, find the gretaest negative number as well.
now, iterate through the array multiplying, all the numbers except 0s.
if the number of negative numbers is odd then don't multiply the maximum negative number 
found in first step. don't multiply it only once, rest all times we encounter it, we have
to multiply it.
after the loop.
chech if the number of positive and negative numbers is zero.
if yes, then the array only contains 0, return 0.
if there are no positive numbers and only one negative number then, check the size of 
the array.
if it is 1 then return a[0].
else return 0 as rest all numbers are 0.
otherwise return ans.

Time Complexity: O(N)
Space Complexity: O(1) */

class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        
        long long int x = 1000000007;
        long long int neg = 0;
        long long int pos = 0;
        int maxneg = INT_MIN;
        bool condition = true;
        for(int i=0; i<n; i++)
        {
            if(a[i] > 0)
                pos++;
            if(a[i] < 0)
            {
                neg++;
                maxneg = max(maxneg,a[i]);
            }
        }
        long long int ans = 1;
        for(int i=0; i<n; i++)
        {
            if(neg%2 == 1)
            {
                if(a[i] == maxneg && condition)
                {
                    condition = false;
                    continue;
                }
            }
            if(a[i] == 0)
                continue;
            ans *= a[i];
            ans %= x;
        }
        if(pos==0 && neg==0)
            return 0;
        
        if(pos == 0 && neg == 1)
        {
            if(n == 1)
                return a[0];
            else
                return 0;
        }
        return ans;
        
    }
};
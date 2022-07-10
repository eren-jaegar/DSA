/*
Approach - 1
sort the array.
now take the sum of all i*a[i].

this works because the larger number should be multiplied with larger index to get the
largest answer.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution{
    public:
    long long int Maximize(int a[],int n)
    {
        long long int x = 1000000007;
        sort(a, a+n);
        long long int sum = 0;
        for(long long int i=0; i<n; i++) //take i as long long int else i*a[i] will be
        { //computed as int and it will overflow before being assigned to sum.
            sum += i*a[i];
            sum %= x;
        }
        return sum;
    }
};
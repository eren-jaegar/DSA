/*
Approach - 1
iterate through the array k time sand find the minimum element each time.
multiply this minimum element by -1.
after the loop, sum all the elements.

Time Complexity: O(N*K)
Space Complexity: O(1) */



/*
Approach - 2
sort the array.
start iterating through the array.
as long as the elements are negative and k is positive and we have not reached the end of
the array. make the negative elements positive by multiplying by -1.
if loop breaks but k is not zero then sort the array again and if k is odd then multiply
the first element by -1.
sum all the elements and that will be the answer.

Time Complexity: O(NlogN)
Space Complexity : O(1) */

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a+n);
        int i = 0;
        while(i<n && a[i]<0 && k)
        {
            if(a[i] < 0)
            {
                a[i] *= -1;
                k--;
                i++;
            }
            else
                break;
        }
        long long int sum = 0;
        if(k)
        {
            sort(a, a+n);
            if(k%2 == 1)
                a[0] *= -1;
        }
        for(int j=0; j<n; j++)
        {
            sum += a[j];
        }
        return sum;
    }
};



/*
Similar approach as approach - 2
but we don't have to sort the array twice.
after the first loop ends if i is n then make it n-1.
if k is odd, then we need to multiply smallest element by -1.
now all the elements are non-negative in the array.
the samllest element will be either at i or at i-1.
this is because in case the first loop broke because we encountered a non-negative element
then either this element or element before it will have the least absolute value.
so we compare them and then multiply the one with least absolute value by -1.

take the sum of all the elements.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a+n);
        int i = 0;
        while(i<n && a[i]<0 && k)
        {
            if(a[i] < 0)
            {
                a[i] *= -1;
                k--;
                i++;
            }
            else
                break;
        }
        if(i == n)
            i--;
        long long int sum = 0;
        if(k%2 == 1)
        {
            if(i>0 && abs(a[i]) > abs(a[i-1]))
                i--;
            a[i] *= -1;
        }
        for(int j=0; j<n; j++)
        {
            sum += a[j];
        }
        return sum;
    }
};
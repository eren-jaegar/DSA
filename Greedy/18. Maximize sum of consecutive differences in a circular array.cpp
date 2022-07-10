/*
Approach - 1
we need to maximize the absolute sum.
sum will be maximum when we subtract large values from small values.
this can be achieved by first sorting the array.
now, construct a new array. in this we put the elements of original array alternatively.
first insert the first element and then insert the last element. then insert the second
element and then insert the second last element and so on...
the array thus constructed will have the maximum absolute sum.

Time Complexity: O(NlogN)
Space Complexity: O(N) */


/*
if we don't construct a new vector and instead use two pointers moving from beginning and
ending to find the sum then we can do this in O(1) space.


Time Complexity: O(NlogN)
Space Complexity: O(1) */


long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    int i = 0;
    int j = n-1;
    long long int sum = 0;
    bool condition = true;
    while(i<j)
    {
        sum += abs(arr[j]-arr[i]);
        if(condition)
        {
            i++;
            condition = false;
        }
        else
        {
            j--;
            condition = true;
        }
    }
    sum += abs(arr[i]-arr[0]); //since, it is circular so we have to take difference of
    //last element(element that would have been last in the new constructed array) and 
    //first element also.
    return sum;
}



/*
Approach - 2
similar to above approach but different implementation.
we need to realize that in above approach all elements with index < n/2 are subtracted
twice and elements with index > n/2 are added twice. so we can simply do this to find
the answer.
in this approach if n is odd then n/2+1 is added once and subtracted once so it gets 
cancelled out and hence is not considered for odd n but is considered for even n.


Time Complexity: O(NlogN)
Space Complexity: O(1) */


long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    int i = 0;
    int j = n-1;
    long long int sum = 0;
    for(int i=0; i<n/2; i++)
    {
        sum -= 2*arr[i];
        sum += 2*arr[n-1-i];
    }
    return sum;
}
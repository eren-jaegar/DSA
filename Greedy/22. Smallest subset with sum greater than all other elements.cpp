/*
Approach - 1
sort the array and find the sum of all the elements.
now, start taking sum of largest elements in reqsum and subtracting them from totalsum.
increase the count for every element taken.
when reqsum>totalsum, then break the loop.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        
        long long int totalsum = 0;
        long long int reqsum = 0;
        int count = 0;
        sort(Arr.begin(), Arr.end());
        for(int i=0; i<N; i++)
        {
            totalsum += Arr[i];
        }
        for(int i=N-1; i>=0; i--)
        {
            if(reqsum > totalsum)
                break;
            reqsum += Arr[i];
            totalsum -= Arr[i];
            count++;
        }
        return count;
    }
};
/*
Approach - 1
sort the array.
take two pointers. one at 0 and other at m-1.
now move them forward and keep finding the difference of elements pointed by them.
the minimum difference will be the answer.

we select the elements between those two elements whose difference is minimum.

Time Complexity: O(NlogN)
Space Complexity: O(1) */


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        long long int ans = LLONG_MAX;
        int i = 0;
        int j = i+m-1;
        sort(a.begin(), a.end());
        while(j<n)
        {
            ans = min(ans,a[j]-a[i]);
            i++;
            j++;
        }
        return ans;
        
    }   
};
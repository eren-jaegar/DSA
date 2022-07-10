/*
Approach - 1
the difference between the two numbers of arrays should be as minimum as possible.
so, we have to match small numbre with small numbre and large ones with large ones.
sort both the arrays, and then find the absolute difference between corresponding elements 
of both the arrays.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long int sum = 0;
        for(int i=0; i<N; i++)
        {
            sum += abs(A[i]-B[i]);
        }
        return sum;
    }
};
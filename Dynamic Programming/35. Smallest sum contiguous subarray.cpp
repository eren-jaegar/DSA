/*
Approach - 1

same as kadane's algorithm. just use min function instead of max function.


Time Complexity: O(N)
Space Complexity: O(1) */


class Solution{
  public:
  long long int smallestSumSubarray(vector<int>& a){
      
      long long int sum = 0;
      long long int ans = LLONG_MAX;
      for(int i=0; i<a.size(); i++)
      {
          sum = min(sum+a[i], (long long int)a[i]);
          ans = min(ans, sum);
      }
      return ans;
  }
};
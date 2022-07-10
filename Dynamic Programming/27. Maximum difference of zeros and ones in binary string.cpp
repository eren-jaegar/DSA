/*
Approach - 1
use kadane's algorithm.

Time Complexity: O(N)
Space Complexity: O(1) */


class Solution{
public:	
	int maxSubstring(string S)
	{
	    int current = 0;
	    int total = INT_MIN;
	    for(int i=0; i<S.size(); i++)
	    {
	        if(S[i] == '1')
	            current--;
	        else
	            current++;
	        total = max(total, current);
	        if(current<0)
	            current = 0;
	    }
	    if(total < 0)
	        total = -1;
	    return total;
	}
};
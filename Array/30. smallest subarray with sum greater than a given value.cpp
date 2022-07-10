//we first find the first subarray starting at index 0 with sum >= target.
//if such subarray does not exist, i.e., sum of all the elements of subarray is less
//than target, then we return zero else
//now we use two pointers
//first pointer is at the end of the subarray that we just found. actually its one
//position ahead than the end of the subarray.
//second pointer is initialized at index 0
//we subtract the element pointed by the second pointer and then increase the second
//pointer by 1. this is done until sum becomes less than target. after that difference
//between first and second pointer is taken to find the size of the subarray.
//we use ans = min(ans, i-j+1) to find the minimum size.
//then element pointed by first pointer is added and the first pointer is increased
//by 1. this is done until sum becomes greater than the target.
//steps are repeated from line 8 till the first pointer hits nums.size().
//time complexity: O(N)
//space complexity: O(1)


long long int sum = 0;
        int ans;
        int i = 0;
        while(sum < target && i<nums.size())
        {
            sum += nums[i];
            i++;
        }
        if(sum < target)
            return 0;
        ans = i;
        int j = 0;
        while(i <= nums.size())
        {
            while(sum >= target)
            {
                sum -= nums[j];
                j++;
            }
            
            ans = min(ans,i-j+1);
            if(i == nums.size())
                break;
            while(sum < target && i < nums.size())
            {
                sum += nums[i];
                i++;
            }
        }
        return ans;


//another implementation(better implementation actually) of the same approach


long long int sum = 0;
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        for(i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans, i-j+1);
                sum -= nums[j];
                j++;
            }
        }
        
        return (ans!=INT_MAX) ? ans : 0;

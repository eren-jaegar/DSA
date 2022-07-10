//the number of numbers in the array that are smaller than or equal to
//a particular number(say 4) will always be greater than the number(4) itself
//if the number is repeated.
//this will also be true if the number is greater than the repeated number.
//the number of numbers that are smaller than or equal to a particular
//number will be equal to that number if that number is smaller than the 
//repeated number.
//we use binary search on numbers [1,2,3...n].
//we dont do binary search on the given array but on the array [1,2...n].
//we get the midpoint and check how many (numbers in the array are smaller
//than or equal to the midpoint) = count.
//if count is greater than mid than we search on left half else we search
//on right half.
//time complexity is nlog(n)   
//log(n) for binary search and n for calculating count.


int low = 1;
        int high = nums.size()-1;
        int mid;
        int duplicate;
        
        auto count = [&] (int mid)
        {
            int c = 0;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] <= mid)
                    c++;
            }
            return c;
        };
        
        while(low <= high)
        {
            mid = (low+high)/2;
            if(count(mid) > mid)
            {
                duplicate = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return duplicate;


//floyd's algorithm
//time complexity O(n), space complexity O(1).


        auto it = nums.begin();
        auto it2 = nums.begin();
        int a,b;
        advance(it, nums[0]);
        advance(it2, nums[nums[0]]);
        while(it != it2)
        {
            a = *it;
            b = *it2;
            it = nums.begin();
            it2 = nums.begin();
            advance(it, a);         //moving pointer once
            advance(it2, nums[b]);  //moving pointer twice
        }
        it = nums.begin();
        while(it != it2)
        {
            a = *it;
            b = *it2;
            it = nums.begin();
            it2 = nums.begin();
            advance(it, a);
            advance(it2, b);
        }
        return it-nums.begin();



//could have been done in O(N) time complexity with O(N) sapce by recording frequencies
//in an unordered map.
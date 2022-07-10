//logic is that, first count the number of elments less than equal to k.
//all we have to do is to check each subarray of size k, for elements > k.
//because the number of such elements will be the number of swaps required. so, we
//check every subarray of size k and then take the minimum of number of such elements
//because that will be the minimum number of swaps required to achieve our goal.


//first approac is brute force. that is for every subarray of size k, we iterate over
//it and find the number of elements > k.
//it will be executed with time complexity O(N^2)


//better approach is to use the two pointers/sliding window approach.
//we first count the number of elements >k(let it be ans) in the first subarray of size k starting
//at index 0. we place two pointers, one at the beginning and other at the end of the
//subarray. if the element pointed by the pointer at the beginning is >k then we ans--
//if the element pointed by the second pointer is >k then ans++. this is because the 
//subarray is moving forward.
//take the minimum of ans after every step and that will be the answer.

//time complexity: O(N)
//space complexity: O(1)


int count = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] <= k)
            count++;
        }
        int j = count;
        int ans = 0;;
        int anss = count;
        if(count == n || count == 0)
            return 0;
        else
        {
            for(int i=0; i<j; i++)
            {
                if(arr[i] > k)
                    ans++;
            }
            anss = min(anss,ans);
            for(int i=0; j<n;)
            {
                if(arr[i] > k)
                    ans--;
                i++;
                if(arr[j] > k)
                    ans++;
                j++;
                anss = min(anss,ans);
            }
        }
        return anss;
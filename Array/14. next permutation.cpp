//if the elements are in decreasing order then the permutation is maximum and no
//higher permutation can be found.
//so we start checking from right and the continue till the sequence is
//increasing(from right) or in other words decreasing(from left).
//now this subarray can't give higher permutation since it is decreasing.
//so we take immediate number left to it and swap it with the number just greater
//than it and to the right of it(i.e. in the decreasing sequence).
//now, we just reverse the decreasing sequence and get the required next permutation
//THIS PROCEDURE WAS FOUND BY OBSERVATION.



//explanation from website follows:

//First, we observe that for any given sequence that is in descending order, no next 
//larger permutation is possible. For example, no next permutation is possible for 
//the following array:[9,5,4,3,1].
//We need to find the first pair of two successive numbers a[i]a[i] and a[i-1]a[i−1],
//from the right, which satisfy a[i] > a[i-1]a[i]>a[i−1]. Now, no rearrangements to 
//the right of a[i-1]a[i−1] can create a larger permutation since that subarray 
//consists of numbers in descending order. Thus, we need to rearrange the numbers to 
//the right of a[i-1]a[i−1] including itself.
//Now, what kind of rearrangement will produce the next larger number? We want to 
//create the permutation just larger than the current one. Therefore, we need to 
//replace the number a[i-1]a[i−1] with the number which is just larger than itself 
//among the numbers lying to its right section, say a[j]a[j].
//We swap the numbers a[i-1]a[i−1] and a[j]a[j]. We now have the correct number at 
//index i-1i−1. But still the current permutation isn't the permutation that we are 
//looking for. We need the smallest permutation that can be formed by using the 
//numbers only to the right of a[i-1]a[i−1]. Therefore, we need to place those 
//numbers in ascending order to get their smallest permutation.
//But, recall that while scanning the numbers from the right, we simply kept 
//decrementing the index until we found the pair a[i]a[i] and a[i-1]a[i−1] where, 
//a[i] > a[i-1]a[i]>a[i−1]. Thus, all numbers to the right of a[i-1]a[i−1] were 
//already sorted in descending order. Furthermore, swapping a[i-1]a[i−1] and a[j]a[j]
//didn't change that order. Therefore, we simply need to reverse the numbers following
//a[i-1]a[i−1] to get the next smallest lexicographic permutation.



 if(nums.size() != 1)
        {
            auto p1 = nums.end();
            auto p2 = p1;
            p2--;
            p2--;
            p1--;
            int n = nums.size();
            int k = nums.size()-1 ;
            while(*p2 - *p1 >= 0)
            {
                k--;
                p2--;
                p1--;
                if(p2 < nums.begin())
                    break;
            }
            if(k == n-1)
            {
                swap(nums[n-1],nums[n-2]);
            }
            else if(k == 0)
            {
                reverse(nums.begin(),nums.end());
                //for(int i=0; i<n/2; i++)
                  //  swap(nums[i],nums[n-i-1]);
            }
            else
            {
                int a = k;
                a--;
                int b;
                for(int i=k; i<nums.size(); i++)
                {
                    if(nums[i] > nums[a])
                        b = i;
                }
                swap(nums[a],nums[b]);
                p1 = nums.begin();
                advance(p1,k);
                reverse(p1,nums.end());
              //  for(int i=k; i<(n+k)/2; i++)
                //    swap(nums[i],nums[n-1+k-i]);
            }
            
        }
//easy approach
//just record the frequency of all the elements in an unordered map and then check
//if frequency is more than floor(n/k).
//if yes insert in answer vector else skip it.
//time complexity is O(N) assuming that [] takes constant time(which is the average case)
//space complexity is O(N).


//could have been done by sorting also in O(NlogN) time complexity.



unordered_map <int,int> um;
        for(int i=0; i<nums.size(); i++)
        {
            um[nums[i]]++;
        }
        vector <int> ans;
        auto it = um.begin();
        int a = floor((float)nums.size()/3);
        while(it != um.end())
        {
            if(it->second > a)
                ans.push_back(it->first);
            it++;
        }
        return ans;


//if the numbers are non negative then array can be used to store frequency else map
//has to be used.


//better solution using boyer moore voting algorithm
//first we initialize num1 by the first number and then we initialize num2 by the 
//next number which is not equal to the first number of the given array.
//then we iterate the whole array

//moore voting algorithm for finding the majority element which is occurs more than 
//n/2 times works as follows:
//initialize num as the first number of the given array and count as 1.
//now iterate over the whole array. if the number is equal to num then increase the
//count by 1 else decrease it by 1.
//if count becomes zero then change num to the next number that comes in the array.
//now, this algo works because if there is a majority element then only it can occur
//more than n/2 times. so basically count increases by the frequency of majority
//element and decreases by the combined frequency of all other elements.
//hence, this is the worst case and we still get the answer.
//best case would be for {1,1,1,2,3,4,5,6,6,6,6,6,6,6,6,6} such an array.
//here, other elements cancel out each other rather than cancelling out the frequency
//of the majority element.

//similar concept works in the case of current question.
//we can either have 0 or 1 or at max 2 majority elements in this case. 
//num1 and num2 will always give some numbers. its just that if we have 2 majority 
//elements then they are the answer else if we have 1 majority element then one of them
//is the answer and if we have zero majority elements then none of them is the answer.
//hence, we check the frequency again after finding num1 and num2.
//worst case for one majority element is if we have all the instances of the majority
//element in the beginning. rest of all the numbers reduce its frequency alternatively
//i.e. if q elements are remaining then frequency of majority element is reduced by 
//(q-1)/2 for odd q and q/2 for even q.

//link to understand problem: https://www.youtube.com/watch?v=yDbkQd9t2ig
//for occurs more than n/2: https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=0s

int count1 = 0;
        int count2 = 0;
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(num1 == nums[i])
                count1++;
            else if(num2 == nums[i])
                count2++;
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(num1 == nums[i])
                count1++;
            if(num2 == nums[i])
                count2++;
        }
        vector <int> ans;
        if(count1 > floor((float)nums.size()/3))
            ans.push_back(num1);
        if(count2 > floor((float)nums.size()/3))
            ans.push_back(num2);
        return ans;
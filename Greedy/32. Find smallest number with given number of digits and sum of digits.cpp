/*
Approach - 1
if s>9*d then we can't form a number as 9*d is the maximum sum of digits that we can
achieve.
we start constructing the number from rightmost digit.
if the sum is greater than 9 then push_back 9 else push_back sum. subtract from sum whatever
you have pushed back.
do this until sum is 0.
for every push_back reduce D by 1, meaning we have taken care of 1 digit.

after this loop, if d is not zero then it means we have insert more digits.
so, to get the smallest number we will have to push_back 0 (d-1) times and push_back 1,
only 1 time in the last so as to make it a d digit number.
now since we will be pushing 1 so the sum will exceed the requied sum by 1 so to counter
that, before inserting 0s, we reduce the last inserted number by 1.


finally, as we have constructed the string from rightmost digit so we need to reverse it
to get the correct answer.


Time Complexity: O(D)
Space Complexity: O(1) //the task itself doesn't require any space. */


class Solution{   
public:
    string smallestNumber(int S, int D){
        
        if(9*D < S)
            return "-1";
        string s;
        while(S)
        {
            s.push_back('0' + min(9,S));
            S -= min(9,S);
            D--;
        }
        if(D)
        {
            s.back() -= 1;
            while(D>1)
            {
                s.push_back('0');
                D--;
            }
            s.push_back('1');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
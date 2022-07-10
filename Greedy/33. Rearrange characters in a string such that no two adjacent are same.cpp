//Link to question: https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/#


/*
Approach - 1
create a vector of size 26 and store the frequencies of all the characters in the string.
sort the vector in descending order.
now, we iterate through the vector.
first we insert the characters in string in even positions and then in odd position.
this ensures that if a valid answer is possible then we get it.
so we start pushing the character with the maximum frequency and keep reducing its frequency
by 1 until it becomes 0. once it becomes 0, we move on to the next element.
once all the even spaces are filled in the string, we start filling the  odd spaces.

after the filling of elements is done, iterate through the new string and if any element
is same as its next element then return "-1" else return the new string.


This solution works because lets say we filled the first element and it had x frequency.
now, we start filling the second element. for the second element to come adjacent to itself,
its frequency will have to be >x which is not possible as we have taken x as the highest
frequency. so, if a solution exists, then this algorithm will always give the answer.


Time Complexity: O(N) //sorting of vector of size 26 takes constant time. it is not dependent 
on N. still if one might be persistent then he may say O(NlogN) though the correct answer
according to me is O(N).
Space Complexity: O(1) if you use the same string that was used to give us the input else 
O(N) if we form a new string. frequency vector takes contant space. its size is always 26.
*/


/*
Note: if we have to just check whether a string is possible or not then we check the 
maximum frequency. if it is <=ceil(n/2) then the answer is possible else if 
max. frequency>ceil(n/2) then, no answer is possible. */


class Solution
{
    public:
    string rearrangeString(string str)
    {
        vector <pair <int,char> > ans(26, pair <int,char> (0,'a'));
        int n = str.size();
        for(int i=0; i<n; i++)
        {
            ans[str[i]-'a'].second = str[i];
            ans[str[i]-'a'].first++;
        }
        sort(ans.rbegin(), ans.rend());
        int j = 0;
        for(int i=0; i<n; )
        {
            while(j<26 && ans[j].first == 0)
                j++;
            if(j>=26)
                break;
            str[i] = ans[j].second;
            ans[j].first--;
            i += 2;
        }
        for(int i=1; i<n;)
        {
            while(j<26 && ans[j].first == 0)
                j++;
            if(j >= 26)
                break;
            str[i] = ans[j].second;
            ans[j].first--;
            i += 2;
        }
        for(int i=0; i<n-1; i++)
        {
            if(str[i] == str[i+1])
                return "-1";
        }
        return str;
    }
    
};
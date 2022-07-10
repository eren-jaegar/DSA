//Link to the question: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#


/*
Approach - 1
find the order in which each alphabet occurs.
number the order from 1 to 26(or whatever number <26 in case all the 26 alphabets are 
not present in the string)

run two nested for loops on this vector.
if any alphabet that comes lexicographically later than the current alphabet but occurs
before the current alphabet in the string then for that current alphabet find the 
lexicigraphically greater alphabet that occurs at the earliest.
break the loop after such a letter has been found.

now, we have found the letter to be replaced and its replacement so replace them.


Time Complexity: O(max(26*26, N))
Space Complexity: O(1) */


class Solution{
public:
    string chooseandswap(string a){
        
        vector <int> freq(26, 0);
        int n = a.size();
        int j = 1;
        for(int i=0; i<n; i++)
        {
            if(freq[a[i]-'a'] == 0)
            {
                freq[a[i] - 'a'] = j;
                j++;
            }
        }
        int maxx = 27;
        int replace = 0;
        int current = 0;
        for(int i=0; i<26; i++)
        {
            maxx = freq[i];
            replace = -1;
            current = i;
            for(int k=i+1; k<26; k++)
            {
                if(freq[k]!=0)
                {
                    if(freq[k] < maxx)
                    {
                        maxx = freq[k];
                        replace = k;
                    }
                }
            }
            if(replace != -1)
                break;
        }
        if(replace == -1)
            return a;
        for(int i=0; i<n; i++)
        {
            if(a[i] == 'a'+current)
            {
                a[i] = 'a'+replace;
                continue;
            }
            if(a[i] == 'a'+replace)
            {
                a[i] = 'a'+current;
                continue;
            }
        }
        return a;
        
    }
    
};



/*
Approach - 2
we store the first index of every alphabet at which the alphabet occurs.
then we start iterating the string and for every element, and check if any alphabet smaller
than the current one has its first appearance later than the current one.
if so, we have found our element and we break out of the loop.
then, just swap the elements.


Time Complexity: O(26*N)
Space Complexity: O(1) */


class Solution{
public:
    string chooseandswap(string a){
        
        vector <int> freq(26, -1);
        int n = a.size();
        for(int i=0; i<n; i++)
        {
            if(freq[a[i]-'a'] == -1)
            {
                freq[a[i] - 'a'] = i;
            }
        }
        int j;
        int i;
        for(i=0; i<a.size(); i++)
        {
            for(j=0; j<a[i]-'a'; j++)
            {
                if(freq[j] > freq[a[i]-'a'])
                {
                    break;
                }
            }
            if(j != a[i]-'a')
                break;
        }
        if(i == a.size())
            return a;
        char a1 = a[i];
        char a2 = 'a'+j;
        for(int i=0; i<n; i++)
        {
            if(a[i] == a1)
            {
                a[i] = a2;
                continue;
            }
            if(a[i] == a2)
            {
                a[i] = a1;
                continue;
            }
        }
        return a;
        
    }
    
};
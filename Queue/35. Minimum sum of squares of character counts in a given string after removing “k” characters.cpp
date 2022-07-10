//Approach - 1
//we can create a vector and store the frequency of all the characters in it.
//now sort the array.
//run a loop for k times.
//in the loop, subtract one form the last element and again sort the array.

//the last element will always have the largest frequency so, we always try to reduce it.

//Time Complexity: O(K*N*logN)
//Space Complexity: O(N)



//Approach - 2
//we can use a priority queue.
//store the frequencies of all the elements in the priority queue.
//then we run a loop for k times.
//each time we take the top element from the priority queue and subtract one from it and
//push it back into the queue.
//after the loop, we just take the sum of squares of all the numbers of the queue and
//return it as ans.

//Time Complexity: O(NlogN)
//Space Complexity: O(N)

class Solution{
public:
    int minValue(string s, int k){
        
        unordered_map <char,int> ump;
        for(int i=0; i<s.size(); i++)
        {
            ump[s[i]]++;
        }
        
        priority_queue <int> freq;
        auto it = ump.begin();
        while(it!=ump.end())
        {
            freq.push(it->second);
            it++;
        }
        
        int x;
        while(k--)
        {
            x = freq.top();
            freq.pop();
            x--;
            freq.push(x);
        }
        int ans = 0;
        while(!freq.empty())
        {
            x = freq.top();
            freq.pop();
            ans += x*x;
        }
        return ans;
        
    }
};



//Same approach but we use multiset.

class Solution{
public:
    int minValue(string s, int k){
        
        unordered_map <char,int> ump;
        for(int i=0; i<s.size(); i++)
        {
            ump[s[i]]++;
        }
        
        multiset <int> freq;
        auto it = ump.begin();
        while(it!=ump.end())
        {
            freq.insert(it->second);
            it++;
        }
        
        int x;
        auto it2 = freq.end();
        it2--;
        while(k--)
        {
            it2 = freq.end();
            it2--;
            x = *it2;
            x--;
            freq.erase(it2);
            it2 = freq.end();
            it2--;
            freq.insert(it2,x);
        }
        int ans = 0;
        auto it3 = freq.begin();
        while(it3 != freq.end())
        {
            x = *it3;
            it3++;
            ans += x*x;
        }
        return ans;
        
    }
};



//Approach - 3(best approach)
//we first get the frequency of all the characters.
//now, we create another map and get the frequencies of the frequencies of characters.
//we also find the maximum, i.e, what is the biggest number that is a frequency of a 
//character. lets call it maxx(in code maximum)
//lets call frequencies of the frequencies of characters as ffc.
//now, in map of ffc, we start by reducing the maxx frequency. if ffc[maxx] is less than 
//k then make ffc[maxx-1] += ffc[maxx] i.e., we have reduced the maxx freq by 1.
//now reduce maxx by 1 as that will now be the biggest frequency.
//keep doing this until k<ffc[maxx] then reduce ffc[maxx] by k and increase ffc[maxx] by 1.
//this is because we can make now remove only k elements from the string.

//after this find the sum of the squares by doing (it2->first)*(it2->first)*(it2->second)
//for every element. here it2->first is the frequency and it2->second is the frequency of
//frequency i.e., how many times it that frequency comes.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution{
public:
    int minValue(string s, int k){
        
        unordered_map <char,int> character;
        unordered_map <int,int> freq;
        
        for(int i=0; i<s.size(); i++)
        {
            character[s[i]]++;
        }
        auto it = character.begin();
        
        int maximum = 0;
        while(it != character.end())
        {
            freq[it->second]++;
            maximum = max(maximum,it->second);
            it++;
        }
        
        while(k)
        {
            if(k>=freq[maximum])
            {
                k -= freq[maximum];
                freq[maximum-1] += freq[maximum];
                freq[maximum] = 0;
                maximum--;
            }
            else
            {
                freq[maximum] -= k;
                maximum--;
                freq[maximum] += k;
                k = 0;
            }
        }
        
        auto it2 = freq.begin();
        int ans = 0;
        while(it2 != freq.end())
        {
            ans += (it2->first)*(it2->first)*(it2->second);
            it2++;
        }
        return ans;
    }
};
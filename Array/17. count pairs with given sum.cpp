//putting all the values in a multiset and then using count function of multiset
//to see if the pair exists and if it does then how many of them exists for a particular
//value. hence, count function is used instead of find because we want to know the 
//number of pairs also. for ex: for k=6 {1,1,5} forms 2 pairs so count(k-5) gives 2.
//take care when arr[i] == k/2.
//finally divide the pairs by 2 as they are counted twice.
//SPACE COMPLEXITY: O(N)
//TIME COMPLEXITY: O(NlogN) or O(N^2) depending on whether count takes logN or N time. 
//TIME COMPLEXITY: O(N) using unordered multiset

multiset <int> ms;      //try using unordered multiset
        int pairs = 0;
        for(int i=0; i<n; i++)
        {
            ms.insert(arr[i]);
        }
        auto it = ms.begin();
        for(; it!=ms.end(); it++)
        {
            if(k%2 == 0)
            {
                if(*it == k/2)
                 continue;
            }
            pairs += ms.count(k - *it);
        }
        pairs = pairs/2;
        if(k%2 == 0)
            {
                if(ms.count(k/2) != 0)
                {
                    int x = ms.count(k/2);
                    pairs += (x*(x-1))/2;
                }
            }
        
        return pairs;



//A more efficient solution
//create a map and keep a record of number of times each element occurs in an array.
//in other words keep track of frequency of every element.
//traverse again and add the frequency of the corresponding element required for 
//making the pair be it zero or whatever.
//as in previous case take care when arr[i] == k/2
//divide the pairs by 2 as they are counted twice. 
//SPACE COMPLEXITY: O(N)
//TIME COMPLEXITY: O(N)


 unordered_map <int,int> m;
        for(int i=0; i<n; i++)
        {
            m[arr[i]]++;     //recording frequency of every element
        }
        int pairs = 0;
        for(int i=0; i<n; i++)
        {
            pairs += m[k-arr[i]];
            
            if(2*arr[i] == k)
                pairs--;
        }
        pairs /= 2;
        return pairs;


//same approach as above but done in one loop
//exploiting the fact that count will not increase when first element of pair is 
//inserted but will increase when the other element is inserted.

unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(k - arr[i]) != m.end()) {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;        


//we can sort the array and use two pointer method also.
//time comlpexity: O(NlogN)
//space complexity: O(1)
//see Q27. triplets that sum to a given number for its implementation.

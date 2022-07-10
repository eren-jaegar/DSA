/*
Approach - 1
we can use brute force approach, use two nested for loops to find the smallest greater 
element for each element.

Time Complexity: O(N^2)
Space Complexity: O(1) */



/*
Approach - 2
we can start iterating from the back of the array while pushing elements in a set.
then we check for upper_bound for the current element. if it is found then put that value
in the array. if it is not found then put -1 in the array.

Time Complexity: O(NlogN) //insertion of N elements in set takes NlogN time
Space Complexity: O(N) */

//NOTE: we don't need to use multiset for duplicate elements as we iterating from the back
//and using upper_bound so, it won't matter if the number already exists.

class Solution{
    public:
    
    void solve(vector <int> &arr)
    {
        set <int> nums;
        auto it = nums.begin();
        for(int i=arr.size()-1; i>=0; i--)
        {
            nums.insert(arr[i]);
            it = nums.upper_bound(arr[i]);
            if(it == nums.end())
                arr[i] = -1;
            else
                arr[i] = *it;
        }
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        solve(arr);
        return arr;
        
    }
};



/*
Approach - 3
we first make a vector of pairs where the first element is in pair is the element itself
and the second element in pair is the index of that element.
Now sort this vector of pairs. in case there are duplicates, it is necessary that we
put the duplicate with higher index first and then the one with lower index so to
achieve this, we have to write a custom comparator function.
now that we have sorted this vector, we start iterating it and putting its element in a
stack, for every element we check if the index of the top element of stack is less than
the index of the current element, if so, then the current element is the smallest greater
element than the top element of stack. so, we put the current element at the index of the
top element of stack and then pop the top element.

This works because in the vector of pairs, the elements are already sorted so if we just
need to find the first index that is greater than the index of the current element.
as the vector is sorted so the element that we find will already be the smallest greater
element than the current element, checking index just ensures that is lies on the right and
not on the left.

Time Complexity: O(NlogN) //sorting takes NlogN time
Space Complexity: O(N) */


class Solution{
    public:
    
    vector <int> usingstack(vector <pair <int,int> > &pairs, int n)
    {
        stack <int> nums;
        vector <int> res(n, -1);
        for(int i=0; i<n; i++)
        {
            while(!nums.empty() && nums.top() < pairs[i].second)
            {
                res[nums.top()] = pairs[i].first;
                nums.pop();
            }
            nums.push(pairs[i].second);
        }
        return res;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        vector <pair <int,int> > pairs(n);
        for(int i=0; i<n; i++)
        {
            pairs[i].first = arr[i];
            pairs[i].second = i;
        }
        sort(pairs.begin(), pairs.end(), [](pair <int,int> a, pair <int,int> b){ //custom function for sorting
        if(a.first < b.first)
            return true;
        if(a.first == b.first)
            return a.second > b.second;
        return false;
    });
        
        vector <int> ans = usingstack(pairs, n);
        return ans;
    }
};
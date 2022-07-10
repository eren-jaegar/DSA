//just put all the elements in an unordered multiset and check the count of element.
//if count of element of a2 is greater than count of same element in a1 then a2 is not
//a subset of a1 else it is.
//time complexity: O(N+M) probably?
//space complexity: O(N+M)


unordered_multiset <int> ums1;
    unordered_multiset <int> ums2;
    int x;
    bool ft = false;
    if(n < m)
        ft = true;
    else
    {
        for(int i=0; i<m; i++)
        {
            ums1.insert(a2[i]);
        }
        for(int i=0; i<n; i++)
        {
            ums2.insert(a1[i]);
        }
        auto it = ums1.begin();
        for(; it != ums1.end();)
        {
            x = ums1.count(*it);
            if(x > ums2.count(*it))
            {
                ft = true;
                break;
            }
            advance(it,x);
        }
    }
   
    string s;
    if(ft)
        s = "No";
    else
        s = "Yes";
    return s;



//another better approach is to just use unordered map and store the frequencies of
//elements of a1. then iterate through a2 and if the frequency of the current element
//is zero then a2 is not a sunset else reduce the frequency by 1;
//time complexity is O(N+M)
//space complexity is O(N)


unordered_map <int,int> um;
    int x;
    bool ft = false;
    if(n < m)
        ft = true;
    else
    {
        for(int i=0; i<n; i++)
        {
            um[a1[i]]++;
        }
        for(int i=0; i<m; i++)
        {
            if(um[a2[i]] <= 0)
            {
                ft = true;
                break;
            }
            else
                um[a2[i]]--;
        }
    }
   
    string s;
    if(ft)
        s = "No";
    else
        s = "Yes";
    return s;



//another approach is to use sort and then follow the algorithm to merge two sorted
//arrays i.e. by comparing elements in both the arrys one by one.
//if both the elements are equal then proceed in both arrays
//if element in a1 is smaller then proceed in a1 only as it may be the case that
//a1 has more duplicates of an element than a2
//if element in a2 is smaller than element in a1 then a2 is not a subset.    
//time complexity: O(mLogm + nLogn)
//space complexity: O(1)

bool ft = false;
    sort(a1, a1+n);
    sort(a2, a2+m);
     int i = 0;
     int j = 0;
     while(i<n && j<m)
     {
         if(a1[i] == a2[j])
         {
             i++;
             j++;
         }
         else if(a1[i] < a2[j])
            i++;
         else
         {
             ft = true;
             break;
         }
     }
     ft = (j < m) ? true : false;
     
     return (ft) ? "No" : "Yes";
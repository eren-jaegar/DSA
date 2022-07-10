//the idea is simple. store all the elements in a set and then check if the difference
//of consecutive elements is 1. if it is 1 then counter++ else counter = 1;
//time complexity is probably NlogN and space complexity is N

//same could have been done by sorting the array and removing the duplicates.
//time complexity would have been NlogN because of sorting and space complexity
//will depend on how much space sort uses.

set <int> s;
      for(int i=0; i<N; i++)
      {
          s.insert(arr[i]);
      }
      auto it1 = s.begin();
      auto it2 = s.begin();
      it2++;
      int count = 1;
      int ans = 1;
      for(; it2 != s.end(); )
      {
          if(*it2-*it1 == 1)
          {
              count++;
              it2++;
              it1++;
          }
          else
          {
              count = 1;
              it2++;
              it1++;
          }
          ans = max(ans,count);
      }
      return ans;



//another approach is to use unordered map. 
//put all the elements in an unordered map. then check for all elements if element-1
//is present or not. if it is not present then the current element is the start of its
//sequence. start checking for sequence and increase count by 1 till the sequence
//is found.
//in case element-1 was present then skip that element as it is not the start of its
//sequence and hence will be covered later in its own sequence.
//ex: in {1,2,3}, for 1, 0 is not present so 1 is start of its sequence but for 2, 1 
//is present so we skip it as 2 will be considered when 1,2,3 sequence is considered.

//time complexity is O(N) assuming that insertion in unordered set takes constant time
//space complexity is O(N)   




unordered_set <int> us;
      for(int i=0; i<N; i++)
      {
          us.insert(arr[i]);
      }
      auto it = us.begin();
      int a;
      int count = 1;
      int ans = 1;
      for(; it!=us.end(); it++)
      {
          a = *it;
          count = 1;
          if(us.find(a-1) == us.end())
          {
              while(us.find(a+1) != us.end())
              {
                  count++;
                  a++;
              }
              ans = max(ans,count);
          }
      }
      return ans;
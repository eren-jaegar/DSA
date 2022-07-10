//same as reversing an array
//time comlexity: O(N)
//space complexity: O(1)


for(int i=0; i<s.size()/2; i++)  //notice that condition is <s.size()/2 and not s.size()
        {
            swap(s[i], s[s.size()-1-i]);
        }
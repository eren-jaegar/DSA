//just like for finding common elements in 2 sorted arrays, first find common elements
//in first two sorted arrays and store them in a dummy vector.
//then find common elements in dummy vector and the third sorted array.
//both time and space complexity are linear.

vector <int> dummy;
            vector <int> ans;
            int i=0;
            int j=0;
            for(; (i<n1)&&(j<n2); )
            {
                if(A[i] < B[j])
                    i++;
                else if(A[i] > B[j])
                    j++;
                else
                {
                    dummy.push_back(A[i]);
                    i++;
                    j++;
                }
            }
            i=0;
            j=0;
            for(; (i<dummy.size())&&(j<n3); )
            {
                if(dummy[i] < C[j])
                    i++;
                else if(dummy[i] > C[j])
                    j++;
                else
                {
                    ans.push_back(C[j]);
                    i++;
                    j++;
                }
            }
            if(ans.size() > 1)
            {
                for(i=0; i<(ans.size()-1); )
                {
                    if(ans[i] == ans[i+1])
                        ans.erase(ans.begin()+i+1);
                    else
                        i++;
                }
            }
            return ans;

//METHOD-2
//same approach as above but we iterate all the 3 arrays together.
//it doesnt use any extra space as no dummy vector is required to store the common
//elements of first two arrays.
//time complexity is linear and space complexity is constant(only one vector for
//returning answer is required).

 vector <int> ans;
            int last = INT_MIN;
            for(int i=0,j=0,k=0; i<n1&&j<n2&&k<n3;)
            {
                while(A[i] == last)
                i++;
                while(B[j] == last)
                j++;
                while(C[k] == last)
                k++;
                
                if(A[i] < B[j])
                i++;
                else if(B[j] < C[k])
                j++;
                else if(C[k] < B[j] || C[k] < A[i])
                k++;
                else
                {
                    ans.push_back(A[i]);
                    last = A[i];
                    i++;
                    j++;
                    k++;
                }
            }
            return ans;


//in other approaches you could use sets or binary search or even maps(after removing
//duplicates from the arrays) to keep a count of frequency(only in case of maps).
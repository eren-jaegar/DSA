//create a frequency hash map
//now start iterating the array. for each element run a nested for loop starting at the
//current element and ending at the last element.
//using this nested for loop, check whether there exists two numbers whose sum is
//equal to X-A[i]. do this using the frequency hash map.
//X is the required sum and arr[i] is the current element in the outer loop for which
//the nested loop is running.
//time complexity: O(N^2)
//space complexity: O(N)

unordered_map <int,int> um;
    for(int i=0; i<n; i++)
    {
        um[A[i]]++;
    }
    int a;
    bool ans = false;
    for(int i=0; i<n; i++)
    {
        um[A[i]]--;
        a = X - A[i];
        for(int j=i+1; j<n; j++)
        {
            if(a%2 == 0)
            {
                if(a/2 == A[j])
                {
                    if(um[a-A[j]] < 2)
                    {
                        continue;
                    }
                }
            }
            if(um[a-A[j]] > 0)
            {
                ans = true;
                break;
            }
        }
        
        if(ans)
            break;
        um[A[i]]++;
    }
    return ans;


//another solution for O(1) space complexity is as follows:
//sort the array and then use two pointer method.
//for two pointer method we use nested for loops
//first loop iterated through the entire array. we store X-A[i] in a variable(here a)
//now using two pointer(in case of array pointers are not exclusively needed as we
//can access elements using []), we set the first pointer to i+1th element and second
//pointer to last element.
//now if the sum of these two elements is less than a, then we increase the first
//pointer by 1 as it is the only way to increase the sum
//similarly if their sum is greater than a then we decrease the second pointer by 1.
//if the sum of current elements pointer by the pointers is less than a and even if
//we could increase second pointer by 1, we still don't increase it but instead
//increase the first pointer only. This is because if we increase the second pointer
//then the sum will exceed a. The sum will exceed a because before the second pointer
//was decreased to point at the current element, it was pointing at the element next to
//the current element. lets call this next element x.
//now, the sum with x and the element pointed by first pointer would have been greater
//than a, thats why second pointer was decreased by 1.
//so if we increase the second pointer by 1 so that it points at a then we are reverting 
//to the previous situation and hence the sum will become greater than a.
//similar argument applies to why we only decrease the second pointer and not the first
//when sum is greater than a.


//thoda sochle, samjhna mushkil nhi hai


//time complexity: O(NlogN) (because of sorting) + O(N^2) (due to nested for loop)
//time complexity: O(N^2)
//space complexity: O(1)


sort(A, A+n);
        bool ans = false;
        int a;
        int j;
        int k;
        for(int i=0; i<n; i++)
        {
            a = X - A[i];
            j = i + 1;
            k = n - 1;
            while(j < k)
            {
                if((A[j] + A[k]) == a)
                {
                    ans = true;
                    break;
                }
                else if((A[j] + A[k]) < a)
                    j++;
                else
                    k--;
            }
            if(ans)
                break;
        }
        return ans;


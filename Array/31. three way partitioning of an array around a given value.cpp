//easy solution
//just iterate once from beginning to end while mainting two pointers.
//first pointer iterates over the entire array and the second pointer marks the
//position for the swap. bith begin at index 0.
//if the element pointed by first pointer is <a then swap it with the element pointed 
//by the second pointer and in this case increase the second pointer by 1.
//repeat the same process but from ending to beginning for swapping elements >b.
//both the pointers will start from end and move towards index 0.
//elements a<= and <=b will automatically come in between this way

//TAKE CARE: for elements >b we can't iterate from beginning as it is possible that
//when we swap the elments, the element that comes in place of first pointer after
//swapping is still >b. And hence it will get skipped from sorting as pointer 1 will
//move forward. ex: {1,2,3,4,10,7,8,11,12} lets assume a = 5 and b = 9. so in this
//scenario if we iterate from beginning to sort elements >b then, 10 and 12 will get
//swapped and then pointer 1 will move forward to point at 7. This way 12 will be skipped
//from sorting and our answer gets wrong.
//Time complexity: O(N).
//Space complexity: O(1).

int k = 0;
        for(int i=0; i<array.size(); i++)
        {
            if(array[i] < a)
            {
                swap(array[k], array[i]);
                k++;
            }
        }
        k = array.size() - 1;
        for(int i=array.size()-1; i>=0; i--)
        {
            if(array[i] > b)
            {
                swap(array[k], array[i]);
                k--;
            }
        }


//another east approach is to just sort the array.
//time complexity: O(NlogN)

 sort(array.begin(), array.end());



//same approach as 1st method, but only one traversal of the array is needed.

 int j = 0;
        int n = array.size();
        int k = n-1;
        for(int i=0; i<=k; i++)
        {
            while(array[k] > b && k>i)
                k--;
            if(array[i] > b)
            {
                swap(array[i], array[k]);
                k--;
            }
            if(array[i] < a)
            {
                swap(array[j], array[i]);
                j++;
            }
        }



//same approach, different implementation


        int start = 0, end = array.size()-1;
 
    // Traverse elements from left
    for (int i=0; i<=end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (array[i] < a)
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else
            swap(array[i++], array[start++]);
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (array[i] > b)
            swap(array[i], array[end--]);
 
        else
            i++;
    }
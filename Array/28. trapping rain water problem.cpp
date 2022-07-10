//brute force solution is to find the buildings with the maximum heights on both
//the left and right of the current element.
//let leftmax be the height of the tallest building to the left of i.
//let rightmax be the height of the tallest building to right of i
//water stored at index i is equal to min(leftmax,rightmax) - a[i]
//an entire traversal is required for each element so time complexity is O(N^2).
//space complexity is O(1).


//MY SOLUTION
//first find the maximum height, then iterate once from 0 to index of max height and 
//then from n-1 to index of max height.
//in each of these iterations, use a nested loop. lets discuss first iteration.
//if you encounter a building with greater height than the arr[i], then stop and add 
//arr[i]*(j-i-1) as it will be the water held if all the elements between i and j were
//0. then subtract sum of all the elements between i and j.
//this will give actual amount of water held betwwen i and j
//do this until you reach index of max height and then repeat the same process 
//with index from n-1 to index of max height.

//time complexity: O(N)
//space complexity: O(1)


long long int sum = 0;
        long long int ans = 0;
        int maximum = 0;
        int maxindex = 0;
        for(int i=0; i<n; i++)
        {
            maximum = max(arr[i], maximum);
            if(maximum == arr[i])
                maxindex = i;
        }
        if(maximum == 0)
            return ans;
        long long int j; //pay attention that j is long long int instead of int
        for(long long int i=0; i<maxindex; i++)  //pay attention that i is
        {                                        //long long int instead of int
            sum = 0;
            j = i+1;
            while((arr[i] > arr[j]) && (j < maxindex))
            {
                sum += arr[j];
                j++;
            }
            ans += arr[i]*(j-i-1); //i and j are long long int so that it does not 
            ans -= sum; //overflow in the above expression on line 47.
            i = j-1; //arr[i] is int so i and j needs to be long long to be able to
        } //keep the result of multiplication within range as it is out of range of int
        for(long long int i=n-1; i>maxindex; i--)  
        {                                         
            sum = 0;
            j = i-1;
            while((arr[i] > arr[j]) && (j > maxindex))
            {
                sum += arr[j];
                j--;
            }
            ans += arr[i]*(i-j-1);
            ans -= sum;
            i = j+1;
        }
        return ans;



//another solution where only one traversal is required instead of 3 traversals.
//in this if you are entering into the first if condition then it is ensured that 
//leftmax in <= rightmax as leftmax will be updated only when arr[l] is <= arr[r]
//ensuring that there exists a building which is equal to or greater in height 
//than the current leftmax.
//since current leftmax is the height of the tallest building to the right of current 
//element and leftmax <= rightmax so this ensures that leftmax = min(leftmax,rightmax).
//hence, we can add leftmax - arr[i] to res.
//though building with the maximum height to the right of the current building can either
//be greater or equal to current rightmax.
//same logic works for the else condition of this if condition.


int l = 0;
        int r = n-1;
        int leftmax = arr[l];
        int rightmax = arr[r];
        long long int res = 0;
        while(l<r)
        {
            if(arr[l] <= arr[r])
            {
                if(leftmax < arr[l])
                    leftmax = arr[l];
                else
                {
                    res += (leftmax - arr[l]);
                    l++;
                }
            }
            else
            {
                if(rightmax < arr[r])
                    rightmax = arr[r];
                else
                {
                    res += (rightmax - arr[r]);
                    r--;
                }
            }
        }
        return res; 
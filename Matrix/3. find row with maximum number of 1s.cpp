//brute force approach
//iterate in every row and find no. of zeroes ans then number of 1s is given by
//m - no. of zeroes.

//TIME COMPLEXITY: O(N*M)
//SPACE COMPLEXITY: O(1)


	    int i;
	    int count = 0;
	    int dummy = -1;
	    int ans;
	    
	    for(i=0; i<n; i++)
	    {
	        int j=0;
	        while(j<m && arr[i][j] == 0)
	            j++;
	        count = max(count,m-j);
	        if(dummy != count)
	        {
	            ans = i;
	        }
	        dummy = count;
	    }
	    if(count == 0)
	        return -1;
	    return ans;

//since every row is sorted, so a better approach is to use binary search in every row
//to find the index of the first one using which we can calculate the number of 1s.
//number if 1s = m-index of first 1.

//TIME COMPLEXITY: O(N*logM)
//SPACE COMPLEXITY: O(1)

        int low = 0;
        int high = m-1;
        int mid;
        int count = 0;
        int dummy = -1;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            low = 0;
            high = m-1;
            while(arr[i][low] != 1 && low<high)
            {
                mid = (high+low)/2;
                if(arr[i][mid] == 0)
                    low = mid+1;
                else
                    high = mid;
            }
            if(arr[i][low] == 1)
                count = max(count,m-low);
            if(count != dummy)
                ans = i;
            dummy = count;
        }
        if(count == 0)
            return -1;
        else
            return ans;


//best approach is to find the index of last 0(can find index of first 1 also) in the first row and then move to the second 
//row. now, check at the index in the second row. if its 0 then skip because
//it cant have more number of 1s then the first row. if it has 1 then keep going back
//till you hit 0 and now we have the index of the last 0 in this row.
//keep doing this till the end.

//since we can only go back m number of times at max. and we iterate through n rows so,

//TIME COMPLEXITY: O(N+M)
//SPACE COMPLEXITY: O(1)

	    int index = m-1;
	    int dummy = m;
	    int ans;
	    
	    for(int i=0; i<n; i++)
	    {
	        while(arr[i][index] == 1)
	            index--;
	        if(dummy != index)
	            ans = i;
	        dummy = index;
	    }
	    if(index == m-1)
	        return -1;
	    else
	        return ans;


//Another solution more efficient than the second solution but less efficient than the 
//third solution is to find the index of first 1 in a row and then apply binary search 
//between 0 and that index in the next row.
//Do this for all the rows.
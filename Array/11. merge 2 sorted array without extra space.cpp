//start comparing last elements of arr1 with starting elements of arr2.
//as long as arr1 as greater elements, switch them with elements of arr2.
//sort both the arrays

	    int i=n-1;
	    int j=0;
	    for(; ((j < m)&&(i >= 0));)
	    {
	        if(arr2[j] < arr1[i])
	        {
	            swap(arr2[j],arr1[i]);
	            j++;
	            i--;
	        }
	        else
	            break;
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);


//for linear time and linear space complexity.

	    int arr3[n+m];
	    int i,j,k=0;
	    for(i=0,j=0; i<n && j<m;)
	    {
	        if(arr1[i] <= arr2[j])
	        {
	            arr3[k] = arr1[i];
	            i++;
	            k++;
	        }
	        else
	        {
	            arr3[k] = arr2[j];
	            k++;
	            j++;
	        }
	    }
	    if(i == n)
	    {
	        while(j != m)
	        {
	            arr3[k] = arr2[j];
	            k++;
	            j++;
	        }
	    }
	    if(j == m)
	    {
	        while(i != n)
	        {
	            arr3[k] = arr1[i];
	            k++;
	            i++;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        arr1[i] = arr3[i];
	    }
	    for(int i=0; i<m; i++)
	    {
	        arr2[i] = arr3[i+n];
	    }



//GAP METHOD
//first gap is taken as ceil((float)(n+m)/2).
//then successive gaps are taken as ceil((float)a/2).
//for each gap set one pointer at starting of 1st array and second pointer
//at pos. of first pointer+a.
//if a exceeds lenght of first array then jump to second array.
//now move both the pointer by one while switching elements if *p1>*p2.
//do this till second pointer reaches the end of second array.
//continue doing this until you are done once with a=1.
//array will be sorted.

	    int a = ceil((float)(n+m)/2);
	    int* p1 = arr1;
	    int* p2 = arr1;
	    while(a>=1)
	    {
	        p1 = arr1;
	        p2 = arr1;
	        if(a > n-1)
	        {
	            int b = a - n + 1;
	            b--;
	            p2 = arr2 + b;
	        }
	        else
	            advance(p2,a);
	        
	        while(p2 != arr2+m)
	        {
	            if(p2 == arr1+n)
	            {
	                p2 = arr2;
	            }
	            
	            if(p1 == arr1+n)
	            {
	                p1 = arr2;
	            }
	            if(*p1 > *p2)
	                swap(*p1,*p2);
	                p1++;
	                p2++;
	        }
	        if(a == 1)
	            a = 0;
	        a = ceil((float)a/2);
	    }
//first, i have counted the number of negative elements between the beginning of 
//array and the first zero, between zeores, and between last zero and ending of
//array.

//this is because 0 divide our subarrays. if we take 0 in a subarray then the product
//will be zero. hence, the zeroes play the role of dividing the subarrays.

//if the number of negative numbers between the above defined intervals is even
//then we can multiply all the numbers between that interval to get a the maximum
//product for that subarray.

//in case the number of negative elements is odd, then the maximum product within that
//subarray will be either the product of all the numbers before the last negative 
//number or the product of all the numbers after first negative number.
//this is because, we want even number of negative numbers in our product to make it
//positive.

//take maximum of prod2 and ans after every case.

//this entire process is covered in the last for loop.

//time complexity: O(N)
//space complexity: O(N) or rather number of zeroes + 1



long long int prod1 = 1;
	    long long int prod2 = 1;
	    long long int ans = LLONG_MIN;
	    long long int count = 0;
	    vector <int> neg;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i] < 0)
	            count++;
	        if(arr[i] == 0)
	        {
	            neg.push_back(count);
	            count = 0;
	        }
	    }
	    neg.push_back(count);
	    int j = 0;
	    
	    if(n == 1)
	    {
	        return arr[0];
	    }
	    long long int count3 = 0;
	    long long int count2 = 0;
	    long long int count1 = 0;
	    for(int i=0; i<n; i++)  //here we counter cases where we have only non-positive
	    {                       //numbers. if the numbers are non-positive and such
	        if(arr[i] > 0)      //that no two negative numbers are next to each other  
	        count3++;           //i.e. negative numbers are separated by 0s between
	        if(arr[i] < 0)      //them. then the max product subarray will be 0 but the
	        {                   //code below gives the answer as 1 because of 
	            count1++;       //prod2 /= x; this expression and hence is has
	            if(i!=0 && arr[i-1] != 0) //been dealt here separately.
	                break;
	            else if(i!=n-1 && arr[i+1] != 0)
	                break;
	            else
	                count2++;
	        }
	    }
	    if(count2 == count1 && count3 == 0)
	        return 0;
	    
	    for(int i=0; i<n; )
	    {
	        if(arr[i] == 0)
	        {
	            prod2 = 1;
	            prod1 = 1;
	            i++;
	            j++;
	            continue;
	        }
	        if(neg[j]%2 == 0 && j<neg.size())
	        {
	            while(neg[j] > 0 && i != n)
	            {
	                if(arr[i] < 0)
	                    neg[j]--;
	                prod2 *= arr[i];
	                i++;
	            }
	            while(arr[i] != 0 && i != n)
	            {
	                prod2 *= arr[i];
	                i++;
	            }
	        }
	        else
	        {
	            long long int dummy = neg[j];
	            long long int x;
	            while(neg[j] > 0)
	            {
	                if(dummy == neg[j])
	                {
	                    prod1 *= arr[i];
	                }
	                prod2 *= arr[i];
	                if(arr[i] < 0)
	                {
	                    neg[j]--;
	                    x = arr[i];
	                }
	                i++;
	            }
	            prod2 /= x;
	            ans = max(ans,prod2);
	            prod2 *= x;
	            prod2 /= prod1;
	            while(arr[i] != 0 && i != n)
	            {
	                prod2 *= arr[i];
	                i++;
	            }
	        }
	        ans = max(ans,prod2);
	    }
	    return ans;




//a better solution is to use kadane's algorithm and do it just like in the case of
//maximum sum subarray

//for every index, the maximum product ending there will be 
//max(arr[i], maxprod*arr[i], minprod*arr[i])
//and minimum product ending at that index will be 
//min(arr[i], maxprod*arr[i], minprod*arr[i])


//time comlpexity: O(N)
//space complexity: O(1)

long long int maxprod = arr[0];
	    long long int minprod = arr[0];
	    long long int ans = arr[0];
	    long long int temp;
	    
	    for(int i=1; i<n; i++)
	    {
	        temp = max((long long int)arr[i], max(maxprod*arr[i], minprod*arr[i]));
	        
	        //we use temp because we have to use maxprod to calculate minprod as well
	        //before we can update maxprod.

	        minprod = min((long long int)arr[i], min(maxprod*arr[i], minprod*arr[i]));
	        maxprod = temp;
	        ans = max(ans,maxprod);
	    }
	    return ans;


//another similar application of kadane's algorithm is as follows:
//we just keep record of maxprod and minprod till the current index and in case the current number 
//is negative, we swap maxprod and minprod as (minprod*neg number) will give maxprod and vice versa

//time comlpexity: O(N)
//space complexity: O(1)

long long int maxprod = arr[0];
	    long long int minprod = arr[0];
	    long long int ans = arr[0];
	    
	    for(int i=1; i<n; i++)
	    {
	        if(arr[i] < 0)
	        {
	            swap(maxprod,minprod);
	        }
	        
	        maxprod = max((long long int)arr[i], maxprod*arr[i]);
	        minprod = min((long long int)arr[i], minprod*arr[i]);
	        
	        ans = max(ans, maxprod);
	    }





//another solution is to use two traversals, one forward traversal and the other 
//backward traversal. 
//in my original solution(the first solution), i had to deal with odd number of
//negative numbers between two intervals and the answer from them can be obtained 
//by either considering all the elements after first negative number or by
//considering all the numbers before last negative number. same thing can be
//achieved by forward and backward traversal.
//in forward traversal, i will get product if we dont consider numbers after last neg number
//and in backward travel, we will get product if we dont consider numbers before the
//first negative numbers.


	    long long int maxfwd = 1;
	    long long int minbkwd = 1;
	    long long int ans = LLONG_MIN;
	    
	    for(int i=0; i<n; i++)
	    {
	        maxfwd *= arr[i]; 
	        ans = max(ans, maxfwd);
	        if(arr[i] == 0)
	            maxfwd = 1;
	    }
	    
	    for(int i=n-1; i>=0; i--)
	    {
	        minbkwd *= arr[i];
	        ans = max(ans, minbkwd);
	        if(arr[i] == 0)
	            minbkwd = 1;
	    }
	    
	    return ans;
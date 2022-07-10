//save all the positive numbers in one array and negative in another then place
//them alternatively in the original array
//both time and space complexity are linear.


vector <int> pos;
	    vector <int> neg;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i] < 0)
	        neg.push_back(arr[i]);
	        else
	        pos.push_back(arr[i]);
	    }
	    int i,j,k;
	    for(i=0,j=0,k=0; i<n && k<neg.size() && j<pos.size(); i++)
	    {
	        if(i%2 == 0)
	        {
	            arr[i] = pos[j];
	            j++;
	        }
	        else
	        {
	            arr[i] = neg[k];
	            k++;
	        }
	    }
	    if(j == pos.size() && i!=n)
	    {
	        while(i < n && k<neg.size())
	        {
	            arr[i] = neg[k];
	            i++;
	            k++;
	        }
	    }
	    if(k == neg.size() && i!=n)
	    {
	        while(i < n && j<pos.size())
	        {
	            arr[i] = pos[j];
	            i++;
	            j++;
	        }
	    }

//another solution to do this in constant space is as follows:
//though its time complexity is O(N^2);
//check if the number at even index is positive or not. in case it is not positive,
//then check for the next positive number from that index(found using j in the code) 
//and then rotate this subarray once to the right. 
//similarly do for odd index and negative numbers.


int i,j=0;
	    for(i=0; i<n; i++)
	    { 
	        j=i;
	        if(i%2 == 0)
	        {
	            if(arr[i] >= 0)
	            continue;
	            else
	            {
	                while(j<n && arr[j] < 0)
	                j++;
	                if(j == n)
	                break;
	                int a = arr[j];
	                int k=j;
	                for(; k>i; k--)
	                {
	                    arr[k] = arr[k-1];
	                }
	                arr[i] = a;
	            }
	        }
	        else
	        {
	            if(arr[i] < 0)
	            continue;
	            else
	            {
	                while(j<n && arr[j] >= 0)
	                j++;
	                if(j == n)
	                break;
	                int a = arr[j];
	                int k = j;
	                for(; k>i; k--)
	                arr[k] = arr[k-1];
	                arr[i] = a;
	            }
	        }
	    }



//if you dont have to preserve the order then first push all the negative elements to 
//last and then swap alternatingly.
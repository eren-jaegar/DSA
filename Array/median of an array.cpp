//just sort the array and if its size is odd then return the miidle element else
//return the average of the two middle elements.

//time complexity: O(NlogN)
//space complexity: O(1)

sort(v.begin(), v.end());
		    if(v.size()%2 != 0)
		    {
		        return v[v.size()/2];
		    }
		    else
		    {
		        return (v[v.size()/2] + v[v.size()/2 - 1])/2;
		    }
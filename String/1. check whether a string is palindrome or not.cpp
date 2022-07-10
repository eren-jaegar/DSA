//just start matching elements from front and back.
//break the loop if any mismatch is encountered.
//check if the loop ran completely or was broken midway.

int i = 0;
	    int n = S.size();
	    for(; i<n/2; i++)
	    {
	        if(S[i] != S[n - 1 - i])
	            break;
	    }
	    if(i < n/2)
	        return 0;
	    else
	        return 1;
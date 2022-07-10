/*
Approach - 1
first check if N>=M. if not then we can't survive on the island.
if yes then we can survive for atleast 6 days.
to check if we can survive for more than 6 days, we have to get through sunday.
so, check if 6*N>=7*M. if yes, then we can surive for any number of days else we can't make
it through sunday, hence we can't survive for more tha 6 days.
numbes of days fro which we have to but food will be found as folows:

ans*N>=S*M => ans = ceil(S*M/N)

Time Complexity: O(1)
Space Complexity: O(1) */

class Solution{
public:
    int minimumDays(int S, int N, int M){
        
        int days = 0;
        if(N/M < 1)
            return -1;
        if(S<=6)
        {
            days = ceil(S*1.0*M/N);
        }
        else
        {
            if(6*N-7*M < 0)
                return -1;
            days = ceil(S*1.0*M/N);
        }
        return days;
    }
};
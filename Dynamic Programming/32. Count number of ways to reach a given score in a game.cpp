/*
Approach - 1
we do not have to consider permutations so, we do not go by standard dp.
we create a 1-D table.
first iterate for 3 then for 5 and then for 10.
this ensures that first we are finding all the possible ways to reach a number using only 3.
then when we iterate for 5 then we get all possible ways to reach a number using both 3 and 5.
here we only get combinations of 3 and 5 but not permutations.
then we iterate for 10 also and get all possible combinations to reach a number using 3,5,10.


Time Complexity: O(N)
Space Complexity: O(N) */

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
    long long int a;
	for(int i=1; i<=3; i++)
	{
	    if(i==1)
	        a=3;
	    else if(i==2)
	        a=5;
	    else
	        a=10;
	    for(int j=a; j<=n; j++)
	    {
	        table[j] += table[j-a];
	    }
	}
	
	return table[n];
}
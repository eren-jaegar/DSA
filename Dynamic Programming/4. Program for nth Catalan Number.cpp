/*
Approach - 1
we have to find the Nth catalan number.

we use the recursion relation: 
summation(t(i-1)*t(n-i)) for i from 1 to n.

Time Complexity: O(N*N)
Space Complexity: O(N) */



/*
Approach - 2
or we can directly find the number using (2nCn)/(n+1)

Time Complexity: O(N)
Space Complexity: O(N)
/*
Approach - 1

for recursion of lcs, we only need the previous row and the current row instead of the
entire row.

so we store only two rows.

we use a bool variable to keep track of current row.

bool bi = i & 1; //it keeps alternating between the two rows.


Time Complexity: O(N*M)
Space Complexity: O(min(N,M)) */
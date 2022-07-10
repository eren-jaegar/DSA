/*
Approach - 1

we can either take the current and not tkae the its children but take its grandchildren.
or we can just not take the current node and take its children.

so we create a recursion using this.

f(x) = max(f(x->left)+f(x->right), 1+f(x->left->left)+f(x->left->right)+f(x->right->left)+f(x->right->right))

using this recursive relation and memoization, we can solve it.


Time Complexity: O(N)
Space Complexity: O(N) */



/*
Approach - 2
we can also create a 2-D matrix which stores value for LIS when the current node is chosen
and when the current node is not chosen.


Time Complexity: O(N)
Space Complexity: O(N) */
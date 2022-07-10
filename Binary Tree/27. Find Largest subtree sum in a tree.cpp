/*Approach - 1
call a recursive function which calls itself to find the sum of the left subtree and the
right subtree for the current node.
then sum of subtree rooted at current node will be equal to sum of node value+sum of left
subtree+sum of right subtree.
compare with max sum till now and then return the sum of the current subtree.

Time Complexity: O(N)
Space Complexity: O(N) */
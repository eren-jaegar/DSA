/*Approach - 1
just call a recursive function which calls itself to find the sum of the current node's left
subtree and right subtree.
update the node's value as sum of its left subtree and right subtree and then return the
sum of node's new value and old value.

Time Complexity: O(N)
Space Complexity: O(height of tree) */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sumtreerecursion(Node* root)
    {
        if(root == NULL)
            return 0;
        int a = root->data;
        int x = sumtreerecursion(root->left);
        int y = sumtreerecursion(root->right);
        root->data = x+y;
        return a+x+y;
    }
    
    void toSumTree(Node *node)
    {
        sumtreerecursion(node);
    }
};
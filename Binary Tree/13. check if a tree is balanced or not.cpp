/*
Approach - 1
we use a recursive function which calculates the height of the tree by calculating height of
the left subtree and height of the right subtree.
so for every subtree we can check if the difference between the heights is <=1 or not.
if not then we make condition false else it remains true.

Time Complexity: O(N)
Space Complexity: O(N) */


class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root, bool &condition)
    {
        if(root == NULL)
            return 0;
        int x = height(root->left, condition);
        int y = height(root->right, condition);
        
        if(max(x,y) - min(x,y) > 1)
            condition = false;
        return 1+max(x,y);
    }
    
    bool isBalanced(Node *root)
    {
        bool ans = true;
        height(root, ans);
        return ans;
    }
};
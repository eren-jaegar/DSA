/*Approach - 1
just call a recursive function which calls upon itself to find the sum of left and right
subtree of the current node.
two special cases are dealth with:
1) when current node is leaf node, don't call the function for its left subtree and right
subtree sum as the node is itself balanced so just return the node->data
2)in case current node has only 1 child the other child will be call the function for NULL
so just return 0 in case the node for which function is called is NULL.
after recieving sum of both subtrees check if they are equal to the current node->data
or not. then return sum of both subtrees + sum of current node->data.

Time Complexity: O(N)
Space Complexity: O(height of the tree) */

class Solution
{
    public:
    
    int sumtree(Node* root, bool* ans)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->data;
        int a = sumtree(root->left, ans);
        int b = sumtree(root->right, ans);
        if(root->data != a+b)
            *ans = false;
        return a+b+root->data;
    }
    
    bool isSumTree(Node* root)
    {
        bool ans = true;
        sumtree(root, &ans);
        return ans;
    }
};
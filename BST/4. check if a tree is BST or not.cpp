/*
Approach - 1
do inorder traversal while keeping record of the previous number.
in case the current number is less than equal to the previous number then it is not a BST

Time Complexity: O(N)
Space Complexity: O(height) //recursion stack uses space */

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    void inorder(Node* root, bool &ans, int &num)
    {
        static int count = 0;
        if(root == NULL)
            return;
            
        inorder(root->left, ans, num);
        if(count == 0)
            num = root->data;
        else
        {
            if(root->data <= num)
                ans = false;
            num = root->data;
        }
        count++;
        inorder(root->right, ans, num);
    }
    
    bool isBST(Node* root) 
    {
        bool ans = true;
        int num = 0;
        inorder(root, ans, num);
        return ans;
    }
};



/*
Approach - 2
keep track of upper and lower bound for every subtree
while calling recursively for left node, lower limit remains same but upper limit is
the value of the current node, vice versa while calling for right node.

Time Complexity: O(N)
Space Complexity: O(height) */


class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    void inorder(Node* root, bool &ans, int &num)
    {
        static int count = 0;
        if(root == NULL)
            return;
            
        inorder(root->left, ans, num);
        if(count == 0)
            num = root->data;
        else
        {
            if(root->data <= num)
                ans = false;
            num = root->data;
        }
        count++;
        inorder(root->right, ans, num);
    }
    
    bool isBST(Node* root) 
    {
        bool ans = true;
        int num = 0;
        inorder(root, ans, num);
        return ans;
    }
};
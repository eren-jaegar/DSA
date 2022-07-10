/*
Approach - 1
do inorder traversal.
keep track of the last node visited so when we visit a new node we put new node's address 
in last node's next and then update last node visited(prev) with current node's address

Time Complexity: O(N)
Space Complexity: O(height) //recursion uses space */

class Solution
{
public:

    void solve(Node* root, Node** prev)
    {
        if(root == NULL)
            return;
        
        solve(root->left, prev);
        if((*prev) != NULL)
        {
            (*prev)->next = root;
        }
        *prev = root;
        solve(root->right, prev);
    }
    
    void populateNext(Node *root)
    {
        Node* temp = NULL;
        solve(root, &temp);
    }
};
/*
Approach - 1
do a reverse inorder traversal and keep counting the elements.
when the count becomes equal to k, we have got our answer.

for reverse inorder traversal, call the function first for the right child and then for
the left child.

Time Complexity: O(max(H,K)) question says O(H+K), GFG article says (N)
Space Complexity: O(H) */

class Solution
{
    public:
    
    Node* reverseinorder(Node* root, int* k)
    {
        if(root == NULL)
            return NULL;
            
        Node* right = reverseinorder(root->right, k);
        if(right)
            return right;
        *k = *k - 1;
        if(*k == 0)
            return root;
        return reverseinorder(root->left, k);
    }
    
    int kthLargest(Node *root, int K)
    {
        Node* ans = reverseinorder(root, &K);
        return ans->data;
    }
};
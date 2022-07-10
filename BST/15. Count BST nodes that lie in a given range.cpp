/*
Approach - 1
visit every node and if it lies in range then, increase count.

Time Complexity: O(N)
Space Complexity: O(H) */

class Solution{
public:

    void traverse(Node* root, int l, int h, int &count)
    {
        if(root == NULL)
            return;
        traverse(root->left, l, h, count);
        if(root->data >= l && root->data <= h)
            count++;
        traverse(root->right, l, h, count);
    }

    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        traverse(root, l, h, count);
        return count;
    }
};



/*
Approach - 2
we can do traversal using morris traversal so, we won't be using any space.

Time Complexity: O(N)
Space Complexity: O(1)*/



/*
Approach - 3
we can optimize it a bit.
if the given node is greater than low, only then should we call the function for its left
child else not.
similarly, if the given node is smaller than high, only then should we call the function
for its right child else not.

Time Complexity: O(H+K)
Space Complexity: O(H) */

class Solution{
public:

    void traverse(Node* root, int l, int h, int &count)
    {
        if(root == NULL)
            return;
        if(root->data >= l && root->data <= h)
            count++;
        if(root->data > l)    
            traverse(root->left, l, h, count);
        if(root->data < h)
            traverse(root->right, l, h, count);
    }

    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        traverse(root, l, h, count);
        return count;
    }
};
/*
Approach - 1
call a recursive function to do it.

incase the node to be deleted is a leaf node then delete it and return NULL
else if it has one child then delete the node and return a pointer to the address of that
child
incase it has 2 children then find the inorder predecessor or successor and replace the
current node's value with the value of its predecessor/successor then call the function
again to delte its predecessor/successor in its left/right subtree.

Time Complexity: O(height)
Space Complexity: O(height) //recursion stack uses space */

class Solution {
public:
    
    
    TreeNode* inorderpred(TreeNode* root)
    {
        while(root && root->right)
            root = root->right;
        return root;
    }
    
    TreeNode* deleterecursion(TreeNode* root, int key)
    {
        if(root == NULL)
            return root;
        if(root->val > key)
            root->left = deleterecursion(root->left, key);
        else if(root->val < key)
            root->right = deleterecursion(root->right, key);
        else if(root->val == key)
        {
            if(root->left && root->right)
            {
                TreeNode* temp = inorderpred(root->left);
                root->val = temp->val;
                root->left = deleterecursion(root->left, root->val);
            }
            else if(root->left)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->right)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                delete root;
                return NULL;
            }
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return deleterecursion(root, key);
        
    }
};



/*
same approach as above just the case for deletion of node with 2 children has been
modified a bit.
p is the parent of the inorder predecessor.

This approach can easily be converted into iteration. just use a while loop to find the
node to be deleted, the remaining code will nearly remain same.

Time Complexity: O(height)
Space Complexity: O(height) */

class Solution {
public:
    
    
    
    TreeNode* deleterecursion(TreeNode* root, int key)
    {
        if(root == NULL)
            return root;
        if(root->val > key)
            root->left = deleterecursion(root->left, key);
        else if(root->val < key)
            root->right = deleterecursion(root->right, key);
        else if(root->val == key)
        {
            if(root->left && root->right)
            {
                TreeNode* temp = root->left;
                TreeNode* p = root;
                while(temp->right)
                {
                    p = temp;
                    temp = temp->right;
                }
                if(p == root)
                {
                    root->left = temp->left;
                }
                else
                {
                    p->right = temp->left;
                }
                root->val = temp->val;
                delete(temp);
            }
            else if(root->left)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->right)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                delete root;
                return NULL;
            }
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return deleterecursion(root, key);
        
    }
};
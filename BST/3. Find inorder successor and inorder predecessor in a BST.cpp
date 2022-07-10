//NOTE: here the question does not need the given key to be present in the tree.
//we basically have to find out the first smaller and first greater element than the key


/*
Approach - 1
store the inorder traversal of the tree in a vector.
search for the first element greater than equal to the given key.

depending on the values if i and if the key is present in tree or not, conditions are formed.
we can get the right answer using them.

Time Complexity: O(N)
Space Complexity: O(N) */

#include <bits/stdc++.h>

void inorder(Node* root, vector <Node*> &nums)
{
    if(root == NULL)
        return;
    inorder(root->left, nums);
    nums.push_back(root);
    inorder(root->right, nums);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    vector <Node*> nums;
    inorder(root, nums);
    int i = 0;
    for(; i<nums.size(); i++)
    {
        if(key <= nums[i]->key)
            break;
    }
    if(i >= nums.size())
    {
        pre = nums[nums.size()-1];
        return;
    }
    if(key == nums[i]->key)
    {
        if(i > 0)
            pre = nums[i-1];
        if(i < nums.size()-1)
            suc = nums[i+1];
        return;
    }
    if(i > 0)
        pre = nums[i-1];
    suc = nums[i];
        
}



/*
Approach - 2
if we use morris traversal then, we can do this in constant space.

Time Complexity: O(N)
Space Complexity: O(1) */



/*
Approach - 3
we call a recursive function that compares the node->data with given key.
if node->data is less than key then we search for key in the right subtree and also make
pre = node->data.
if node->data is greater than key then we search in the left subtree and also make
suc = node->data.
if the node->data == key then we search for the inorder pred and inorder suc but in case
the left subtree for the current node doesn't exist then we don't search for inorder pred.
same if right subtree doesn't exist then we don't search for inorder suc.
in these cases, either the pred and suc are at above levels so they have already been 
taken into account while calling for left and right subtree or they simply don't exist 
(in case it is the first node then pred doesn't exist) so, pred ans/or suc will remain
NULL in that case.

Time Complexity: O(height)
Space Complexity: O(height) */

void solve(Node* root, Node* &pre, Node* &suc, int key)
{
    if(root == NULL)
        return;
    if(root->key == key)
    {
        Node* temp = root->left;
        while(temp && temp->right)
            temp = temp->right;
        if(temp) //checking if left subtree exists or not
            pre = temp;
        temp = root->right;
        while(temp && temp->left)
            temp = temp->left;
        if(temp) //checking if right subtree exists or not
            suc = temp;
        return;
    }
    else if(root->key < key)
    {
        pre = root;
        solve(root->right, pre, suc, key);
    }
    else
    {
        suc = root;
        solve(root->left, pre, suc, key);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    solve(root, pre, suc, key);
}
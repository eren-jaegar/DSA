/*
Approach - 1
call a recursive function.
base case if the root is NULL, return NULL
if root->data equals either of the values then return return root
else if one value is greater than root->data and other is less than root->data then return
root as both values lie on opposite side of the current node.
else if both the values are smaller then call the function for root->left
else if both the values are bigger then call the function for root->right

Time Complexity: O(height)
Space Complexity: O(height) //recursion */

Node* solve(Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    if(root->data > min(n1,n2) && root->data < max(n1,n2))
        return root;
    if(root->data < n1)
        return solve(root->right, n1, n2);
    else
        return solve(root->left, n1, n2);
}

Node* LCA(Node *root, int n1, int n2)
{
    return solve(root, n1, n2);
}



/*
Approach - 2
the first two conditions of approach-1 can be merged into one and written as else after
condition-3 and condition-4. this can be implemented in recursion also but if we
implement this iteratively or if we implement approach-1 as it is iteratively then we
can do this in O(1) space.

Time Complexity: O(height)
Space Complexity: O(1) */

Node* LCA(Node *root, int n1, int n2)
{
    while(root)
    {
        if(root->data < n1 && root->data < n2)
            root = root->right;
        else if(root->data>n1 && root->data>n2)
            root = root->left;
        else
            break;
    }
    return root;
}
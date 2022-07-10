/*
Approach - 1
call a simple recursive function, maintain the max and min value possible in the subtree
whose root is the current node.
if min+1==root->data==max-1 then we have a dead end as we can't insert any more elements.

only leaf nodes can be dead ends as all other nodes already have children and also we 
insert at leaf nodes.

Time Complexity: O(N)
Space Complexity: O(H) */

bool deadend(Node* root, int min, int max)
{
    if(root == NULL)
        return false;
    if(root->left==NULL && root->right==NULL && min+1 == root->data && root->data+1 == max)
        return true;
    bool a = deadend(root->left, min, root->data);
    bool b = deadend(root->right, root->data, max);
    return a||b;
}

bool isDeadEnd(Node *root)
{
    return deadend(root, 0, INT_MAX);
}



/*
Approach - 2
same approach as above just a better implementation. */

bool deadend(Node* root, int min, int max)
{
    if(root == NULL)
        return false;
    if(min == max)
        return true;
    bool a = deadend(root->left, min, root->data-1);
    bool b = deadend(root->right, root->data+1, max);
    return a||b;
}

bool isDeadEnd(Node *root)
{
    return deadend(root, 1, INT_MAX);
}



/*Approach - 3
we need to realise that if for a given leaf node node->data-1 and node->data+1 exist
in the tree then it is a dead end, except for 1 because 0 can't exist so, only having 2
in the tree would suffice.

so, we traverse the tree and store all the elements in a map along with all the leaf nodes
in another map and check if x-1 and x+1 exist or not.
if they do even for one node then it is a dead end.

x-1 and x+1 need to be checked because if they exist, only then can min and max condition
of above approaches be achieved.


Time Complexity: O(N)
Space Complexity: O(N)
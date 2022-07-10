/*
Approach - 1
call a recursive function

Time Complexity: O(height)
Space Complexity: O(height) //recursion stack uses space */

int searchrec(Node* root, int x)
{
    if(root == NULL)
        return 0;
    if(root->data == x)
        return 1;
    if(root->data < x)
        return searchrec(root->right, x);
    else
        return searchrec(root->left, x);
}

bool search(Node* root, int x) {
    
    return searchrec(root, x);
    
}



/*
Approach - 2
do it iteratively.

Time Complexity: O(height)
Space Complexity: O(1) */

bool search(Node* root, int x) {
    
    while(root)
    {
        if(root->data == x)
            return 1;
        else if(root->data < x)
            root = root->right;
        else
            root = root->left;
    }
    return 0;
    
} 
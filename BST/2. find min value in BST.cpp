/*
Approach - 1
keep travelling to the left most node

Time Complexity: O(height)
Space Complexity: O(1) */

int minValue(Node* root) {
    
    if(root == NULL)
        return -1;
    while(root->left)
        root = root->left;
    return root->data;
}

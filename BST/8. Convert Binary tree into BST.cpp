/*
find inorder traversal in a vector.
sort it
and then do the inorder traversal again and start putting the elements of the vector
into nodes in increasing order.

Time Complexity: O(NlogN)
Space Complexity: O(N) //vector requires space */

//in this code, i have sorted the vector in reverse order so that i can just pop_back
//the elements else i will have to maintain int i for vector traversal while putting back
//the elements

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void putorder(Node* root, vector <int> &ans)
    {
        if(root == NULL)
            return;
        putorder(root->left, ans);
        root->data = ans.back();
        ans.pop_back();
        putorder(root->right, ans);
    }
    
    void findorder(Node* root, vector <int>&ans)
    {
        if(root == NULL)
            return;
        findorder(root->left, ans);
        ans.push_back(root->data);
        findorder(root->right, ans);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector <int> ans;
        findorder(root, ans);
        sort(ans.rbegin(), ans.rend());
        putorder(root, ans);
        return root;
    }
};
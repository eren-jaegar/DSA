/*Approach - 1
we call a recursive function to store the path from root to n1 in vector a and store the
path from root to n2 in vector b.
then we traverse both the vector and the last common element in them is our answer.

Time Complexity: O(N)
Space Complexity: O(height) //recursion uses O(H) and the two vectors also use O(H) as they 
don't contain more than H elements at any instant. */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    void lcarec(Node* root, int n1, int n2, vector <pair <Node*, int> >&a, vector <pair <Node*, int> >&b)
    {
        if(root == NULL)
            return;
        if(a.empty() || a.back().second!=n1)
            a.push_back(make_pair(root,root->data));
        if(b.empty() || b.back().second!=n2)
            b.push_back(make_pair(root,root->data));
            
        lcarec(root->left, n1, n2, a, b);
        lcarec(root->right, n1, n2, a, b);
        
        if(a.back().second!=n1)
            a.pop_back();
        if(b.back().second!=n2)
            b.pop_back();
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector <pair <Node*, int> > a;
        vector <pair <Node*, int> > b;
        lcarec(root, n1, n2, a, b);
        //if(a.empty() || b.empty()) then either one of n1&n2 or both don't exist in the given tree
        int i;
        for(i=0; i<min(a.size(),b.size()); i++)
        {
            if(a[i].first != b[i].first)
                break;
        }
        i--;
        return a[i].first;
    }
};



/*
Approach - 2
we call a recursive function which checks if the current node data match either n1 or n2
ans then calls the same function recursively on its left and right subtree to find if
either of them contains either of the elements.
if the subtree contains either elements then it returns the address of the first element
that it encounters else return null.
so if both left and right are not null then they both contain an element each so, we return
the current node as answer as it will be their lca. if either of them is null then we
return the other one as answer as that would contain both the elements.

Time Complexity: O(N)
Space Complexity: O(H) //only recursion requires space, no extra space requires for
storing the path. */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* lcarec(Node* root, int n1, int n2)
    {
        if(root == NULL)
            return NULL;
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node* left = lcarec(root->left, n1, n2);
        Node* right = lcarec(root->right, n1, n2);
        
        if(left && right)
            return root;
        if(left)
            return left;
        return right;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return lcarec(root, n1, n2);
    }
};
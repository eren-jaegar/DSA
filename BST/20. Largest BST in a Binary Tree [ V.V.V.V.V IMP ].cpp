/*
Approach - 1

do a preorder traversal of the tree. for the current node check if it is BST ot not.
in case it is then find its size.
in case it is not then check whether its children are BST or not.

keep doing this and then the maximum size will be the answer.


Time Complexity: O(N^2)
Space Complexity: O(H) */


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    
    int knowsize(Node* root)
    {
        if(root == NULL)
            return 0;
        return 1+knowsize(root->left)+knowsize(root->right);
    }
    
    bool check(Node* root, int min, int max)
    {
        if(root == NULL)
            return true;
        if(root->data > min && root->data < max)
        {
            return check(root->left, min, root->data) && check(root->right, root->data, max);
        }
        else
            return false;
    }
    
    void preorder(Node* root, int &size)
    {
        if(root == NULL)
            return;
        bool a = check(root, INT_MIN, INT_MAX);
        if(a)
            size = max(knowsize(root),size);
        else
        {
            preorder(root->left, size);
            preorder(root->right, size);
        }
    }
    
    int largestBst(Node *root)
    {
        int size = 0;
        preorder(root, size);
        return size;
    }
};



/*
Approach - 2

create a structure that stores the following information: 
1)minimum value in the tree rooted at current node
2)maximum value in the tree rooted at current node
3)size of the biggest bst which is subtree of the tree rooted at current node
4)whether the tree rooted at current node is a bst or not


we do a preorder/postorder traversal of the tree.

for null pointer, we return true for bst, 0 for size, INT_MIN for maxval and INT_MAX for
minval.

for every node check whether the children nodes nodes are bst or not.
in case they are then whether current node's data is in range or not.
in case it is then the tree rooted at current node is bst else it is not.
return accordingly.
in case either of the child return false for bst then the tree rooted at current node can't
be a bst hence, return accordingly.



we traverse the tree in bottom up manner where each node passes the following information:
1)minimum value in the tree rooted at current node
2)maximum value in the tree rooted at current node
3)size of the biggest bst which is subtree of the tree rooted at current node
4)whether the tree rooted at current node is a bst or not


Time Complexity: O(N)
Space Complexity: O(H) //recursion */



class Solution{
    
    struct bst
    {
        int minval;
        int maxval;
        int size;
        bool condition;
    };
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bst solve(Node* root)
    {
        bst x;
        if(root == NULL)
        {
            x.size = 0;
            x.condition = true;
            x.minval = INT_MAX;
            x.maxval = INT_MIN;
            return x;
        }
        bst a = solve(root->left);
        bst b = solve(root->right);
        if(a.condition && b.condition)
        {
            if(root->data > a.maxval && root->data < b.minval)
            {
                x.condition = true;
                x.size = a.size + b.size + 1;
                x.minval = min({a.minval,b.minval,root->data}); //necessary to take root->data because of leaf nodes. else minval will contain INT_MAX
                x.maxval = max({a.maxval,b.maxval,root->data}); //necessary to take root->data because of leaf nodes. else maxval will contain INT_MIN
            }
            else
            {
                x.condition = false;
                x.size = max(a.size, b.size);
                x.minval = INT_MIN; //could have been anything
                x.maxval = INT_MAX; //could have been anything
            }
        }
        else
        {
            x.condition = false;
            x.size = max(a.size, b.size);
            x.minval = INT_MIN; //could have been anything
            x.maxval = INT_MAX; //could have been anything
        }
        return x;
    }
    
    int largestBst(Node *root)
    {
        bst ans = solve(root);
        return ans.size;
    }
};
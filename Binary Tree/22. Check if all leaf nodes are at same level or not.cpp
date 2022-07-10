/*Approach - 1
call a recursive function which tracks the height of all the leaf nodes and pass to it
a variable which stores max height of leaf nodes till now(maxheight).
if maxheight is -1 then it has not encountered any leaf node so when we enocunter one, update
maxheight equal to the height of that node.
if we encounter any other node with height != maxheight then make ans = false as all leaf
nodes are not on same level.

Time Complexity: O(N)
Space Complexity: O(height of tree) */

class Solution{
  public:
    /*You are required to complete this method*/
    
    void check(Node* root, int* level, int height, bool* ans)
    {
        if(*ans == false)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            if(*level == -1)
            {
                *level = height;
            }
            else
            {
                if(height != *level)
                    *ans = false;
            }
        }
        if(root->left)
            check(root->left, level, height+1, ans);
        if(root->right)
            check(root->right, level, height+1, ans);
    }
    
    bool check(Node *root)
    {
        int maxlevel = -1;
        bool ans = true;
        check(root, &maxlevel, 0, &ans);
        return ans;
    }
};



//better implementation

class Solution{
  public:
    /*You are required to complete this method*/
    
    bool check(Node* root, int* level, int height)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(*level == -1)
            {
                *level = height;
                return true;
            }
            else
            {
                if(height != *level)
                    return false;
                return true;
            }
        }
        bool a = true, b = true;
        if(root->left)
            a = check(root->left, level, height+1);
        if(root->right)
            b = check(root->right, level, height+1);
        
        return a&&b;
    }
    
    bool check(Node *root)
    {
        int maxlevel = -1;
        return check(root, &maxlevel, 0);
    }
};



/*
Approach - 2
could have done by level order traversal using iterative method also. */

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        queue <Node*> dummy;
        dummy.push(root);
        Node* temp = NULL;
        int maxheight = 0;
        int height = 0;
        while(!dummy.empty())
        {
            int n = dummy.size();
            height++;
            for(int i=0; i<n; i++)
            {
                temp = dummy.front();
                dummy.pop();
                if(temp->left)
                    dummy.push(temp->left);
                if(temp->right)
                    dummy.push(temp->right);
                if(temp->left==NULL && temp->right==NULL)
                {
                    if(maxheight == 0)
                        maxheight = height;
                    else
                    {
                        if(height != maxheight)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
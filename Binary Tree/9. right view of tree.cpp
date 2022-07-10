/*Approach - 1
same as approach-1 of previous question, just interchange the insertion order of temp->left
and temp->right.
i.e., first insert temp->right and then insert temp->left

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector <int> ans;
    Node* temp = NULL;
    queue <Node*> dummy;
    dummy.push(root);
    dummy.push(NULL);
    if(root == NULL)
        return ans;
    while(!dummy.empty())
    {
        temp = dummy.front();
        if(temp)
        {
            ans.push_back(temp->data);
            while(temp!=NULL)
            {
                if(temp->right)
                    dummy.push(temp->right);
                if(temp->left)
                    dummy.push(temp->left);
                dummy.pop();
                temp = dummy.front();
            }
        }
        else
        {
            dummy.pop();
            if(!dummy.empty())
                dummy.push(NULL);
        }
    }
    return ans;
    }
};



/*Approach - 2
same as approach-2 of previous question, just interchange the insertion order of temp->left
and temp->right.
i.e., first insert temp->right and then insert temp->left

NOTE: We could have inserted left first and then just pushed the last node into the ans
vector instead of pushing the first node.

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector <int> ans;
        queue <Node*> dummy;
        Node* temp = NULL;
        dummy.push(root);
        int n;
        while(!dummy.empty())
        {
            n = dummy.size();
            for(int i=1; i<=n; i++)
            {
                temp = dummy.front();
                dummy.pop();
                if(i == 1)
                    ans.push_back(temp->data);
                if(temp->right)
                    dummy.push(temp->right);
                if(temp->left)
                    dummy.push(temp->left);
            }
        }
        return ans;
    }
};



/*Approach - 3
same as approach-3 of previous question. just call the function for right subtree before 
calling it for the left subtree.

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution
{
    public:
    
    void view(vector <int> &ans, int level, int* maxheight, Node* root)
{
    if(root == NULL)
        return;
    if(level > *maxheight)
    {
        *maxheight += 1;
        ans.push_back(root->data);
    }
    view(ans, level+1, maxheight, root->right);
    view(ans, level+1, maxheight, root->left);
}

vector<int> rightView(Node *root)
{
    int maxheight = 0;
    vector <int> ans;
    view(ans, 1, &maxheight, root);
    return ans;
}
};
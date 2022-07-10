/* Approach - 1
we do a level order traversal and push the first element of each level into the ans vector.
we keep track of end of each level using a NULL pointer. so next element after a null pointer
will be the first element of that level.

Time Complexity: O(N)
Space Complexity: O(N) */

vector<int> leftView(Node *root)
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
                if(temp->left)
                    dummy.push(temp->left);
                if(temp->right)
                    dummy.push(temp->right);
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



/*Approach - 2
same approach as above, just slightly different implementation. we don't use null pointer
to keep track of new level but for each new level we check the size of queue, which gives
us the number of elements in that level. so now we run a for loop to push their children
into queue and also push only the first node into ans vector.

Time Complexity: O(N)
Space Complexity: O(N) */

vector<int> leftView(Node *root)
{
    vector <int> ans;
    Node* temp = NULL;
    queue <Node*> dummy;
    dummy.push(root);
    int n;
    if(root == NULL)
        return ans;
    while(!dummy.empty())
    {
        n = dummy.size();
        for(int i=1; i<=n; i++)
        {
            temp = dummy.front();
            dummy.pop();
            if(i==1)
                ans.push_back(temp->data);
            if(temp->left)
            {
                dummy.push(temp->left);
            }
            if(temp->right)
            {
                dummy.push(temp->right);
            }
        }
    }
    return ans;
}



/*Approach - 3
using recursion.
we keep track of the maxheight achieved till now.
if the level of the current node is greater than the maxheight then we have encountered 
the first node of the level so we push it into the ans vector.
to ensure that its the first node, we first call the view function recursively on the
left subtree and then on the right subtree.

the recursive function's calling is like preorder traversal.

Time Complexity: O(N)
Space Complexity: O(N) */

void view(vector <int> &ans, int level, int* maxheight, Node* root)
{
    if(root == NULL)
        return;
    if(level > *maxheight)
    {
        *maxheight += 1;
        ans.push_back(root->data);
    }
    view(ans, level+1, maxheight, root->left);
    view(ans, level+1, maxheight, root->right);
}

vector<int> leftView(Node *root)
{
    int maxheight = 0;
    vector <int> ans;
    view(ans, 1, &maxheight, root);
    return ans;
}
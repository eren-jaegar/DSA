//Approach - 1
//use a queue
//first push the value of the root node in the ans vector and push the address of the root
//node in the queue,
//now, run a while loop till the queue is not empty.
//pop the front element of queue. check its left node, if it is not null then, push its data
//into the and vector and push its address into thr queue.
//now check for the right node, if it is not null then push its data into ans vector and
//push its address into queue.

//Time Complexity: O(N) //every node is accessed twice
//Space Complexity: O(N)

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector <int> ans;
        queue <Node*> dummy;
        Node* temp = NULL;
        
        dummy.push(node);
        while(!dummy.empty())
        {
            temp = dummy.front();
            dummy.pop();
            ans.push_back(temp->data);
            if(temp->left)
            {
                //ans.push_back(temp->left->data);
                dummy.push(temp->left);
            }
            if(temp->right)
            {
                //ans.push_back(temp->right->data);
                dummy.push(temp->right);
            }
        }
        return ans;
    }
};


//same approach, slightly different implementation

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector <int> ans;
        queue <Node*> dummy;
        Node* temp = NULL;
        ans.push_back(node->data);
        dummy.push(node);
        while(!dummy.empty())
        {
            temp = dummy.front();
            dummy.pop();
            if(temp->left)
            {
                ans.push_back(temp->left->data);
                dummy.push(temp->left);
            }
            if(temp->right)
            {
                ans.push_back(temp->right->data);
                dummy.push(temp->right);
            }
        }
        return ans;
    }
};



//Approach - 2
//for explanation see approach-3 of next question

//Time Complexity: O(N^2)
//Space Complexity: O(N)

class Solution
{
    public:
    
void printgivenlevel(Node* root, vector <int> &ans, int i)
{
    if(root == NULL)
        return;
    if(i == 1)
    {
        ans.push_back(root->data);
        return;
    }
    printgivenlevel(root->left, ans, i-1);
    printgivenlevel(root->right, ans, i-1);
}

int treeheight(Node* root)
{
    if(root == NULL)
        return 0;
    int x = treeheight(root->left);
    int y = treeheight(root->right);
    
    if(x>y)
        return x+1;
    return y+1;
}

vector<int> levelOrder(Node *root)
{
    vector <int> ans;
    int height = treeheight(root);
    for(int i=1; i<=height; i++)
    {
        printgivenlevel(root, ans, i);
    }
    return ans;
}
};
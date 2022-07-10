/*
Approach - 1
we use two queues
we pop the first element from q1 and keep traversing in its right subtree.
we push its data into ans vector and whenever we encounter a left node we push it into q2
because it will be part of next diagonal.
once temp becomes null while traversing in the right subtree of current node, we pop the
next node from q1.
if temp is null and q1 is empty then it means current diagonal is over so, we swap q2 with
q1.
q2 contained the nodes for next diagonal.
if temp is null and q1 is empty then there are no more diagonals left so we break out of loop

Time Complexity: O(N)
Space Complexity: O(N) */

vector<int> diagonal(Node *root)
{
    vector <int> ans;
    queue <Node*> q1;
    queue <Node*> q2;
    Node* temp = NULL;
    temp = root;
    while(temp || !q1.empty())
    {
        if(temp == NULL)
        {
            temp = q1.front();
            q1.pop();
        }
        ans.push_back(temp->data);
        if(temp->left)
            q2.push(temp->left);
        temp = temp->right;
        if(temp==NULL && q1.empty())
            q1.swap(q2);
    }
    return ans;
}



/*
Approach - 2
similar to above, we just use 1 queue.
instead of using q2, we can just push the left subtree node in q1 because after the current
diagonal is over, they will be processes anyhow and we can break from the loop when q1 is 
empty.

Time Complexity: O(N)
Space Complexity: O(N) */

vector<int> diagonal(Node *root)
{
    vector <int> ans;
    queue <Node*> q1;
    Node* temp = NULL;
    q1.push(root);
    while(temp!=NULL || !q1.empty())
    {
        if(temp == NULL)
        {
            temp = q1.front();
            q1.pop();
        }
        ans.push_back(temp->data);
        if(temp->left)
            q1.push(temp->left);
        temp = temp->right;
    }
    return ans;
}



/*
Approach - 3
using a map
elements of a diagonal are stored in the same vector against the same key.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

//copied code, not written by myself.


void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left,
                      d + 1, diagonalPrint);
 
    // Vertical distance remains
    // same for right child
    diagonalPrintUtil(root->right,
                         d, diagonalPrint);
}
 
// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{
     
    // create a map of vectors
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
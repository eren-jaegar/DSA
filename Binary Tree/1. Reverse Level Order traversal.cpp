//Approach - 1
//we use a queue and stack
//first we push the address of the root into queue.
//now run a while loop till queue is not empty
//pop the front element of the queue into temp.
//if the temp->right is not null then push the address of the temp->right into queue.
//if the temp->left is not null then push the address of the temp->left into queue.
//push temp into the stack.

//now, run another while loop till stack is not empty.
//pop the top element and push_back its data into the ans vector.

//Time Complexity: O(N)
//Space Complexity: O(N)

vector<int> reverseLevelOrder(Node *root)
{
    vector <int> ans;
    stack <Node*> nodeorder;
    queue <Node*> dummy;
    Node* temp = NULL;
    
    dummy.push(root);
    while(!dummy.empty())
    {
        temp = dummy.front();
        dummy.pop();
        if(temp->right)
            dummy.push(temp->right);
        if(temp->left)
            dummy.push(temp->left);
        nodeorder.push(temp);
    }
    while(!nodeorder.empty())
    {
        ans.push_back(nodeorder.top()->data);
        nodeorder.pop();
    }
    return ans;
}



//Approach - 2

//NOTE: Can't use deque instead of using queue and stack because when we push_back into
//deque, all the iterators get invalidated.
//so, to use deque we need to make our own deque.

//we are implementing array as an deque.
//we are doing static declaration so there is wastage of space, but if implement deque using
//linked list or use dynamic memory allocation for array after finding number of nodes in
//tree then, it will use less space.

//initialize two integers start and end to traverse the array.
//we insert element at end.
//we first push the root address into the array.
//run a while loop till start!=end
//now take the address at the start index into temp.
//if temp->right is not null then insert its address at end index and do end++
//so same for temp->left
//do start++

//after this do end-- and make start = -1
//run a while loop till start != end
//push_back data of address stored at end index.
//do end--

//Time Complexity: O(N)
//Space Complexity: O(N)

vector<int> reverseLevelOrder(Node *root)
{
    vector <int> ans;
    Node* dummy[10000];
    int start = 0, end = 0;
    Node* temp = NULL;
    
    dummy[end] = root;
    end++;
    while(start != end)
    {
        temp = dummy[start];
        if(temp->right)
        {
            dummy[end] = temp->right;
            end++;
        }
        if(temp->left)
        {
            dummy[end] = temp->left;
            end++;
        }
        start++;
    }
    start = -1;
    end--;
    while(start != end)
    {
        ans.push_back(dummy[end]->data);
        end--;
    }
    return ans;
}



//Approach - 3
//we first find the height of the given tree.
//we create a function to print all the nodes on a given level.
//we call that function iteratively from height to 1.

//printgivenlevel returns without doing anything if the given root is null.
//if the given level is 1 then it prints/push_back the data of the current node.
//else it calls itself by reducing the level by 1 for the node->left and node->right.


//Time Complexity: O(N^2)
//worst case scenario for skewered tree: printgivenlevel is called n times and it executes 
//in O(N) so, time complexity is O(N^2) printgivenlevel makes (n)+(n-1)+(n-2)...+1 calls
//in total so O(N^2) complexity.

//Space Complexity: O(N) varies from O(logN) to O(N), worst case scenario O(N)

//NOTE: see approach-2 of next question i.e. question-2 for implementing this using
//iteration(using queue) instead of recursion.


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

vector<int> reverseLevelOrder(Node *root)
{
    vector <int> ans;
    int height = treeheight(root);
    for(int i=height; i>0; i--)
    {
        printgivenlevel(root, ans, i);
    }
    return ans;
}
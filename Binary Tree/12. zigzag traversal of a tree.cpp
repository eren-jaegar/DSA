/*Approach - 1
//use recursion
we have used a recursion function which depending on the bool type variable passed to it
either inserts left node first and right node second or vice versa.
this gives us out zigzag traversal
we have also used stacks to store the addresses and push them out though queues could have
also been used

Time Complexity: O(N)
Space Complexity: O(N) //though it uses a lot of space, later approaches are space efficient
*/


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    
    void zigzag(vector <int> &ans, stack <Node*> &dummy1, bool condition)
    {
        Node* temp = NULL;
        stack <Node*> dummy2;
        if(dummy1.empty())
            return;
            
        if(condition)
        {
            while(!dummy1.empty())
            {
                temp = dummy1.top();
                dummy1.pop();
                ans.push_back(temp->data);
                if(temp->left)
                    dummy2.push(temp->left);
                if(temp->right)
                    dummy2.push(temp->right);
            }
            zigzag(ans, dummy2, false);
        }
        else
        {
            while(!dummy1.empty())
            {
                temp = dummy1.top();
                dummy1.pop();
                ans.push_back(temp->data);
                if(temp->right)
                    dummy2.push(temp->right);
                if(temp->left)
                    dummy2.push(temp->left);
            }
            zigzag(ans, dummy2, true);
        }
    }
    
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> ans;
        stack <Node*> dummy;
        dummy.push(root);
        zigzag(ans, dummy, true);
        return ans;
    }
};



/*
Approach - 2
we use two stacks. 
one to store the addresses of the nodes for traversal of current level(s1) and other to
store the addresses of nodes for traversal of next level(s2).
once s1 is empty we swap s2 with s1 and reverse the condition.

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> ans;
        bool condition = true;
        stack <Node*> s1;
        stack <Node*> s2;
        s1.push(root);
        Node* temp = NULL;
        while(!s1.empty() || !s2.empty())
        {
            temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(condition)
            {
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
            else
            {
                if(temp->right)
                    s2.push(temp->right);
                if(temp->left)
                    s2.push(temp->left);
            }
            if(s1.empty())
            {
                s1.swap(s2);
                condition = !condition;
            }
        }
        return ans;
    }
};



/*
Approach - 3
we are using a deque
alternatively we are pushing left node first and right node second and vice versa.
alternatively we pop current element from front ot from back
after for loop is over i.e, current level has been traversed, flip the condition

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> ans;
        bool condition = true;
        deque <Node*> dummy;
        dummy.push_back(root);
        Node* temp = NULL;
        while(!dummy.empty())
        {
            int n = dummy.size();
            for(int i=0; i<n; i++)
            {
                if(condition)
                {
                    temp = dummy.front();
                    dummy.pop_front();
                    ans.push_back(temp->data);
                    if(temp->left)
                        dummy.push_back(temp->left);
                    if(temp->right)
                        dummy.push_back(temp->right);
                }
                else
                {
                    temp = dummy.back();
                    dummy.pop_back();
                    ans.push_back(temp->data);
                    if(temp->right)
                        dummy.push_front(temp->right);
                    if(temp->left)
                        dummy.push_front(temp->left);
                }
            }
            condition = !condition;
        }
        return ans;
    }
};



/*
Approach - 4
we use a queue
we do level order traversal.
for a certain level just store all its data of nodes from left to right and depending
on condition either we have to reverse it or not.

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> ans;
        queue <Node*> dummy;
        dummy.push(root);
        Node* temp = NULL;
        bool condition  = true;
        while(!dummy.empty())
        {
            int n = dummy.size();
            vector <int> level;
            for(int i=0; i<n; i++)
            {
                temp = dummy.front();
                dummy.pop();
                level.push_back(temp->data);
                if(temp->left)
                    dummy.push(temp->left);
                if(temp->right)
                    dummy.push(temp->right);
            }
            if(!condition)
                reverse(level.begin(), level.end());
            condition = !condition;
            for(int i=0; i<level.size(); i++)
                ans.push_back(level[i]);
        }
        return ans;
    }
};
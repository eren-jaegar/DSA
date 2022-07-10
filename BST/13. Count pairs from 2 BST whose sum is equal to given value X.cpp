/*
Approach - 1
do inorder traversal of both the tree ans save the values in a vector.
now, traverse in both the vectors and find the number of pairs.

Time Complexity: O(N+M)
Space Complexity: O(N+M) */

class Solution
{
public:


    void inorder(vector <int> &nums, Node* root)
    {
        if(root == NULL)
            return;
        inorder(nums, root->left);
        nums.push_back(root->data);
        inorder(nums, root->right);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector <int> a;
        vector <int> b;
        inorder(a, root1);
        inorder(b, root2);
        
        int count = 0;
        int i=0, j=b.size()-1;
        while(i<a.size() && j>=0)
        {
            if(a[i]+b[j] == x)
            {
                count++;
                i++;
                j--;
            }
            else if(a[i]+b[j] < x)
                i++;
            else
                j--;
        }
        return count;
    }
};



/*
Approach - 2
iterate through all the nodes in tree 1 and keep searching for x - node->data in tree 2.
if found then increase the count.

Time Complexity: O(N*height of tree2), basically O(N*logM)
Space Complexity: O(height of tree 2). if we use morris traversal then we only require
space for searching.
else if we do not use morris traversal O(h1+h2) */



/*
Approach - 3
do inorder traversal in tree 1 and reverse inorder traversal in tree2
this way we can access their elements in the same order as we did in approach-1.

Time Complexity: O(N+M)
Space Complexity: O(height1+height2) */

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int count = 0;
        stack <Node*> s1;
        stack <Node*> s2;
        Node* top1 = NULL;
        Node* top2 = NULL;
        while(1)
        {
            while(root1)
            {
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2)
            {
                s2.push(root2);
                root2 = root2->right;
            }
            if(s1.empty() || s2.empty())
                break;
            top1 = s1.top();
            top2 = s2.top();
            if(top1->data + top2->data == x)
            {
                count++;
                s1.pop();
                s2.pop();
                root1 = top1->right;
                root2 = top2->left;
            }
            else if(top1->data + top2->data < x)
            {
                s1.pop();
                root1 = top1->right;
            }
            else
            {
                s2.pop();
                root2 = top2->left;
            }
        }
        return count;
    }
};
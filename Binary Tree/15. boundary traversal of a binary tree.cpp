/* Approach - 1
push the root into the left(ans) vector
first check if the root node is the only node. if yes, return the left vector
else push the left boundary into the left vector.
if the size of left vector is not 1 that is there are elements other than the root itself
then remove the last element ass it is leaf node and will be added using the leaf function.
call the leaf function and push all the leaf elements into ans vector.

now push all the right boundary elements into right vector. if the root->right is not
NULL then it means that there is atleast one element in right boundary which means that 
its last elmeent will be a leaf node which has already been considered in leaf nodes so
delete the last element of left vector as it will that leaf node.
now push the contents of right vector in reverse order into the left vector.
return the left vector

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution {
public:

    void leaf(Node* root, vector <int>& left)
    {
        if(root->left || root->right)
        {
            if(root->left)
                leaf(root->left, left);
            if(root->right)
                leaf(root->right, left);
        }
        else
            left.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector <int> left;
        if(!root->left && !root->right)
        {
            left.push_back(root->data);
            return left;
        }
        vector <int> right;
        left.push_back(root->data);
        Node* temp = root->left;
        while(temp)
        {
            left.push_back(temp->data);
            if(temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
        auto it = left.end();
        if(left.size() != 1)
        {
            it--;
            left.erase(it);
        }
        leaf(root, left);
        temp = root->right;
        if(temp)
        {
            it = left.end();
            it--;
            left.erase(it);
        }
        while(temp)
        {
            right.push_back(temp->data);
            if(temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        for(int i=right.size()-1; i>=0; i--)
        {
            left.push_back(right[i]);
        }
        return left;
    }
};
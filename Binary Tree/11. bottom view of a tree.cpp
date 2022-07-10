/*Approach - 1
it is similar to approach-3 of the previous question.
we create two vectors, one to store the left elements(hd<=0) and other to store the right 
elements(hd>0)
do level order traversal and w do not have to care about encountering the element before
because if we encounter an element at same distance then either it is at the same level
and is the latter element or it is at a lower level. either way it needs to be inserted 
into the vector

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution {
  public:
  
    int size(Node* root)
    {
        if(root == NULL)
            return 0;
        int x = size(root->left);
        int y = size(root->right);
        return x+y+1;
    }
  
    vector <int> bottomView(Node *root) {
        
        int n = size(root);
        vector <int> left(n,0);
        vector <int> right(n,0);
        vector <int> ans;
        queue <pair <Node*, int> > dummy;
        Node* temp = NULL;
        int hd = 0;
        
        dummy.push(make_pair(root, 0));
        while(!dummy.empty())
        {
            temp = dummy.front().first;
            hd = dummy.front().second;
            if(hd<=0)
            {
                left[-1*hd] = temp->data;
            }
            else
            {
                right[hd] = temp->data;
            }
            if(temp->left)
                dummy.push(make_pair(temp->left, hd-1));
            if(temp->right)
                dummy.push(make_pair(temp->right, hd+1));
            dummy.pop();
        }
        int i = 0;
        while(i<n && left[i] > 0)
            i++;
        i--;
        for(; i>=0; i--)
        {
            ans.push_back(left[i]);
        }
        for(int j=1; j<n && right[j]>0; j++)
        {
            ans.push_back(right[j]);
        }
        return ans;
        
    }
};



/*Approach - 2
same as approach - 2 of last question, just don't check if it already exists in map or not
and just update it

Time Complexity: O(NlogN)
Space Complexity: O(N)



Approach - 3
same as approach-2 of last question
instead of checking that the level of current element is lower than level of already existing 
element, check for the opposite
if the level is greater than or equal to then update it else not.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void topviewrecursion(map<int, pair<int,int> > &view, int distance, int level, Node* root)
    {
        if(root == NULL)
            return;
        if(view.count(distance) == 0)
            view[distance] = make_pair(root->data,level);
        else
        {
            if(level >= view[distance].second)
                view[distance] = make_pair(root->data,level);
        }
        topviewrecursion(view, distance-1, level+1, root->left);
        topviewrecursion(view, distance+1, level+1, root->right);
    }
    
    vector<int> bottomView(Node *root)
    {
        map <int,pair<int, int> > view;
        vector <int> ans;
        topviewrecursion(view, 0, 0, root);
        auto it = view.begin();
        while(it != view.end())
        {
            ans.push_back((it->second).first);
            it++;
        }
        return ans;
    }

}; 
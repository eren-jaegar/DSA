/*Approach - 1
we use recursion
first make a map which stores the horizontal distance in its first element and its second
element is a pair which stores the node value and node level.

now we call the recursive function from our main function by passing the map, horizontal
distance of node from root, its level and the node itself.
the first node that we pass is root node, so its distance and level are 0.

in the recursive function, check whether element for the curret horizintal distance
already exists in map or not. check is done using count function. if the element does not
exist, then insert it into the map.
in case the element already exists, check if the level of the existing element is less than
the current element or not.
if it is less then let it be else replace it with the current element.
this is because even though these two nodes have the same horizontal distance, in top view
only the node which has lesser level will be visible as it will be on the top of other node.

it is possible to encounter a node with greater level before encountering the node at lesser
level because the recursion calling follows depth first search type of style. 

Time Complexity: O(NlogN) //insertion and count functions of map take logN time
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
            if(level < view[distance].second)
                view[distance] = make_pair(root->data,level);
        }
        topviewrecursion(view, distance-1, level+1, root->left);
        topviewrecursion(view, distance+1, level+1, root->right);
    }
    
    vector<int> topView(Node *root)
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



/*Approach - 2
in this approach we do a level order traversal
we create a queue to store the node addresses as well as their horizontal distances.
we keep track of the horizontal distance of the current node. if a node with same distance
has already been encountered then we skip it else we insert it into the map
here, we do not have to take care of th level of the nodes as we are doing level order
traversal so we will always encounter the node with lesser level first.

Time Complexity: O(NlogN) //count and insertion of map take logN time
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map <int, int> view;
        vector <int> ans;
        Node* temp = NULL;
        int hd = 0;
        queue <pair <Node*, int> > dummy;
        dummy.push(make_pair(root,0));
        while(!dummy.empty())
        {
            hd = dummy.front().second;
            temp = dummy.front().first;
            if(view.count(hd) == 0)
                view[hd] = temp->data;
            if(temp->left)
            {
                dummy.push(make_pair(temp->left, hd-1));
            }
            if(temp->right)
            {
                dummy.push(make_pair(temp->right, hd+1));
            }
            dummy.pop();
        }
        auto it = view.begin();
        while(it != view.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }

};



/*Approach - 3
similar to above approach
we do level order traversal
we create a queue which stores the addresses of the nodes as well as their horizontal
distances.
instead of using a map to keep track of whether we have encountered a node for a particular
horizontal distance or not, we use two variables, ld and rd which keep track of the 
farthest left side distance and the farthest right side distance that we have encountered
till now.

we push the values of left side nodes in a stack as we will get them in reverse order.
we can push the values of right side nodes in a vector.

this approach works because at a time we can increase or decrease the horizontal distance 
by only 1 so basicallt we will not skip any horizontal distance and since it is level order
traversal so, we will be encountering elments with lower level first.

Time Complexity: O(N)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        stack <int> left;
        vector <int> right;
        int ld = 0;
        int rd = 0;
        vector <int> ans;
        Node* temp = NULL;
        int hd = 0;
        queue <pair <Node*, int> > dummy;
        dummy.push(make_pair(root,0));
        while(!dummy.empty())
        {
            hd = dummy.front().second;
            temp = dummy.front().first;
            if(hd<ld)
            {
                left.push(temp->data);
                ld--;
            }
            else if(hd>rd)
            {
                right.push_back(temp->data);
                rd++;
            }
            if(temp->left)
            {
                dummy.push(make_pair(temp->left, hd-1));
            }
            if(temp->right)
            {
                dummy.push(make_pair(temp->right, hd+1));
            }
            dummy.pop();
        }
        while(!left.empty())
        {
            ans.push_back(left.top());
            left.pop();
        }
        ans.push_back(root->data); //root node's data is not inserted in above loop so we take 
        //care of it here.
        for(int i=0; i<right.size(); i++)
        {
            ans.push_back(right[i]);
        }
        return ans;
    }

};
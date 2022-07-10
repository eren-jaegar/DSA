/*Approach - 1
the diameter of a tree is nothing but the maximum of leftheight+rightheight+1 for every node.
for every node, we can find the maximum height of its left and right subtree and then for
the diameter we can do leftheight+rightheight+1. this may not be the diameter for the tree
as there might exist greater diameter in one of its subtree. that is why we call a recursive
function which checks the diameter from every leaf node and works its way to the top i.e, 
root node.
we can take max of all such diameters and that will be our answer.

Time Complexity: O(N)
Space Complexity: O(N) recursive stack uses space    */

class Solution {
    int ans = 0;
 
  public:
 
    int diameter(Node* root) {
        
        height(root);
        return ans;
    }
    
    int height(Node* root) //this is the function to find height of a tree
    {
        if(root == NULL)
            return 0;
        int x = height(root->left);
        int y = height(root->right);
    
        ans = max(ans, x+y+1); //we have made a slight modification. it calculates for every
        //node, the sum of left subtree and right subtree and 1. this is a potential
        //diameter. diameter will either be this or will be the diameter of one of its
        //subtree. max diameter of subtrees is stored in ans and then we compare it to
        //the current potential diameter and take the maximum.
        if(x>y)
            return x+1;
        return y+1;
    }
};



//Approach - 2
//we create a function finddiameter.
//the diameter for a subtree will be the maximum of (diameter of its left subtree), (diameter
//of its right subtree) and (the sum of height of its left subtree and right subtree+1).

//based on this, we call the function recursively to find diameter of the current node's
//left subtree and right subtree.

//using a pointer height, we also pass on the height on the subtree of the node.
//now that we have the diameters and height, we take its maximum and return it.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int finddiameter(Node* root, int *height)
    {
        int lh = 0;
        int rh = 0;
        if(root == NULL)
        {
            *height = 0;
            return 0;
        }
        int ldiameter = finddiameter(root->left, &lh);
        int rdiameter = finddiameter(root->right, &rh);
        
        *height = 1+max(lh,rh);
        
        return max(lh+rh+1, max(ldiameter,rdiameter));
    }
    
    int diameter(Node* root) {
        
        int height = 0;
        return finddiameter(root, &height);
        
    }
}; 
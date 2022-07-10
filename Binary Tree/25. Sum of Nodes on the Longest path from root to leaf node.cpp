/*Approach - 1
create a recursive function.
if the level of the current node exceeds the maxlevel so far then update the sum and
increase the maxlevel by 1.
else if the current level is equal to the maxlevel then compare if the sum+node->data is 
greater than current maxsum or not.
if it is greater than update maxsum. this is because in case of several longest paths,
we need the one with the greatest sum.
after the recursive function is over return the maxsum from the main function

Time Complexity: O(N)
Space Complexity: O(height of the tree) */


class Solution
{
public:
    
    void sumrecursion(Node* root, int sum, int level, int* maxsum, int* maxlevel)
    {
        if(root == NULL)
            return;
        
        if(level == *maxlevel)
        {
            if(sum+root->data > *maxsum)
                *maxsum = sum+root->data;
        }
        
        if(level > *maxlevel)
        {
            *maxlevel += 1;
            *maxsum = sum+root->data;
        }
        
        sumrecursion(root->left, sum+root->data, level+1, maxsum, maxlevel);
        sumrecursion(root->right, sum+root->data, level+1, maxsum, maxlevel);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxsum = 0;
        int maxlevel = 0;
        sumrecursion(root, 0, 1, &maxsum, &maxlevel);
        return maxsum;
    }
};
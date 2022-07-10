//Approach - 1
//we use recursion.
//call the function height to call recursively for the heights of the left subtree and
//right subtree of the current node.
//return the maximum of these two heights.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        if(node == NULL)
            return 0;
        
        int x = height(node->left);
        int y = height(node->right);
        
        if(x>y)
            return x+1;
        return y+1;
        
    }
};



//Approach - 2
//we can use a queue.
//push the root address and NULL into the queue.
//run a while loop till the queue is not empty
//in the loop, take the front element of the queue into temp.
//if the temp is not equal to null then check if temp->left is null or not. if not
//push its address into the queue. check and do the same for temp->right.
//else if temp is null and the queue is not empty then push null into the queue.

//in our while loop encountering NULL will mark the end of a level in tree and hence, whenever
//we encounter a NULL we increase our height by 1. we only push the null in the queue,
//when we have finished a level.

//Time Complexity: O(N)
//Space Complexity: O(N)

//NOTE: This can probably be used to implement printgivenlevel function also.

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        int ans = 0;
        queue <Node*> dummy;
        dummy.push(node);
        dummy.push(NULL);
        Node* temp = NULL;
        while(!dummy.empty())
        {
            temp = dummy.front();
            dummy.pop();
            
            if(temp == NULL)
                ans++;
            
            if(temp)
            {
                if(temp->left)
                    dummy.push(temp->left);
                if(temp->right)
                    dummy.push(temp->right);
            }
            else if(!dummy.empty())
                dummy.push(NULL);
        }
        return ans;
        
    }
};
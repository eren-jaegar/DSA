/*NOTE: in case of post order process is same, just begin traversing postorder from
last and call the recursive function for right child first and then for the left child*/



/*Approach - 1
see abdul bari video no. 295,296. if in hurry just see 296 as 295 only tells us that tree
can be constructed from inorder+preorder/postorder


Time Complexity: O(N^2)
Space Complexity: O(N) */

class Solution{
    public:
    
    int split(int* in, int start, int end, int x)
    {
        for(int i=start; i<=end; i++)
        {
            if(in[i] == x)
            return i;
        }
        return -1;
    }
    
    Node* buildtreerecursion(int* in, int* pre, int start, int end, int &i)
    {
        if(start>end)
            return NULL;
            
        int splitindex = split(in, start, end, pre[i]);
        Node* temp = new Node(pre[i]);
        i++;
        temp->left = buildtreerecursion(in, pre, start, splitindex-1, i);
        temp->right = buildtreerecursion(in, pre, splitindex+1, end, i);
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int i = 0;
        return buildtreerecursion(in, pre, 0, n-1, i);
    }
};



/*Approach - 2
we can do it in linear time by doing searching in inorder for splitindex in constant time.
we can search in constant time by storing all the elements as keys in an unordered map and
storing their indexes as their values.
this way we can find their index in constant time

this approach requires use of extra space apart from the recursion stack and space required 
for nodes of trees.

Time Complexity: O(N)
Space Comlpexity: O(N) //uses more space than previous approach */

class Solution{
    public:
    
    Node* buildtreerecursion(unordered_map <int,int> &ump, int* pre, int start, int end, int &i)
    {
        if(start>end)
            return NULL;
            
        int splitindex = ump[pre[i]];
        Node* temp = new Node(pre[i]);
        i++;
        temp->left = buildtreerecursion(ump, pre, start, splitindex-1, i);
        temp->right = buildtreerecursion(ump, pre, splitindex+1, end, i);
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int i = 0;
        unordered_map <int,int> ump;
        for(int j=0; j<n; j++)
        {
            ump[in[j]] = j;
        }
        return buildtreerecursion(ump, pre, 0, n-1, i);
    }
};
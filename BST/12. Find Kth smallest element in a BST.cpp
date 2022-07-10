/*
Approach - 1
call for inorder traversal and keep counting the number of elements so far.
when you get to k assign ans this root->data.

Time Complexity: O(N)
Space Complexity: O(H) */

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    void inorder(Node* root, int* k, int* ans)
    {
        if(root == NULL)
            return;
        inorder(root->left, k, ans);
        *k = *k - 1;
        if((*k) == 0)
        {
            *ans = root->data;
            return;
        }
        inorder(root->right, k, ans);
    }
    
    int KthSmallestElement(Node *root, int K) {
        
        int ans = -1;
        inorder(root, &K, &ans);
        return ans;
    }
};



/*
Approach - 2
a bit better implementation of above approach

Time Complexity: O(min(max(h,k),N)) //probably, though gfg says O(N)
Space Complexity: O(H) */

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    Node* inorder(Node* root, int* k)
    {
        if(root == NULL)
            return NULL;
        Node* left = inorder(root->left, k);
        if(left)
            return left;
        *k = *k - 1;
        if((*k) == 0)
        {
            return root;
        }
        return inorder(root->right, k);
    }
    
    int KthSmallestElement(Node *root, int K) {
        
        Node* ans = NULL;
        ans = inorder(root, &K);
        if(ans)
            return ans->data;
        return -1;
    }
};




NOTE: Approach - 3 is VERY IMPORTANT

/*
Approach - 3
Using Morris Traversal.
we traverse in inorder fashion while increasing the count by 1.
when the count becomes equal to k, we have got our answer.
but let the loop run entirely so that it can store the original structure of the tree.

also initialize ans as -1, in case size of tree is smaller than k then -1 will be returned 
as required.

Time Complexity: O(N)
Space Complexity: O(1) */

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        
        int k = K;
        Node* current = root;
        Node* pre = NULL;
        int count = 0;
        int ans = -1;
        
        while(current)
        {
            if(current->left == NULL)
            {
                count++;
                if(count == k)
                    ans = current->data;
                current = current->right;
            }
            else
            {
                pre = current->left;
                
                while(pre->right!=NULL && pre->right!=current)
                    pre = pre->right;
                    
                if(pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }
                if(pre->right == current)
                {
                    count++;
                    if(count == k)
                        ans = current->data;
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
        return ans;
        
    }
};



/*
Morris traversal works because it makes the current element, the right element of its
predecessor.
so while printing we move towards right else we move towards left.
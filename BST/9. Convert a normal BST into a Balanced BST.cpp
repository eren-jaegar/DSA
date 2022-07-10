/*
Approach - 1
we do an inorder traversal and find all the elements of the BST.
then call a recursive function that takes the middle element and makes it as current node
and then calls itself recursively for all the elements on the left as left child of teh current
node and for all the elements on right as the right child of current node.

Time Complexity: O(N)
Space Complexity: O(N) */


Node* buildrecursion(vector <int>&nums, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = ceil((start+end)/2);
    Node* root = new Node(nums[mid]);
    root->left = buildrecursion(nums, start, mid-1);
    root->right = buildrecursion(nums, mid+1, end);
    return root;
}

void inorder(Node* root, vector <int>&nums)
{
    if(root == NULL)
        return;
    inorder(root->left, nums);
    nums.push_back(root->data);
    inorder(root->right, nums);
}

Node* buildBalancedTree(Node* root)
{
    vector <int> nums;
    inorder(root, nums);
    Node* ans = buildrecursion(nums, 0, nums.size()-1);
    return ans;
}



/*
Approach - 2
same as above just don't create new nodes and instead rearrange the already existing ones.

Time Complexity: O(N)
Space Complexity: O(N) */


Node* buildrecursion(vector <Node*>&nums, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = ceil((start+end)/2);
    Node* root = nums[mid];
    root->left = buildrecursion(nums, start, mid-1);
    root->right = buildrecursion(nums, mid+1, end);
    return root;
}

void inorder(Node* root, vector <Node*>&nums)
{
    if(root == NULL)
        return;
    inorder(root->left, nums);
    nums.push_back(root);
    inorder(root->right, nums);
}

Node* buildBalancedTree(Node* root)
{
    vector <Node*> nums;
    inorder(root, nums);
    Node* ans = buildrecursion(nums, 0, nums.size()-1);
    return ans;
}
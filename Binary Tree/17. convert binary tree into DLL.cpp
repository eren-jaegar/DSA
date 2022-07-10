/*Approach - 1
do an inorder traversal of the tree and store the address of each node in a vector.
then link the consecutive nodes in the vector and return the first element of the vector as
that will be the head.

Time Complexity: O(N)
Space ComplexityL O(N) */

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void inorder(Node* root, vector <Node*> &address)
    {
        if(root == NULL)
            return;
        inorder(root->left, address);
        address.push_back(root);
        inorder(root->right, address);
    }
    
    Node * bToDLL(Node *root)
    {
        vector <Node*> address;
        inorder(root, address);
        int i = 0;
        int j = 1;
        for(; j<address.size();)
        {
            address[i]->right = address[j];
            address[j]->left = address[i];
            i++;
            j++;
        }
        return address[0];
    }
};



/*Approach - 2
we use recursion
call a function for inorder traversal
pass to it the root node, pointer to head node of DLL and a pointer to Node* pointer prev

prev contains the address of the last node that we have traversed using inorder traversal.
so when we encounter a new node, we link it to the previous node which is pointed by the 
prev pointer. linking is done by doint (*prev)->right = root;root->left = *prev 
then we update the last traversed node by doing *prev = root;

Time Complexity: O(N)
Space Complexity: O(height of tree) */

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void inorder(Node* root, Node** prev, Node** head)
    {
        if(root == NULL)
            return;
        inorder(root->left, prev, head);
        if(*head == NULL)
        {
            *head = root;
            *prev = root;
        }
        else
        {
            (*prev)->right = root;
            root->left = *prev;
            *prev = root;
        }
        inorder(root->right, prev, head);
    }
    
    Node * bToDLL(Node *root)
    {
        Node* head = NULL;
        Node* prev = NULL;
        inorder(root, &prev, &head);
        return head;
    }
};
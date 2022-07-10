/*
Approach - 1
form a node structure. include a height element too.
form the nodes for all the given frequencies and push them in a priority queue.
in the priority queue sort the nodes in increasing order of their data. in case the data is
same then sort them in increasing order of their height.
run a loop till there is only one element left in the queue.
in the loop. pop out top element and store in a. then pop out next top element and store
in b.
now create a new node with data as sum of a and b and height as max(a->height,b->height)+1.
push this new node back into the queue.

after the loop, do a preorder traversal and push the codes for all the leaf elements.


Time Complexity: O(NlogN)
Space Complexity: O(N) */


//Note: this solution does not get accepted.


class Solution
{
    struct Node
    {
        int data;
        int height;
        Node* right;
        Node* left;
        Node(int x)
        {
            data = x;
            height = 0;
            right = NULL;
            left = NULL;
        }
    };
    
    struct compare
    {
        bool operator()(Node* a, Node* b)
        {
            if(a->data == b->data)
                return a->height > b->height;
            return a->data > b->data;
        }
    };
    
	public:
	
	    void print(Node* root, vector <string>&ans, string &s)
	    {
	        if(root==NULL)
	            return;
	        s.push_back('0');
	        print(root->left, ans, s);
	        s.pop_back();
	        s.push_back('1');
	        print(root->right, ans, s);
	        s.pop_back();
	        if(root->left == NULL && root->right == NULL)
	            ans.push_back(s);
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector <string> ans;
		    priority_queue <Node*, vector<Node*>, compare> nums;
		    sort(f.begin(), f.end());
		    Node* temp = NULL;
		    for(int i=0; i<N; i++)
		    {
		        temp = new Node(f[i]);
		        nums.push(temp);
		    }
		    Node* a = NULL;
		    Node* b = NULL;
		    while(nums.size() != 1)
		    {
		        a = nums.top();
		        nums.pop();
		        b = nums.top();
		        nums.pop();
		        temp = new Node(a->data+b->data);
		        temp->height = max(a->height,b->height)+1;
		        temp->left = a;
		        temp->right = b;
		        nums.push(temp);
		    }
		    string s;
		    print(nums.top(), ans, s);
		    return ans;
		}
};



//for the solution to get accepted, we need to sort the elements in queue only on the
//basis of their data and not on height.


//this solution gets accepted.

class Solution
{
    struct Node
    {
        int data;
        int height;
        Node* right;
        Node* left;
        Node(int x)
        {
            data = x;
            height = 0;
            right = NULL;
            left = NULL;
        }
    };
    
    struct compare
    {
        bool operator()(Node* a, Node* b)
        {
            // if(a->data == b->data)
            //     return a->height > b->height;
            return a->data > b->data;
        }
    };
    
	public:
	
	    void print(Node* root, vector <string>&ans, string &s)
	    {
	        if(root==NULL)
	            return;
	        s.push_back('0');
	        print(root->left, ans, s);
	        s.pop_back();
	        s.push_back('1');
	        print(root->right, ans, s);
	        s.pop_back();
	        if(root->left == NULL && root->right == NULL)
	            ans.push_back(s);
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector <string> ans;
		    priority_queue <Node*, vector<Node*>, compare> nums;
		    sort(f.begin(), f.end());
		    Node* temp = NULL;
		    for(int i=0; i<N; i++)
		    {
		        temp = new Node(f[i]);
		        nums.push(temp);
		    }
		    Node* a = NULL;
		    Node* b = NULL;
		    while(nums.size() != 1)
		    {
		        a = nums.top();
		        nums.pop();
		        b = nums.top();
		        nums.pop();
		        temp = new Node(a->data+b->data);
		        temp->height = max(a->height,b->height)+1;
		        temp->left = a;
		        temp->right = b;
		        nums.push(temp);
		    }
		    string s;
		    print(nums.top(), ans, s);
		    return ans;
		}
};




/*
I believe both solutions are right and their can be multiple ways to do huffman encoding.
*/

/*
Approach - 1
we use a stack, see abdul bari lecture 308 and 309.
only push that nodes in stack for which you are assigning left children.
if we are assigning right children then the nodes need not be pushed into the stack.

Time Complexity: O(N)
Space Complexity: O(height)
*/



/*
Approach - 2
we maintain min and max limit for every node.
if the current data is in that limit then create node for it else return.

Time Complexity: O(N)
Space Complexity: O(height) */


Node* solve(int* pre, int* preindex, int low, int high, int size)
{
	if(low>high) //don't think this will ever happen
		return NULL;
	if(*preindex>size)
		return NULL;
	Node* root = NULL;
	if(pre[*preindex]>low && pre[*preindex]<high)
	{
		root = new Node(pre[*preindex]);
		*preindex += 1;

		root->left = solve(pre, preindex, low, root->data, size);
		root->right = solve(pre, preindex, root->data, high, size);
	}
	return root;
}

Node* driver(int* pre)
{
	int preindex = 0;
	int size = sizeof(pre)/sizeof(pre[0]);
	solve(pre, &preindex, INT_MIN, INT_MAX, size-1);
}
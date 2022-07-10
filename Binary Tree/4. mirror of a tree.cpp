/*Approach - 1
we can just call a recursive function that swaps the left and right pointers of the current
node and then calls itself recursively for current_node->left and current_node->right.

it modifies the original tree.

Time Complexity: O(N)
Space Complexity: O(N) //recursive stack uses space */

void mirror(Node* root)
{
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	if(root->left)
		mirror(root->left);
	if(root->right)
		mirror(root->right);
}



/*Approach - 2
if we don't want to change the current tree then we can create a function that creates
a new node for every passed node of the original tree but it creates the left node
for the passed right node and right node for the passed left node.

Time Complexity: O(N)
Space Complexity: O(N) */

void mirror(Node* root, Node* mirrornode)
{
	if(root == NULL)
	{
		mirrornode = NULL;
		return;
	}
	mirrornode = new Node(root->data);
	mirror(root->left, mirrornode->right);
	mirror(root->right, mirrornode->left);
}



/*Approach - 3
similar approach as above but we use recursion
create two queues.
do level order iteration of the original tree and keep pushing the address of the nodes.
correspondingly in other queue push the addresses of the mirror tree but for right node of
origianal tree push the left node of mirror tree and vice versa.

Time Complexity: O(N)
Space Complexity: O(N) */


Node* mirror(Node* root)
{
	Node* mirrornode = new Node(root->data);
	Node* temp = NULL;
	Node* temp1 = NULL;
	Node* temp2 = NULL;
	queue <Node*> original;
	queue <Node*> mirrored;
	original.push(root);
	mirrored.push(mirrornode);
	while(!original.empty())
	{
		temp1 = original.front();
		original.pop();
		temp2 = mirrored.front();
		mirrored.pop();
		if(temp1->left)
		{
			temp = new Node(temp1->left->data);
			temp2->right = temp;
			original.push(temp1->left);
			mirrored.push(temp2->right);
		}
		if(temp2->right)
		{
			temp = new Node(temp1->right->data);
			temp2->left = temp;
			original.push(temp1->right);
			mirrored.push(temp2->left);
		}
	}
	return mirrornode;
}
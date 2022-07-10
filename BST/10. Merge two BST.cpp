/*
Approach - 1
find the inoder traversal of tree1 and tree2.
the merge them using merge sort in (N+M) time.
now, we have inorder traversal of the combined tree.
now, simply vreate tree using this inorder traversal as we did in Q9. convert BST to
balanced BST.

Time Complexity: O(N+M)
Space Complexity: O(N+M) */



/*
Approach - 2
convert the first tree into dll and then convert the second tree into dll.
now, merge the two dll's using merge sort in O(N+M) time.
now, we have the combined tree in the form of a dll.
now, convert this dll into a tree in O(N+M) time.

Time Complexity: O(N+M)
Space Complexity: O(height of combined tree) //we use no extra space other than recursion.
*/

Node* solve(Node** head, int size)
{
	if(size<=0)
		return NULL;
	Node* left = solve(head, size/2);
	Node* root = *head;
	root->left = left;
	*head = (*head)->right //(*head)->next
	root->right = solve(head, size - size/2 - 1); //total nodes-nodes in left subtree-root node(1)
	return root;
}


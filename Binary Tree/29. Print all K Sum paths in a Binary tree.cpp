/*Approach - 1
start by doing level order traversal.
for every node call a recursive function that traverses tree from that node to its children
leaf nodes.
while traversing, keep track of sum and as soon as the sum reaches k, push it into a vector


Time Complexity: O(N*N)
Space Complexity: O(N) or O(H) */ //recursion uses O(H) space and dummy contains atmost H elements
//and can't really say about ans. O(H) is the right complexity prolly.

void printpathrecursion(int k, int sum, vector <vector <int> >&ans, vector <int>&dummy, Node* root)
{
	if(root == NULL)
		return;
	sum += root->data;
	dummy.push_back(root->data);
	if(sum == k)
		ans.push_back(dummy);
	printpathrecursion(k, sum, ans, dummy, root->left);
	printpathrecursion(k, sum, ans, dummy, root->right);
	sum -= root->data;
	dummy.pop_back(); //necessary to remove the last element as it will no longer be in our path
}

vector <vector <int> > printpath(Node* root, int k)
{
	vector <vector <int> > ans;
	vector <int> dummy;
	queue <int> q;
	q.push(root);
	Node* temp = NULL;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right)
		printpathrecursion(k, 0, ans, dummy, temp);
	}
	return ans;
}



/*
Approach - 2
instead of calling a function for every node, we call the function for just root node.
we keep track of the path travelled in a dummy vector and keep checking our sum from down
to top(moving from latest node towards root node) i.e, traversing in dummy vector from end
to begin.
if the sum equals k at any instant then we push it into ans vector.

Time Complexity: O(N*H*H)
Space Complexity: O(N) or O(H) */ //recursion uses O(H) space and dummy contains atmost H elements
//and can't really say about ans. O(H) is the right complexity prolly.


void pushvector(vector <int>&dummy, vector <vector <int> >&ans, int i)
{
	ans.push_back(vector <int> ());
	int k = ans.size()-1;
	for(; i<dummy.size(); i++)
	{
		ans[k].push_back(dummy[i]);
	}
}

void printpathrecursion(Node* root, int k, vector <vector <int> >&ans, vector <int>&dummy)
{
	if(root == NULL)
		return;
	dummy.push_back(root->data);
	printpathrecursion(root->left, k, ans, dummy);
	printpathrecursion(root->right, k, ans, dummy);

	int sum = 0;
	for(int i=dummy.size()-1; i>=0; i--)
	{
		sum += dummy[i];
		if(sum == k)
		{
			pushvector(dummy, ans, i);
		}
	}
	dummy.pop_back();

}

vector <vector <int> > printpath(root, k)
{
	vector <vector <int> > ans;
	vector <int> dummy;
	printpathrecursion(root, k, ans, dummy);
}
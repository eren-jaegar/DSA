/*
Approach - 1

do a dfs and keep track of visited element.
push the element into the answer vector while returning.


Time Complexity: O(V+E)
Space Complexity: O(V) */


class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	void dfs(vector <int> &ans, bool* visit, vector <int> *adj, int num)
	{
	    for(int i=0; i<adj[num].size(); i++)
	    {
	        if(visit[adj[num][i]] == false)
	        {
	            visit[adj[num][i]] = true;
	            dfs(ans, visit, adj, adj[num][i]);
	        }
	    }
	    ans.push_back(num);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector <int> ans;
	    bool visit[V] = {false};
	    for(int i=0; i<V; i++)
	    {
	        if(visit[i] == false)
	        {
	            visit[i] = true;
	            dfs(ans, visit, adj, i);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};
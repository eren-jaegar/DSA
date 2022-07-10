/*
Approach - 1


implement normally.


Time Complexity: O(V+E)
Space Complexity: O(V) */


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    
    void dfs(bool* visit, vector <int> &ans, vector <int> *adj, int num)
    {
        if(visit[num] == true)
            return;
        visit[num] = true;
        ans.push_back(num);
        for(int i=0; i<adj[num].size(); i++)
            dfs(visit, ans, adj, adj[num][i]);
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        bool visit[V] = {0};
        vector <int> ans;
        dfs(visit, ans, adj, 0);
        return ans;
    }
};
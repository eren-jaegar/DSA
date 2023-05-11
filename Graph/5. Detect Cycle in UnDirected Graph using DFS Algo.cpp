/*
Approach - 1

we can do it similar to finding cycle in directed graph.
only thing that we have to take care is the previous element that we visited before coming
to the current element.
let's say we go from 1 to 2. now adj[2] will contain 1 but that does not form a loop so we
skip it and do not call dfs for it.
this is achieved by passing along the previous element in the function.

Another thing that we have to take care of is the self loop, i.e., 1 looping onto itself.
for this we check if adj[nums] contains nums itself. if it does then return true.


Time Complexity: O(V+E)
Space Complexity: O(V) */


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    bool dfs(bool* visit, bool* instack, int prev, vector <int> *adj, int nums)
    {
        if(instack[nums] == true)
            return true;
        instack[nums] = true;
        if(visit[nums] == true)
        {
            instack[nums] = false;
            return false;
        }
        visit[nums] = true;
        bool ans = false;
        for(int i=0; i<adj[nums].size(); i++)
        {
            if(nums == adj[nums][i])
                return true;
            if(prev != adj[nums][i])
                ans = ans || dfs(visit, instack, nums, adj, adj[nums][i]);
        }
        instack[nums] = false;
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        bool visited[V] = {0};
        bool instack[V] = {0};
        int prev = -1;
        bool ans = false;
        for(int i=0; i<V; i++)
            ans = ans || dfs(visited, instack, prev, adj, i);
        return ans;
    }
};
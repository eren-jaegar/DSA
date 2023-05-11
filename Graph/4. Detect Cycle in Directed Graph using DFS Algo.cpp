/*
Approach - 1

do dfs and keep storing the elements that you have visited. basically store the elements 
of the current recursion stack.
keep a teack of all the elements that you have visited as well. this will reduce the
time complexity.


Time Complexity: O(V+E)
Space Complexity: O(V) */


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(bool* visit, bool* instack, vector <int>* adj, int num)
    {
        if(instack[num] == true)
            return true;
        instack[num] = true;
        if(visit[num] == true)
        {
            instack[num] = false;
            return false;
        }
        visit[num] = true;
        bool a = false;
        for(int i=0; i<adj[num].size(); i++)
            a = a||dfs(visit, instack, adj, adj[num][i]);
        instack[num] = false;
        return a;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        bool visit[V] = {0};
        bool instack[V] = {0};
        bool ans = false;
        for(int i=0; i<V; i++)
            ans = ans || dfs(visit, instack, adj, i);
        return ans;
    }
};
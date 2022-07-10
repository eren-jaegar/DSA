/*
Approach - 1

do it normally


Time Complexity: O(V+E)
Space Complexity: O(V) */


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        bool visit[V] = {0};
        queue <int> order;
        vector <int> ans;
        order.push(0);
        int a;
        while(!order.empty())
        {
            a = order.front();
            order.pop();
            if(visit[a] == true)
                continue;
            visit[a] = true;
            ans.push_back(a);
            for(int i=0; i<adj[a].size(); i++)
                order.push(adj[a][i]);
        }
        return ans;
        
    }
};
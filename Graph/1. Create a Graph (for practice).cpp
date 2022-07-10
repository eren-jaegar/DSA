/*
Approach - 1


Time Complexity: O(V+E)
Space Complexity: O(V+E) */


class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        
        vector <vector <int> > nums(V);
        for(int i=0; i<V; i++)
        {
            nums[i].push_back(i);
            for(int j=0; j<adj[i].size(); j++)
            {
                nums[i].push_back(adj[i][j]);
            }
        }
        return nums;
        
    }
};
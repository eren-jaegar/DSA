/*
Approach - 1

first create a adjacency list from the given connections matrix.
now do a dfs
keep track of already visited nodes.
if we encounter a visited node then we know that a link can be severed. so do extra++ to mark
extra connections.
do not increase extra for parent because that's the link from which we have come to the
current node in the first place.
at last do extra/2. this is because every extra link is counted twice.

keep track of number of conenctions required by counting how many different times dfs 
is called from the main function.

Time Complexity: O(V+E)
Space Complexity: O(V+E) //V for adjacency list and E for recursion */


class Solution {
public:
    
    void dfs(vector <bool> &visit, vector <vector <int> > &connect, int i,  int &extra, int parent)
    {
        for(int j=0; j<connect[i].size(); j++)
        {
            if(connect[i][j] == parent)
                continue;
            if(visit[connect[i][j]])
            {
                extra += 1;
            }
            else
            {
                visit[connect[i][j]] = true;
                dfs(visit, connect, connect[i][j], extra, i);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector <vector <int> > adj(n);
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int extra = 0;
        int req = -1;
        vector <bool> visit(n,false);
        for(int i=0; i<n; i++)
        {
            if(visit[i]==false)
            {
                visit[i] = true;
                req++;
                dfs(visit, adj, i, extra, n);
            }
        }
        extra /= 2;
        if(req<=extra)
            return req;
        return -1;
    }
};
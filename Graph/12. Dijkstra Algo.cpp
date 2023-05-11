/*
Approach - 1

Time Complexity: O(?)
Space Complexity: O(?) */

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue <pair <int,int> > order;
        vector <int> dist(V, INT_MAX);
        dist[S] = 0;
        order.push({0,S});
        pair <int,int> x;
        while(!order.empty())
        {
            x = order.top();
            order.pop();
            for(int i=0; i<adj[x.second].size(); i++)
            {
                if(dist[x.second] + adj[x.second][i][1] < dist[adj[x.second][i][0]])
                {
                    dist[adj[x.second][i][0]] = dist[x.second] + adj[x.second][i][1];
                    order.push({dist[adj[x.second][i][0]], adj[x.second][i][0]});
                }
            }
        }
        return dist;
    }
};
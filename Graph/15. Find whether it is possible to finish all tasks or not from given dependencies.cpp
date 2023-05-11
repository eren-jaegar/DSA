/*
Approach - 1

we just need to create the adjacency list and detect if there is any cycle in the formed 
directed graph.


Time Complexity: O(N+P)
Space Complexity: O(N+P) //here N is V and P is E */


class Solution {
public:
    
    
    bool detectcycle(bool* instack, bool* visit, vector<vector <int> >&adj, int nums)
    {
        if(instack[nums])
            return true;
        if(visit[nums])
            return false;
        visit[nums] = true;
        instack[nums] = true;
        bool ans = false;
        for(int i=0; i<adj[nums].size(); i++)
        {
            ans = ans || detectcycle(instack, visit, adj, adj[nums][i]);
        }
        instack[nums] = false;
        return ans;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    vector <vector <int> > adj(N);
	    for(int i=0; i<prerequisites.size(); i++)
	    {
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    bool ans = false;
	    bool visit[N] = {false};
	    bool instack[N] = {false};
	    for(int i=0; i<N; i++)
	    {
	        if(visit[i] == false)
	        {
	            ans = ans || detectcycle(instack, visit, adj, i);
	        }
	    }
	    if(ans)
	        return false;
	    return true;
	}
};
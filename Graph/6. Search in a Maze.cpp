/*
Approach - 1
call for every cell and see if its valid. in case it is then call for all its neighbour cells.
keep a track of every visited node.

Time Complexity: O(4^(N^2))
Space Complexity: O(N*N) */ //considering space used by visit matrix only

class Solution{
    public:
    
    void solve(vector <vector <int> >&m, vector<vector<bool> > &visit, vector<string> &path, string &s, int n, int x, int y)
    {
        if(x<0 || y<0)
            return;
        if(x>=n || y>=n)
            return;
        if(m[x][y] == 0)
            return;
        if(x==n-1 && y==n-1)
        {
            path.push_back(s);
            return;
        }
        if(visit[x][y])
            return;
        visit[x][y] = true;
        s.push_back('D');
        solve(m,visit,path,s,n,x+1,y);
        s.pop_back();
        s.push_back('U');
        solve(m,visit,path,s,n,x-1,y);
        s.pop_back();
        s.push_back('R');
        solve(m,visit,path,s,n,x,y+1);
        s.pop_back();
        s.push_back('L');
        solve(m,visit,path,s,n,x,y-1);
        s.pop_back();
        visit[x][y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector <vector <bool> > visit(n, vector <bool> (n,false));
        vector <string> path;
        string s;
        solve(m, visit, path, s, n, 0, 0);
        return path;
    }
};



/*
Approach - 2
reduce the time complexity by calling for only unvisited nodes.
reduce the space complexity by modifying the matrix instead of using visit matrix.
make visited cell in m as 0 so it won't be visited again.
make it 1 while returning.

Time Complexity: O(3^(N^2))
Space Complexity: O(1) */
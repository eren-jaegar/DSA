/*
Approach - 1
traverse all valid nodes and change their color.
use bfs for traversing the nodes.

Time Complexity: O(?)
Space Complexity: O(N*M) */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        int x = image[sr][sc];
        queue <pair <int,int> > cd;
        cd.push({sr,sc});
        pair <int, int> num;
        int visit[m][n];
        memset(visit, 0, sizeof(visit));
        while(!cd.empty())
        {
            num = cd.front();
            cd.pop();
            if(num.first<0 || num.second<0)
                continue;
            if(num.first>=m || num.second>=n)
                continue;
            if(visit[num.first][num.second] == 1)
                continue;
            if(image[num.first][num.second] == x)
            {
                visit[num.first][num.second] = 1;
                image[num.first][num.second] = color;
                cd.push({num.first+1, num.second});
                cd.push({num.first-1, num.second});
                cd.push({num.first, num.second+1});
                cd.push({num.first, num.second-1});
            }
        }
        return image;
    }
};
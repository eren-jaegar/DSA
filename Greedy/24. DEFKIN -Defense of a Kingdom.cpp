/*
Approach - 1
the biggest unguarded rectangle will be found by finding the biggest unguarded rows and
columns.
so we make two separate vectors for rows and columns of towers.
we sort them. 
find the difference between two consecutive rows and columns and take the maximum.
also, consider the first and last elements and their difference with the boundaries.

the product of the maximum rows difference and maximum columns difference will be the answer.

in case there are no towers then, height*width of the entire grid will be the answer.


Time Complexity: O(NlogN)
Space Complexity: O(1) */


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int w,h;
        cin>>w>>h;
        int n;
        cin>>n;
        vector <int> rows(n);
        vector <int> columns(n);
        for(int i=0; i<n; i++)
        {
            cin>>rows[i];
            cin>>columns[i];
        }
        if(n == 0)
        {
            cout<<w*h<<endl;
            continue;
        }
        sort(rows.begin(), rows.end());
        sort(columns.begin(), columns.end());
        int maxrowdiff = -1;
        int maxcoldiff = -1;
        for(int i=0; i<n-1; i++)
        {
            maxrowdiff = max(maxrowdiff, rows[i+1] - rows[i] - 1);
            maxcoldiff = max(maxcoldiff, columns[i+1] - columns[i] - 1);
        }
        maxrowdiff = max(maxrowdiff, max(rows[0]-1, w-rows[n-1]));
        maxcoldiff = max(maxcoldiff, max(columns[0]-1, h-columns[n-1]));
        cout<<maxrowdiff*maxcoldiff<<endl;
    }
}
/*
Approach - 1

same as 11. Minimum Cost to cut a board into squares in greedy.


Time Complexity: O(NlogN + MlogM)
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
        int m,n;
        cin>>m>>n;
        m--;
        n--;
        vector <int> hor(m);
        vector <int> ver(n);
        for(int i=0; i<m; i++)
            cin>>hor[i];
        for(int i=0; i<n; i++)
            cin>>ver[i];
        sort(hor.rbegin(), hor.rend());
        sort(ver.rbegin(), ver.rend());
        int hcut = 1;
        int vcut = 1;
        int i = 0;
        int j = 0;
        int cost = 0;
        while(i<m && j<n)
        {
            if(hor[i] > ver[j])
            {
                cost += hor[i]*vcut;
                hcut++;
                i++;
            }
            else
            {
                cost += ver[j]*hcut;
                vcut++;
                j++;
            }
        }
        if(i<m)
        {
            while(i<m)
            {
                cost += hor[i]*vcut;
                i++;
            }
        }
        if(j<n)
        {
            while(j<n)
            {
                cost += ver[j]*hcut;
                j++;
            }
        }
        cout<<cost<<endl;
    }
}
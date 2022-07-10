/*
Approach - 1
the maximum distance that a chick can reach in time t is given by:
initial position + speed*t (lets call it maxreach).
if this distance is >= b then the chick can reach the barn else not.
so, we start iterating the array from the end.
we start iterating from the end so that we can keep track of how many slow chicks we have
encountered till we encounter the next fast chick.(explained at last)

now if we encounter a fast chick(a chick that can reach the barn) then do k--
else if we encounter a slow chick(a chick that can't reach the barn) then add current 
value of k to swaps.
this is because, k represents the number of fast chicks behind the current slow chick.
so for those k fast chicks to pass we will need to make k swaps, hence we add k to swaps.

keep doing this until either k becomes 0 or we iterate through the entire array.
if k becomes 0 then print the number of swaps(count) else print impossible.

we only swap fast chick with slow chicks because those slow chicks can't reach the barn.
if a super fast chick gets stuck with a fast chick then we don't need to make a swap
as superfast chick will reach the barn even while moving at the speed of fast chick(ofcourse
because the fast chick can reach the barn and hence it is fast).

if we iterate from the start then we will not know if there are more fast chicks ahead.
lets say there were k+1 fast chicks. minimum swaps will be required if we take the
last k fast chicks rather than first k fast chicks.

hence starting from start will result in difficult implementation.


Time Complexity: O(N)
Space Complexity: O(1) //space is required to store distances and speed not for doing
the task. */


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long int c;
    cin>>c;
    for(long long int i=1; i<=c; i++)
    {
        long long int n,k,b,t;
        cin>>n>>k>>b>>t;
        vector <long long int> dist(n);
        vector <long long int> speed(n);
        for(long long int j=0; j<n; j++)
            cin>>dist[j];
        for(long long int j=0; j<n; j++)
            cin>>speed[j];
        long long int count = 0;
        long long int j = n-1;
        while(j>=0 && k)
        {
            if((dist[j] + speed[j]*t) >= b)
                k--;
            else
                count += k;
            j--;
        }
        if(k)
            cout<<"Case #"<<i<<": IMPOSSIBLE\n";
        else
            cout<<"Case #"<<i<<": "<<count<<"\n";
    }
}
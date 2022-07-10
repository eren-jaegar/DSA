/*
Approach - 1
we have to find the maximum value possible.
we need to realize that the power is more important than the base.
lets understand this with an example:
lets say the current signal strength is X and now we have to decide between two numbers a 
and b. we know that a>b. we need to decide whether we should place a first or b first.
if we place a first we get b^(a^(X)) and we place b first be get a^(b^(X)).
now we can take any two numbers a and b and take log to compare these expressions,
we will find that if a>b then b^(a^(X))>a^(b^(X)) i.e., a should be plces first.
the only exception to this is when X=1, a=3, b=2. in this case the opposite is true.

(try solving by taking log for the exception. you will find that for X>=1.1(approx.)
the exception also follows the rule and for all other numbers the rule is followed for X>=1,
the limit of X from which the rule starts to follow is less than 1 for every other possible
pair if number except 2&3 for whih it is about 1.1).

another thing that we need to take care of is that if there are 1s in the given data then
they need to appear in the start because 1^X is 1 so if they apear later then they will just
reduce the signal to 1.

so, this is what the solution looks like:
sort the array in descending order.
move all the 1s to the start of the array.
if the only elements apart from 1 are 2 and 3 then swap their positions. do this, even if
1 is not present and only 2 and 3 are present. but if any other number apart from 1,2 or 3
is pesent then don't swap them.

we have our answer.


Time Complexity: O(NlogN)
Space Complexity: O(1) //the task itself doesn't require any extra space. */


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
        int n;
        cin>>n;
        int count = 0;
        vector <int> amp(n);
        for(int i=0; i<n; i++)
        {
            cin>>amp[i];
            if(amp[i] == 1)
                count++;
        }
        sort(amp.rbegin(), amp.rend());
        if(n>1)
        {
            if(amp[0]==3 && amp[1]==2 && count+2==n)
                swap(amp[0],amp[1]);
        }
        if(count)
        {
            int i = n-1;
            int j = i-count;
            while(j>=0)
            {
                swap(amp[i],amp[j]);
                i--;
                j--;
            }
        }
        for(int i=0; i<n; i++)
            cout<<amp[i]<<" ";
        cout<<endl;
    }
}
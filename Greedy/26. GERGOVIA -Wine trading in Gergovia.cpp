/*
Approach - 1
we start from left end and start making pairs.
the first seller sells to the first buyer until one of them exhausts.
then we move on to the next person of the category who has exhausted.
for example: lets say first buyer bought from first seller.
the seller reached its limit but the buyer did not so we move on to next seller.
then the new seller sells to old buyer till one of them reaches their limit.
the process continues like this.

another good explanation is as follows:
any solution is right as long as it follows this one condition:

CONDITION: The wine shouldn't travel in opposite directions over some common distance.

Explanation: lets say we have four people, 1,2,3,4. 1 & 4 are sellers and 2 & 3 are buyers.
if 1 sells to 3 then wine travels in right direction from 2 to 3. and if 4 sells to 2
then wine travels in left direction from 3 to 2.
in this case the wine travels in opposite direction over some common distance i.e.,
distance between 2 and 3.
so, this is not the right solution as it will make some unnecessary moves.

Note: it is allowed for wine to come to same point from opposite directions. for ex.
1,2,3; if 1 and 3 are sellers and 2 is a buyer then wine can come from 1 and 3 to 2 and 
it will be right as wine has not travelled any common distance.

out logic always satisfies this condition hence it works. though, there may be several
other answers as well that satisfy this condition.


Time Complexity: O(N)
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
    long long int n;
    while(cin>>n)
    {
        if(n == 0)
            exit(0);
        vector <long long int> nums(n);
        for(long long int i=0; i<n; i++)
            cin>>nums[i];
        long long int i = 0;
        long long int j = 0;
        long long int ans = 0;
        while(i<n && j<n)
        {
            while(i<n && nums[i] <= 0)
                i++;
            while(j<n && nums[j] >= 0)
                j++;
            if(i>=n || j>=n)
                break;
            ans += (abs(i-j)*min(nums[i],(-1*nums[j])));
            if(nums[i]<(-1*nums[j]))
            {
                nums[j] += nums[i];
                nums[i] = 0;
            }
            else
            {
                nums[i] += nums[j];
                nums[j] = 0;
            }
        }
        cout<<ans<<endl;
    }
}
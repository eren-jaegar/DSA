/*
Approach - 1
we need to survive for the maximum time.
so it is obvious that it is best to start in air as it increases both the health and the 
armor.
at every odd move, we should come to air. and at every even move we can either go to
fire or water and that we have to decide.

as long as we have sufficient health and armor, we find keep alternating between
water and air.
if we run out of armor then we should go to fire(via air ofcourse).
then again we should keep oscillating between air and water as long as we have armor and
health. again if we run out of armor then we should go to fire.

this is because if we go to fire then we lose a lot of health.
if we ever need to go to fire because we are low on armor then we can go else there is no
need to go to fire for any reason. as if we run out of armor then we can always go to fire
else no need to go there. if we run out og health then it can't be replenished as 
efficiently as armor.

Time Complexity: O(?) //prolly O(min(H,A))
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
        int h,a;
        cin>>h>>a;
        int count = 0;
        while(h>0 && a>0)
        {
            h += 3;
            a += 2;
            count++;
            if(a > 10)
            {
                h -= 5;
                a -= 10;
                count++;
            }
            else
            {
                h -= 20;
                a += 5;
                count++;
            }
        }
        count--; //it is reduced once because the second we die is also counted but it shouldn't be.
        cout<<count<<endl;
    }
}
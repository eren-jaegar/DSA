/*NOTE: It is not clear from the question but what they mean by edge is that when you
encounter a break in the board and then move onto cut its next disjoint piece.

see 28. CHOCOLA –Chocolate question for understanding the question. It's the same as this
one */


/*
Approach - 1

first realize that the cost of cutting will be minimized when we make the cuts with the
highest cost first.
costs horizontal cuts are independent of each other and costs of vertical cuts are 
independent of each other.
but the costs of horizontal cuts are dependent on the vertical cuts and vice versa.

to minimize the cost, we need to make the horizontal/vertical cut with higher cost
before making a vertical/horizontal cut with lesser cost.

understand this with an example.
let the current total number of horizontal cuts be X and current total number of vertical
cuts be Y.
now, let there be a horizontal cut with cost "a" and a vertical cut with cost "b" such that
a>b.
total cost if we make the vertical cut first comes out to be = (X+1)b + (Y+2)a
total cost if we make the horizontal cut first comes out to be = (X+2)b + (Y+1)a
since, a>b so it is clear that making the costly cut first gives less cost than making the
less cheaper cut first.
in case, the cost of both the cuts are equal then we can make either of the cut first.
this is evident as the above expressions will have same value if a==b.

So, we just sort the two given vectors independently and then use the marge sort process
to find the cost.
while making a vertical cut, increase the vertical cut count and do the same while making
a horizontal cut.

Time Complexity: O(NlogN + MlogM)
Space Complexity: O(1) */


class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        
        int horizontal = 0; //number of horizontal cuts
        int vertical = 0; //number of vertical cuts
        int cost = 0; //total cost of cutting
        sort(X.rbegin(), X.rend());
        sort(Y.rbegin(), Y.rend());
        int i = 0;
        int j = 0;
        while(i<M && j<N)
        {
            if(X[i] >= Y[j])
            {
                vertical++;
                cost += X[i]*(horizontal+1);
                i++;
            }
            else
            {
                horizontal++;
                cost += Y[j]*(vertical+1);
                j++;
            }
        }
        if(i<M)
        {
            while(i<M)
            {
                cost += X[i]*(horizontal+1);
                i++;
            }
        }
        if(j<N)
        {
            while(j<N)
            {
                cost += Y[j]*(vertical+1);
                j++;
            }
        }
        return cost;
    }
};
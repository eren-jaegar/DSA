/*
Approach - 1
find the sum of each stack individually.
run a loop and iterate through all the stacks in it.
if at any point the sum of all the three stacks is same then break the loop.
else, if the sum of any stack is greater than the sum of either of the remaining two
stacks, then pop its top element and subtract it from the sum.
this is because if its sum is more then, its current sum can't be the answer so either the
answer is 0 or any other positive integer less than its current value. so, we pop the 
top element to reduce it.


Time Complexity: O(N1+N2+N3)
Space Complexity: O(1) */

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        for(int i=0; i<N1; i++)
            sum1 += S1[i];
        for(int i=0; i<N2; i++)
            sum2 += S2[i];
        for(int i=0; i<N3; i++)
            sum3 += S3[i];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<N1 && j<N2 && k<N3)
        {
            if(sum1==sum2 && sum2==sum3)
                break;
            if(sum1>sum2 || sum1>sum3)
            {
                sum1 -= S1[i];
                i++;
            }
            if(sum2>sum1 || sum2>sum3)
            {
                sum2 -= S2[j];
                j++;
            }
            if(sum3>sum1 || sum3>sum2)
            {
                sum3 -= S3[k];
                k++;
            }
        }
        if(sum1==0 || sum2==0 || sum3==0)
            return 0;
        return sum1;
    }
};


//some minor changes in the same code:

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        for(int i=0; i<N1; i++)
            sum1 += S1[i];
        for(int i=0; i<N2; i++)
            sum2 += S2[i];
        for(int i=0; i<N3; i++)
            sum3 += S3[i];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<N1 && j<N2 && k<N3)
        {
            if(sum1==sum2 && sum2==sum3)
                break;
            if(sum1>sum2 || sum1>sum3)
            {
                sum1 -= S1[i];
                i++;
            }
            if(sum2>sum1 || sum2>sum3)
            {
                sum2 -= S2[j];
                j++;
            }
            if(sum3>sum1 || sum3>sum2)
            {
                sum3 -= S3[k];
                k++;
            }
        }
        if(sum1==0 || sum2==0 || sum3==0)
            return 0;
        return sum1;
    }
};



//slightly different implementation:
//the first code can do popping from several stacks in the same run of the loop whereas
//this code only pops element from one stack in one run.


class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        for(int i=0; i<N1; i++)
            sum1 += S1[i];
        for(int i=0; i<N2; i++)
            sum2 += S2[i];
        for(int i=0; i<N3; i++)
            sum3 += S3[i];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<N1 && j<N2 && k<N3)
        {
            if(sum1==sum2 && sum2==sum3)
                break;
            if(sum1>sum2 || sum1>sum3)
            {
                sum1 -= S1[i];
                i++;
            }
            else if(sum2>sum1 || sum2>sum3)
            {
                sum2 -= S2[j];
                j++;
            }
            else
            {
                sum3 -= S3[k];
                k++;
            }
        }
        if(sum1==0 || sum2==0 || sum3==0)
            return 0;
        return sum1;
    }
};
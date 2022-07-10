//NOTE: a comparison is to check whether A knows B or not


//Approach - 1
//brute force approach
//check all the rows. if we encounter any row with all elements as zeroes then, it is a
//potential celebrity. if we don't encounter any such row then there is no celebrity.
//now, for the same column numbre as the row number found in previous step, check all the
//rows. if that column has only 1 zero at M[i][i] then it is a celebrity else there is no
//celebrity.

//we do not have to check if there are multiple such rows in the first step because if there
//were more such rows then that means that there will be no celebrity so, it gets checked in
//the second step. if there are more such rows then we will get that there is no celebrity
//in the second step.

//Time Complexity: O(N^2)
//Space Complexity: O(1)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int count = 0;
        int k = -1;
        for(int i=0; i<n; i++)
        {
            count = 0;
            for(int j=0; j<n; j++)
            {
                if(M[i][j] == 0)
                    count++;
            }
            if(count == n)
            {
                k = i;
                break;
            }
        }
        if(k == -1)
            return -1;
        
        count = 0;
        for(int i=0; i<n; i++)
        {
            if(M[i][k] == 0)
                count++;
        }
        if(count == 1)
            return k;
        return -1;
    }
};



//Approach - 2
//we start by taking two variables i and j initialized to 0 and 1 respectively.
//now, we check M[i][j] and M[j][i]. if they both are 0 or 1 then none of them can be 
//the celebrity as they both either don't know each other or they both know each other.
//in this case we make i point to the next row as j and we make j point to the row next
//row to which now i is pointing.

//in case M[i][j] is 0 and M[j][i] is 1 then i can be a celebrity but j cannot be
//a celebrity so we keep i where it is and move j one row ahead.

//in case M[i][j] is 1 and M[j][i] is 0 then j can be celebrity but i cannot be a 
//celebrity so we move i to j and we move j forward by 1 row.

//after j becomes >= n we stop this process.

//now if i is >= n then there is no celebrity. but if it is i<n then the row pointed by i
//is a potential celebrity so, we check for ith row that there should be n 0s and we also
//check for ith column that there should be only one 0. if this is the case then, i is the
//celebrity else it is not.

//Time Complexity: O(N)
//Space Complexity: O(1)
//Number of comparisons = 4N-2 (in worst case)


//NOTE: create a stack and push all indexes(IDs) in a stack if they are not freely accessible
//like in case if a queue, not all the elements can be accessed without removing the front
//elements.
//pop two ids from the stack, make a comparison and push the potential celebrity back in.


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i = 0;
        int j = 1;
        while(j<n)
        {
            if(M[i][j] == M[j][i])
            {
                i = j+1;
                j += 2;
            }
            else if(M[i][j] == 0)
                j++;
            else
            {
                i = j;
                j++;
            }
        }
        int count1 = 0;
        int count2 = 0;
        if(i>=n)
            return -1;
        for(int k=0; k<n; k++)
        {
            if(M[i][k] == 0)
                count1++;
            if(M[k][i] == 0)
                count2++;
        }
        if(count1==n && count2==1)
            return i;
        return -1;
    }
};



//Approach - 3
//pretty much similar to the above approach.
//but to reduce the number of comparisons, we just check whether i knows j or not.
//if it doesn't know j then j can't be celebrity so move j forward.
//if it knows j then i cannot be a celebrity so, make i=j and move j forward.

//after this, finally check whether the row pointed by i is the celebrity or not by
//checking number of 0s in ith row and ith column.

//this reduces the number of comparison by N-1.

//Time Complexity: O(N)
//Space Complexity: O(1)
//Number of comparisons = 3N-1 (in worst case or rather in every case)

//NOTE: create a stack and push all indexes(IDs) in a stack if they are not freely accessible
//like in case if a queue, not all the elements can be accessed without removing the front
//elements.
//pop two ids from the stack, make a comparison and push the potential celebrity back in.


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i = 0;
        int j = 1;
        while(j<n)
        {
            if(M[i][j] == 0)
                j++;
            else
            {
                i = j;
                j++;
            }
        }
        int count1 = 0;
        int count2 = 0;
        
        for(int k=0; k<n; k++)
        {
            if(M[i][k] == 0)
                count1++;
            if(M[k][i] == 0)
                count2++;
        }
        if(count1==n && count2==1)
            return i;
        return -1;
    }
};



//Approach - 4
//we use the two pointer method.
//initialize one pointer(say i) to 0 and other(say j) to n-1.
//if i knows j then i cannot be a celebrity so move it forward.
//if i doesn't know j then j cannot be a celebrity so reduce j by 1.
//do this till j>i.

//after this, check if i is the celebrity by counting number of 0s in the ith row and
//in the ith column.

//Time Complexity: O(N)
//Space Complexity: O(1)
//Number of comparisons = 3N-1 (in worst case or rather in every case)

//NOTE: create a stack and push all indexes(IDs) in a stack if they are not freely accessible
//like in case if a queue, not all the elements can be accessed without removing the front
//elements.
//pop two ids from the stack, make a comparison and push the potential celebrity back in.


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i = 0;
        int j = n-1;
        while(j>i)
        {
            if(M[i][j] == 0)
                j--;
            else
                i++;
        }
        
        int count1 = 0;
        int count2 = 0;
        
        for(int k=0; k<n; k++)
        {
            if(M[i][k] == 0)
                count1++;
            if(M[k][i] == 0)
                count2++;
        }
        if(count1==n && count2==1)
            return i;
        return -1;
    }
};



//Approach - 5
//using recursion
//same approach as above, just implemented using recursion

//Time Complexity: O(N)
//Space Complexity: O(N) //recursion stack uses space
//Number of comparisons = 3N-1 (in worst case or rather in every case)


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int findcelebrity(int n, vector<vector<int> >& M)
    {
        if(n==0)
            return -1;
         int a = findcelebrity(n-1,M);
         
         if(a==-1)
            return n-1;
         
         if(M[a][n-1])
            return n-1;
        
        return a;
    }
    
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int a = findcelebrity(n,M);
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[a][i] == 0)
                count1++;
            if(M[i][a] == 0)
                count2++;
        }
        if(count1 == n && count2 == 1)
            return a;
        return -1;
    }
};
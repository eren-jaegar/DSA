//Approach - 1
//brute force approach
//run two nested for loops and check for every subarray of size k, which is the first 
//negative element.

//Time Complexity: O((N-K+1)*K) ~ O(N*K)
//Space Complexity: O(1) //we require space only to store and return the answer.
//if we were to print it then we wouldn't have required anu extra space.



//Approaxh - 2
//we create a queue and push the index of the useful elements. useful elements here
//are negative elements that lie within the current subarray.
//if any negative element does not lie within the current subaraay then we remove it 
//from out queue.
//if the queue is empty then that means there are no negative elements in the 
//current subarray so, we push 0 into ans vector else we push element at the index 
//which is at the front of the queue.

//Time Complexity: O(N)
//Space Complexity: O(K) //we can store a maximum a of K elements in the deque as
//the length of subarray is K.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
        queue <int> negnum;
        vector <long long> ans;
        for(int i=0; i<K; i++)
        {
            if(A[i]<0)
                negnum.push(i);
        }
        
        for(int i=K; i<N; i++)
        {
            if(!negnum.empty())
                ans.push_back(A[negnum.front()]);
            else
                ans.push_back(0);
                
            while(!negnum.empty() && negnum.front()<=i-K)
                negnum.pop();
                
            if(A[i]<0)
                negnum.push(i);
        }
        if(!negnum.empty())
            ans.push_back(A[negnum.front()]);
        else
            ans.push_back(0);
            
        return ans;                                                 
 }



//Approach - 3
//we use the sliding window approach.
//we maintain a variable that stores the index of the first negative number in the 
//subarray.
//if the index gets out of lower bounds of subarray then we increase it till it 
//beomes negative or hitd the upper bound of the subarray.
//if it is non-negative even after hitting the upper bounds of the subarray then,
//it means that there is no negative number in the curren subarray.

//Time Complexity: O(N)
//Space Compplexity: O(1) //we require space only to store and return the answer.
//if we were to print it then we wouldn't have required anu extra space.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        
        vector <long long> ans;
        int i = 0;
        int j = K-1;
        int p = 0;
        for(; j<N; i++,j++)
        {
            if(p<i)
            {
                for(p=i; p<j; p++)
                {
                    if(A[p] < 0)
                        break;
                }
            }
            if(A[p]>=0)
            {
                for(; p<j; p++) //we don't do p<=j because then, before coming out of
                	//loop, p might become j+1 and it will go out of bounds of the current
                	//subarray.
                {
                    if(A[p] < 0)
                        break;
                }
            }
            if(A[p]<0)
                ans.push_back(A[p]);
            else
                ans.push_back(0);
        }
        return ans;
 }



 //Same approach, different implementation

 vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
        vector <long long int> ans;
        int index = 0;
        
        for(int i=K-1; i<N; i++)
        {
            while((index<i) && (index <= i-K || A[index]>=0))
                index++;
            
            if(A[index]<0)
                ans.push_back(A[index]);
            else
                ans.push_back(0);
        }
        return ans;
                                                 
 }
//Approach - 1
//dequeue all the elements into an array and then first push the first k elements in 
//reverse order and then push the remaining size-k elements in the original order.

//Time Complexity: O(N)
//Space Complexity: O(N)

queue<int> modifyQueue(queue<int> q, int k) {
    
    int arr[q.size()];
    
    int j = q.size();
    for(int i=0; i<j; i++)
    {
        arr[i] = q.front();
        q.pop();
    }
    for(int i=k-1; i>=0; i--)
    {
        q.push(arr[i]);
    }
    for(int i=k; i<j; i++)
        q.push(arr[i]);
    
    return q;
    
}



//Approach - 2
//better solution
//push the first k elements into a stack and then pop them out while inserting into
//the queue.
//now pop the first size-k elements from queue and push them one by one into the queue.
//push them directly into the queue as they are not to be reversed.

//Time Complexity: O(N)
//Space Complexity: O(K)

queue<int> modifyQueue(queue<int> q, int k) {
    
    stack <int> nums;
    int j = q.size();
    for(int i=0; i<k; i++)
    {
        nums.push(q.front());
        q.pop();
    }
    
    while(!nums.empty())
    {
        q.push(nums.top());
        nums.pop();
    }
    j -= k;
    while(j--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
    
}
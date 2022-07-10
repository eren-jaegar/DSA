//Approach - 1
//just call a recursive function.
//the recursive function pops the values out until the queue is empty.
//then, while returning it pushes back the values that it had popped out.

//NOTE: pass the queue by address or reference, because if we pass by value it probably
//becomes a O(N^2) solution. this is because when it returns the queue, its assignment
//takes O(N) time. (probably, not sure though, so ask once)

//Time Complexity: O(N)
//Space Complexity: O(N) //used by recursion stack

void reverse(queue <int> &q)
{
    int a;
    if(q.empty())
        return;
    
    a = q.front();
    q.pop();
    reverse(q);
    q.push(a);
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}



//NOTE: if we do not want to use recursion, then we could have used stack as well.
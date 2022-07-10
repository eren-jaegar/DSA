//find the maximum index you can reach from index 0.
//maximum index is index+arr[index].
//initialize i to maximum index and increase count by 1 to show that
//you have jumped from previous index to new index.
//now, start checking from max index of previous index(i.e. previous i)
//till max index of current index.
//repeat till you reach n-1 index.

class Solution{
  public:
    int minJumps(int arr[], int n){
        int i = 0;
        int a;
        int best = 0;
        int count = 0;
        int j = 1;
        int k;
        while(i < n-1)
        {
            if(arr[i] == 0)
                return -1;
            if(arr[i] + i >= n-1)
            {
                count++;
                return count;
            }
            else
            {
                for(; j<=arr[i]; j++)
                {
                    //a = arr[i+j] - (arr[i] - j);
                    best = max(best,arr[i+j]+i+j);
                    if(best == arr[i+j]+i+j)
                        k = i+j;
                }
                j = (i+j-k);
                i = k;
                count++;
                best = 0;
               // cout<<i<<endl<<j<<endl<<k<<endl;
            }
        }
        return count;
    }
};
/*
Approach - 1
we use a priority queue.
sort the elements according to their arrival time.
now push the departure time of the first train in the queue.
initialize a counter to 1.
iterate through the array.
if the arrival time of the train is more than the top element in the queue which is a
departure time then pop it and push the current train's departure time. this signifies that
the earlier train has been removed from the platform and the current train has been put
in its place.
in case the arrival time is smaller then the departure time, then it is smaller then all the
departure times in the queue as the queue is made as a min heap.
so we push the current train's departure time in the queue and increase the counter by 1.

in the end, return the counter.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector <pair <int,int> > trains(n);
        for(int i=0; i<n; i++)
        {
            trains[i].first = arr[i];
            trains[i].second = dep[i];
        }
        sort(trains.begin(), trains.end());
        int count = 1;
        priority_queue <int, vector <int>, greater <int> > p;
        p.push(trains[0].second);
        for(int i=1; i<n; i++)
        {
            if(trains[i].first <= p.top())
                count++;
            else
                p.pop();
            p.push(trains[i].second);
        }
        return count;
    }
};



/*
Approach - 2
sort both the arrays individually and then use merge sort on these arrays.
if we element in arrival is smaller than or equal to the element in departure then increase
counter by 1.
else decrease the counter.
maximum value of counter throughout this process is taken as the answer.

we are basically seeing when we habe the max number of trains together.
if there is an arrival but no departure then naturally we will require one extra platform
and if there is a departure then we require one less platform.
so, the maximum value of count throughout the process is the answer.

Time Complexity: O(NlogN)
Space Complexity: O(1) */



/*
Approach - 3
based on the above approach.
we use a map/array to keep track of when we require a platform i.e., when a train has 
arrived and when we don't require a platform i.e., when the train has left.
then we go through that array summing all its values. the maximum value of sum during this
process will be the answer.

Time Complexity: O(N)
Space Complexity: O(1) //an array of size 2361 is required irrespective of number of trains. */


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int platform[2361] = {0}; //2361 because for departure time 2359 we will reduce value at 2360.
        for(int i=0; i<n; i++)
        {
            platform[arr[i]]++;
            platform[dep[i]+1]--;
        }
        int sum = 0;
        int ans = 0;
        for(int i=0; i<2361; i++)
        {
            sum += platform[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
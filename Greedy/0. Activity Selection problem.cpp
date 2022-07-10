/*
Approach - 1
sort the activities according to their finish time and then select the start selecting the 
activities. 
the first activity is always selected, declare a variable endtime. make endtime = finish
time of selected activity.
traverse in the selected array till you find an activity whose start time is greater than
endtime.
select that activity, increase the count and then make endtime = finish time of this
selected activity.

Time Complexity: O(NlogN)
Space Complexity: O(N) */

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int count = 0;
        vector <pair <int,int> > time(n);
        for(int i=0; i<n; i++)
        {
            time[i].first = end[i];
            time[i].second = start[i];
        }
        sort(time.begin(), time.end());
        int endtime = -1; //initialized to -1 so that tge first activity gets selectes even if its start time is 0.
        int j = 0;
        while(j<n)
        {
            while(j<n && time[j].second <= endtime)
                j++;
            if(j<n)
            {
                count++;
                endtime = time[j].first;
            }
        }
        return count;
    }
};
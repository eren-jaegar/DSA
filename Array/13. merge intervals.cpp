//sort the intervals by their first element.
//if the ending of a interval is greater than the starting of the next
//interval then there is an overlap.
//for an overlap the starting interval is taken as the start of the first overlapped
//interval but ending interval is taken as the maximum of end of all the overlapping
//intervals.
//bool is used because if last interval is not merged than it is not
//considered/traversed because for loop only goes till intervals.size()-2.

sort(intervals.begin(),intervals.end());
        vector <vector <int> > answer;
        int start;
        int end;
        int a;
        bool done = true;
        if(intervals.size() == 1)
            answer.push_back(intervals[0]);
        else
        {
            for(int i=0; i<intervals.size()-1; i++)
            {
                if(intervals[i][1] >= intervals[i+1][0])
                {
                    start = intervals[i][0];
                    a = intervals[i][1];
                    while(a >= intervals[i+1][0])
                    {
                        if(i == intervals.size()-2)
                            done = false;
                        a = max(a,intervals[i+1][1]);
                        end = a;
                        i++;
                        if(i == intervals.size()-1)
                            break;
                    }
                    vector <int> v = {start,end};
                    answer.push_back(v);
                }
                else
                {
                    answer.push_back(intervals[i]);
                }
            }
            if(done)
                answer.push_back(intervals[intervals.size()-1]);
        }
        return answer;



//better implementation of the same approach (taken directly from website)

sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
/*
Approach - 1
make a vector of vector of pairs.
we will store the trains according to their platforms.
the first vector is to store trains as per their platforms.
in a particular nested vector, we store the incoming and outgoing times of trains for a
particular platform.
after storing this, we sort all the vectors according to the time of outgoing of trains.
after sorting it is the same as activity selection problem.
so, we just select the first train for the current platform then look for the next train 
whose incoming time is later than the outgoing time of the selected train, then we
select it.
do it for all the vectors, i.e., for all the platforms.
the platforms are independent of each other.

Time Complexity: O(NlogN) //N is the number of trains.
Space Complexity: O(N) */
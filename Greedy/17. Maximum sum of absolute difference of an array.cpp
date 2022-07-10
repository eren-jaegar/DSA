//see next question(Q-18) for implementation.


/*
Approach - 1
we need to maximize the absolute sum.
sum will be maximum when we subtract large values from small values.
this can be achieved by first sorting the array.
now, construct a new array. in this we put the elements of original array alternatively.
first insert the first element and then insert the last element. then insert the second
element and then insert the second last element and so on...
the array thus constructed will have the maximum absolute sum.

Time Complexity: O(NlogN)
Space Complexity: O(N) */


/*
if we don't construct a new vector and instead use two pointers moving from beginning and
ending to find the sum then we can do this in O(1) space.

Time Complexity: O(NlogN)
Space Complexity: O(1) */
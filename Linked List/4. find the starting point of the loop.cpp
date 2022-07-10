//pretty much similar to finding whether there is a loop or not.

//approach-1
//using hashing. save addresses in a hash map. the first address that repeats is the answer.

//Time Complexity: O(N)
//Space Complexity: O(1)



//approach-2
//use floyds algorithm and let slow and fast meet. Now, make slow = head. move slow and
//fast by 1 till they are equal. the point where they are equal is the first node in the 
//loop. even if they already meet at head while determining the loop, then head node will be
//the first node in the loop.
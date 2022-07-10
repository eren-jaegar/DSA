//Approach - 1
//we can implement deque using doubly linked list or use stl deque.
//either way, for implementing stack, we can use push_back function of deque for pushing
//elements into stack and we can use pop_back function of deque for popping elements
//out of stack.
//for accessing top element of stack we can use, back() function.
//empty() and size() can be used for checking if the stack is empty or not, and what
//its size is.

//all of this can be done in O(1) time and O(1) space. O(1) space because queue uses
//space(basically space used by stack) but these functions don't require any extra 
//space.


//Time Complexity: O(1)
//Space Complexity: O(1) because queue uses space(basically space used by stack)
//but these functions don't require any extra space.



//NOTE: instead of using push_back(), pop_back() and back() we could have also used
//push_front(), pop_front() and front().
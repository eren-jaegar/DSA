//Approach - 1
//we use two pointer method.
//first pointer is initialized to head and second pointer is moved to the last node of
//the DLL.
//then we add their data and compare with the required sum
//if the addition of data is less than the required sum then, we move the first pointer
//forward. if the addition is more than the required sum then we move the second pointer
//to the previous node. if the addition is equal to the required sum then we move the 
//first pointer to next node and the second pointer to the previous node.
//the condition to break out of loop will be first!=second && first->prev!=second
//as either only one pointer may move or both the pointers may move.

//Time Complexity: O(N)
//Space Complexity: O(1)



//Approach - 2
//we can use hash map to store the elements. if (sum-current element) is present in frequency
//map then we have a pair else insert that element in the frequency map and move on to the
//next element.

//Time Complexity: O(N)
//Space Complexity: O(N)

//Note: This method can be used for unsorted lists as well.

//Note: Another method to use for unsorted lists is to sort their elements(probably by storing in an array first)
//and then use either of the approach

//Time Complexity: O(NlogN)
//Space Complexity: O(N) //if we use first approach then also it should be O(N) i guess,
//because we can't directly sort the list and have to first store its elements in an array
//or vector or set or any other suitable container.
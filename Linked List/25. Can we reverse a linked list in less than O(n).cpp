//No, we can not reverse a singly linked list in less than O(N) time as we have to access
//every node and change its next pointer. So, this will require O(N) time.

//We can't reverse a doubly linked list in less than O(N) time as well because it also
//requires accessing every node and swapping their prev and next pointers.
//Though it does require less operations than a singly linked list.

//Same is true for circular singly linked list and circular doubly linked list, as we will
//have to access every node and change their next and prev(only in case of doubly linked list)
//pointers.



//For reversing a linked list of any type:

//Time Complexity: O(N)
//Space Complexity: O(1) 
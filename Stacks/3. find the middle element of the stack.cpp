//We have to find and delete the middle element of the stack in O(1) time.
//we know that if we use an array then we can't delete the middle element in O(1) time
//as after removing the middle elements, we will have to move the elements stacked
//above the middle element(by one place down to fill the void made by removing the 
//middle element) so it will tke O(N) time.

//We can use linked list. if we maintain a pointer that points to the middle element
//then we can delete it in O(1) time. But, while using pop() or push(), the size of
//the linked list changes and hence, the middle element might change as well.
//So, we will have to move the middle pointer forward or backward but it is not
//possible to move the pointer backwards in singly linked list.
//if we try to maintain a pointer that points to the element previous to the current
//element, even then it won't work. this is because we can move the middle pointer back
//once and then we will need to move the previous pointer back too, which will take
//O(N) time and hence not efficient.


//So, we use Doubly linked list and maintain a pointer that points the middle element
//of the stack.
//Using this we can execute pop, push, findMiddle and deleteMiddle functions in O(1)
//time.



//ARTICLE LINK - https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
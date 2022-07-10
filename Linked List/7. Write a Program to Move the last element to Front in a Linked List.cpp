//initialize two pointers current and prev.
//move them till the last of the linked list i.e. with condition while(current->next != NULL)
//after this, make prev as the last element by prev->next = NULL.
//make current as the first element by current->next = head (now it points on the original first element)
//and head = current; this makes the last element as the first element.

//Time Complexity: O(N)
//Space Complexity: O(1)
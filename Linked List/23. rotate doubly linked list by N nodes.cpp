//Approach - 1

//this is to rotate the list in counter clockwise direction.

//iterate till the last element and make the list circular by making last_node->next = head
//and head->prev = last_node.
//then initialize a pointer and with head. move this pointer forward p times.
//now, this pointer is pointing to the node which will be our new head. 
//so, now make the list linear by making the currently pointed node as the first node and 
//its previous node as the last node. Do this by making current->prev->next = NULL &
//current->prev = NULL.
//change head so that it points to the new head by doing head = current.

//Time Complexity: O(N)
//Space Complexity: O(1)

//Link to the question: https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/

class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        Node* current = start;
        while(current->next)
            current = current->next;
        current->next = start;
        start->prev = current;
        current = start;
        while(p--)
        {
            current = current->next;
        }
        current->prev->next = NULL;
        current->prev = NULL;
        start = current;
    }
}; //in question ; was missing here. So remember to add it if you try to do the question again.


//In order to rotate the list in clockwise direction, first make the list circular as above
//and then move backwards p times from the head node to reach the node which will be the 
//new head node. Now, make the list linear by following same process as describes above.
//change head so that it points to the new head.

//Time Complexity: O(N)
//Space Complexity: O(1)
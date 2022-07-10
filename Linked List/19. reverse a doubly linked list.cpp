//Approach - 1
//iterate from start to end of list.
//keep swapping the node->next and node->prev pointers.
//works for lists with only one node also. Both the next and prev are NULL so they get
//switched and then current->prev == NULL becomes true so it breaks out of loop.

//Time Complexity: O(N)
//Space Complexity: O(1)

    Node* current = head;
    while(1)
    {
        swap(current->prev, current->next);
        if(current->prev == NULL)
            break;
        current = current->prev;
    }
    head = current;



//Approach - 2
//we could have swapped the node->data also using two pointers from start and end.
//Though this could be more costly as compared to swapping pointers if the size of the data
//items is more.

//Time Complexity: O(N)
//Space Complexity: O(1)



//Approach - 3
//we can use stack or array to store data elements and then put them in list in reverse
//order.

//Time Complexity: O(N)
//Space Complexity: O(N)    
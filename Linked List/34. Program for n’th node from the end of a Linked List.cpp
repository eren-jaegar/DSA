//Approach - 1
//find the size of the linked list.
//if the size < n then return -1 as the element does not exist;
//else initialize a pointer to head and move it size-n times.
//return the data of the node pointed by current.

//Time Complexity: O(N)
//Space Complexity: O(1)

int getNthFromLast(Node *head, int n)
{
    int size = 0;
    Node* current = head;
    while(current)
    {
        size++;
        current = current->next;
    }
    if(n > size)
        return -1;
    int to_travel = size-n;
    current = head;
    while(to_travel--)
        current = current->next;
        
    return current->data;
        
}

//Note: We could have also used recursion.



//Approach - 2
//we take two pointers and initialize them to head. move one of them forward n times
//if we encounter NULL before completing it moving n times forward then return -1 else,
//now move both the pointers forward till the ahead pointer reaches the end of the list.
//return the data of the node pointed by the pointer that is behind.

//Time Complexity: O(N)
//Space Complexity: O(1)

int getNthFromLast(Node *head, int n)
{
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(n && ptr2)
    {
        ptr2 = ptr2->next;
        n--;
    }
    if(n)
        return -1;
    while(ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
    
}
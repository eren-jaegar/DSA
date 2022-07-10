//iterate through entire linked list using two pointers and keep checking if their data is
//same or not. if it is same then remove the node pointed by next

//Time Complexity: O(N)
//Space Complexity: O(1)

    Node* current = head;
    Node* next = NULL;
    Node* temp = NULL;
    next = current->next;
    while(next)
    {
        
        if(current->data == next->data)
        {
            temp = next;
            next = next->next;
            delete temp;
            current->next = next;
        }
        else
        {
            current = next;
            next = next->next;
        }
    }
    return head;



//another similar approach

//Time Complexity: O(N)
//Space Complexity: O(1)

//in this, we move current only when current->data != next->data
//if they are equal then, we just move next forward and remove the duplicate using temp
//current->next = next is also updated only when current->data != next->data

//after loop current->next = NULL in case the last element is repeated. because in this 
//case, next will become NULL but current->next will no become NULL so it has to be made
//NULL separately.


        Node* current = head;
    Node* next = NULL;
    Node* temp = NULL;
    next = current->next;
    while(next)
    {
        
        if(current->data == next->data)
        {
            temp = next;
            next = next->next;
            delete temp;
            //current->next = next;
        }
        else
        {
            current->next = next;
            current = next;
            next = next->next;
        }
    }
    current->next = NULL;  //important
    return head;
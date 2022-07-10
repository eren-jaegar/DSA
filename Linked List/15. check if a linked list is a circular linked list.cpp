//Approach - 1;
//start traversing from head. if you you reach NULL then list is not circular else if you
//reach head(p->next == head will be the condition for this), list is circular.

//Time Complexity: O(N)
//Space Complexity: O(1)

    if(head == NULL)
        return true;
    Node* p = head;
    while(p && p->next!=head)
        p = p->next;
    if(p)
        return true;
    return false;
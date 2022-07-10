//we follow the process of merge sort. we iterate through both the linked lists and put
//common elements in a new linked list.

//Time Complexity: O(N+M)
//Space Complexity: O(min(N,M))

    Node* temp = NULL;
    Node* prev = NULL;
    Node* head = NULL;
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if(head2->data < head1->data)
        {
            head2 = head2->next;
        }
        else
        {
            temp = new Node(head1->data);
            if(head == NULL)
            {
                head = temp;
                prev = temp;
            }
            else
            {
                prev->next = temp;
                prev = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    return head;



//we can also use recursion

//Time Complexity: O(N+M)
//Space Complexity: O(N+M) due to recursion calls. There can be maximum of N+M-1 recursion calls

Node* intersection(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    
    if(head1->data < head2->data)
        return intersection(head1->next, head2);
    if(head1->data > head2->data)
        return intersection(head1, head2->next);
    Node* temp = new Node(head1->data);
    temp->next = intersection(head1->next, head2->next);
    return temp;
}


Node* findIntersection(Node* head1, Node* head2)
{
    return intersection(head1,head2);
}



//we can use hash map also. we create a frequency map for all the elements of smaller list(say list1)
//then we iterate through list2. if the current element of list2 is present in frequency map,
//then we put it in a new list else we skip it.

//This works for unsorted lists as well.

//Time Complexity: O(N+M)
//Space Complexity: O(min(N,M))
//Approach - 1
//find the size of the given linked list.
//calculate required size of first linked list and move a pointer till its last element.
//take another pointer to the next node to the last node of list1.
//make next of last node of list1 point to head and make the last element of the original
//list to point at the next element to the last element of list1.

//Time Complexity: O(N)
//Space Complexity: O(1)

    Node* end = head;
    int count = 1;
    while(end->next != head)
    {
        end = end->next;
        count++;
    }
    Node* temp1 = head;
    Node* temp2 = NULL;
    int to_move;
    if(count%2 == 1)
        to_move = (count/2);
    else
        to_move = count/2 - 1;
    while(to_move--)
        temp1 = temp1->next;
    temp2 = temp1->next;
    temp1->next = head;
    end->next = temp2;
    *head1_ref = head;
    *head2_ref = temp2;

//same solution with one less Node* pointer used

        Node* end = head;
    int count = 1;
    while(end->next != head)
    {
        end = end->next;
        count++;
    }
    Node* temp1 = head;
    int to_move;
    if(count%2 == 1)
        to_move = (count/2);
    else
        to_move = count/2 - 1;
    while(to_move--)
        temp1 = temp1->next;
        
    end->next = temp1->next;
    temp1->next = head;
    *head1_ref = head;
    *head2_ref = end->next;



//Approach - 2
//slow and fast pointers can also be used to find the point where the list is to be broken
//as it is the mid-point.

//Time Complexity: O(N)
//Space Complexity: O(1)



//IMPORTANT

//as per the question, if there are odd number of nodes then, first list should have the
//extra node.
//so in case the original list has only 1 node, the first list should have 1 node and
//the second list should be NULL.
//but the codes above give that one node to both the lists which is wrong. the online judge 
//of question also does the same thing which is again wrong.

//so, this code takes care of this case when number of nodes in original list is 1.

    Node* end = head;
    int count = 1;
    while(end->next != head)
    {
        end = end->next;
        count++;
    }

    if(count == 1)  //this if condition takes care of the said case.
    {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }

    Node* temp1 = head;
    int to_move;
    if(count%2 == 1)
        to_move = (count/2);
    else
        to_move = count/2 - 1;
    while(to_move--)
        temp1 = temp1->next;
        
    end->next = temp1->next;
    temp1->next = head;
    *head1_ref = head;
    *head2_ref = end->next;

//Time Complexity: O(N)
//Space Complexity: O(1)
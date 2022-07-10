//Approach - 1
//brute force method is to run two loops. outer loop for list1 and inner loop for list2.
//check for every node of list1 if it is present in list2. the first node to be present in 
//both the lists is the answer.

//Time Complexity: O(N*M)
//Space Complexity: O(1)



//Approach - 2
//we can use hash map to store all the addresses of nodes in list1 and then iterate through
//list2 while comparing the addresses stored in hash map. the first address to match is the
//answer.

//Time Complexity: O(N+M)
//Space Complexity: O(min(N,M))



//Approach - 3
//we can use recursion. we first find the sizes of the lists. after that we take the 
//difference of their sizes. then move ahead in the larger list by the difference.
//now, both the list have same size.
//we call a recursive function(tail recursion)
//if we reach NULL in the lists then return -1.
//then while returning, we check if the addresses in both the lists is same or not.
//if it is same then assign their data value in a temporary variable(here t).
//return t.

//Time Complexity: O(N+M)
//Space Complexity: O(min(N,M))

int intersection(Node* head1, Node* head2)
{
    if(head1 == NULL && head2 == NULL)
        return -1;
    int t = intersection(head1->next, head2->next);
    if(head1 == head2)
        t = head1->data;
    return t;
}

int size(Node* head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    int s1 = size(head1);
    int s2 = size(head2);
    int diff;
    if(s1>s2)
        diff = s1-s2;
    else
        diff = s2-s1;
    while(diff--)
    {
        if(s1 > s2)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    return intersection(head1, head2);
}



//Approach - 4
//we find the difference between the sizes of the linked lists. we traverse by difference
//in the larger linked list so that the sizes of both the linked lists are same.
//now, we move in both the lists until head1 != head2.
//if they are equal at NULL then return -1 else return their data value.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

//minimum traversal of lists is required in this approach.
//same amount of traversal in approach using equations.

int size(Node* head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    int s1 = size(head1);
    int s2 = size(head2);
    int diff;
    if(s1>s2)
        diff = s1-s2;
    else
        diff = s2-s1;
    while(diff--)
    {
        if(s1 > s2)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    while(head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    if(!head1)
        return -1;
    return head1->data;
}



//Approach - 5
//reach the end of list1 and make it circular by making next of last node point at
//its first node.
//Now, this will act like a loop for list2
//use floyd's loop finding algorithm to find the starting point of loop as that will be the 
//point of intersection of both the lists.
//break the loop of first list by making next of last node as NULL.

//Time Complexity: O(N+M)
//Space Complexity: O(1)



//Approach - 6
//take two pointers and make them point at head1 and head2 respectively.
//Now, move them forward by 1. after reaching end of list1, point pointer1 at head2 and
//continue moving it. After reaching end of list2, point pointer2 at head1 and continue
//moving it.
//Now, they will meet at intersection point.

//Proof - let length of list1 before intersection point be x
//let length of list2 before intersection point be y.
//let length og common part be z
//pointer1 will cover x+z+y distance ans pointer2 will cover y+z+x distance.
//hence, they cover same distance and then meet at intersection point.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(!ptr1 && !ptr2)
            break;
        if(!ptr1)
            ptr1 = head2;
        if(!ptr2)
            ptr2 = head1;
    }
    if(!ptr1)
        return -1;
    return ptr1->data;



//Approach - 7
//using equations
//1) Let X be the length of the first linked list until intersection point.
//   Let Y be the length of the second linked list until the intersection point.
//   Let Z be the length of the linked list from the intersection point to End of
//   the linked list including the intersection node.
//   We Have
//           X + Z = C1;
//          Y + Z = C2;
//2) Reverse first linked list.
//3) Traverse Second linked list. Let C3 be the length of second list - 1. 
//     Now we have
//        X + Y = C3
//     We have 3 linear equations. By solving them, we get
//       X = (C1 + C3 – C2)/2;
//       Y = (C2 + C3 – C1)/2;
//       Z = (C1 + C2 – C3)/2;
//      WE GOT THE INTERSECTION POINT.
//4)  Reverse first linked list.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

//it doesn't require any pointers, though it requires modifying a list(reverses list1, though fixes it at last)
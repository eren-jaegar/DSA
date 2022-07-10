//we just floyd's loop detection algorithm.
//take two pointers slow and fast, both initialized to head.
//move slow by one node and move fast by two nodes. if both the pointers ever meet then the 
//loop exists. if fast becomes NULL then the loop doesn't exist.

//It works because when the slow pointer enters the loop, the fast pointer is already in 
//the loop. Let the distance between then be k. in every move, the distance between them 
//increases by 1 until becomes equal to m(length of the loop), this is when both the 
//pointers meet and hence loop exists.
//if loop doesn't exist then the fast pointer reaches the end of the list first and becomes
//NULL, hence showing that the list is linear and there is no loop.

//Time Complexity: O(N)
//Space Complexity: O(1)

        Node* slow = head;
        Node* fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast = fast->next;
    }
    while(slow != fast && fast != NULL);
    if(fast)
        return true;
    else
        return false;




//another approach that we can adopt is to use hashing. we can create an unordered map or
//unordered set of Node* type and store the addresses of the visited nodes. if the address
//of the current node already exists in the map/set then, loop exists else if we reach NULL
//then, loop doesn't exists.

//Time Complexity: O(N)
//Space Complexity: O(N)

unordered_map <Node*, int> address;
        while(head)
        {
            if(address[head] == 0)
                address[head]++;
            else
                return true;
            head = head->next;
        }
        return false;




//another approach that we can do is to use two pointers first and last.
//first always points at the head and last keeps moving forward. everytime last moves, check
//the distance between first and last. if it increases keep moving last forward. if it remains
//same or decreases then a loop exists. if last reaches NULL, then loop doesn't exist.
//the distance will remain same if there is only one node in the loop.

//Time Complexity: O(N^2)
//Space Complexity: O(1)
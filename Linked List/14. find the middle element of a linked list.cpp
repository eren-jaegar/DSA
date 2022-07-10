//Approach - 1
//we can store all the addresses in an array/vector and then return the middle address.

//Time Complexity: O(N)
//Space Complexity: O(N)



//Approach - 2
//initialize two pointers fast and slow to head.
//move fast pointer by 2 nodes and move slow pointer by 1 node.
//keep moving till fast pointer hits NULL.
//return slow pointer.

//Time Complexity: O(N)
//Space Complexity: O(1)

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(ptr2)
        {
            ptr2 = ptr2->next;
            if(ptr2)
                ptr2 = ptr2->next;
            else
                break;
            ptr1 = ptr1->next;
        }
        return ptr1;



//Approach - 3
//we can also do this by finding the size and moving the pointer floor(size/2) nodes ahead 
//of head pointer.

//Time Complexity: O(N)
//Space Complexity: O(1)
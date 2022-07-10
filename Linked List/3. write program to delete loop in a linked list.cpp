//use floyd's loop finding algorithm to find if there is loop or not
//if there is loop, then make slow = head.
//now move slow and fast by one node and check if slow->next == fast->next
//when condition is true, change fast->next to NULL.
//in case slow and fast meet at head only while detecting loop, then slow->next will be
//equal to fast->next hence, our algorithm will fail. So, in this case we move fast till 
//fast->next != slow and then make fast->next = NULL;

//proof of why this works when we move both pointers by one node:
//method-3 in https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

//Time Complexity: O(N)
//Space Complexity: O(1)

        Node* fast = head;
        Node* slow = head;
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        while(slow != fast && fast);
        if(!fast)
            return;
        slow = head;
        if(slow == fast)
        {
            while(fast->next != slow)
                fast = fast->next;
            fast->next = NULL;
            return;
        }
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;



//another way is to count the number of nodes(k) in loop, then make slow and fast equal to
//head then move fast forward by k times. After this if slow == fast then move fast ahead
//by k-1 times and make fast->next == NULL.
//else if fast != slow then move both fast and slow by 1 till fast->next != slow->next
//then make fast->next = NULL.

//Time Complexity: O(N)
//Space Complexity: O(1)


       Node* fast = head;
        Node* slow = head;
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        while(slow != fast && fast);
        if(!fast)
            return;
        int k = 1;
        while(fast->next != slow)
        {
            k++;
            fast = fast->next;
        }
        slow = head;
        fast = head;
        for(int i=0; i<k; i++)
            fast = fast->next;
        if(fast == slow)
        {
            for(int i=1; i<k; i++)
                fast = fast->next;
            fast->next = NULL;
            return;
        }
        while(fast->next != slow->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;


//we can also use hash map to store the addresses and once we have found the address that
//repeats first, then we can just move forward from that address till node->next is not 
//equal to that address. then change node->next to NULL.

//Time Complexity: O(N)
//Space Complexity: O(N)

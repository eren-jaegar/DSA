//we just run a loop with condition head != NULL, this ensures that loop runs till end of
//the linked list. now, within this loop, we run another loop in sets of k && head. head
//condition is for last when set of k might not be formed from remaining elements.
//we also have to link the last element of every set(after reversing) with the first element
//of next set(after reversing).
//for this we use last and last1 for storing addresses of the first elements. we store
//addresses in last and last1 alternatively and hence we use count so that we can use 
//it in condition to use last and last1 alternatively.
//we have to use both last and last1 because for storing the address of the last element
//(after reversing) which is the first element(before reversing). because what happens is 
//before we can link the last element after reversing with the first element of next set
//after reversing, we encounter last element(after reversing or first before reversing)
//of next set and it would update node* last. hence we have to use last1 as well.

//Time Complexity: O(N)
//Space Complexity: O(1)


        node* prev = NULL;
        node* temp = NULL;
        bool condition = true;
        node* head1 = NULL;
        node* last = NULL;
        node* last1 = NULL;
        int a = k;
        int count = 0;
        while(head)
        {
            count++;
            a = k;
            prev = NULL;
            temp = NULL;
            
            while(a-- && head)
            {
                if(count%2 == 1 && a == k-1)
                {
                    last = head;
                }
                if(count%2 == 0 && a == k-1)
                {
                    last1 = head;
                }
                temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            
            if(condition)
            {
                condition = false;
                head1 = prev;
            }
            else
            {
                if(count%2 == 0)
                {
                    last->next = prev;
                }
                else
                    last1->next = prev;
            }
        }
        if(count%2 == 0)
            last1->next = NULL;
        else
            last->next = NULL;
        
        return head1;



//Iterative Approach

//Time Complexity: O(N)
//Space Complexity: O(N/K); n/k or n/k+1 calls are made.

node* reversal(node* head, int k)
        {
            if(!head)
                return NULL;
            
            node* current = head;
            node* next = NULL;
            node* prev = NULL;
            int count = 0;
            while(count<k && current)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            
            if(current)
            {
                head->next = reversal(next,k);
            }
            return prev;
        }
        
    struct node *reverse (struct node *head, int k)
    { 
        return reversal(head,k);
    }
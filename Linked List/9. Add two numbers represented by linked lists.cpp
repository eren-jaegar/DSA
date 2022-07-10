//reverse the given linked lists and then start adding the numbers till one of the linked
//list ends. then take the sum of numbers of other linked list with carry and put them in your
//new linkedlist. keep doing this until you reach the end of the second linkedlist as well
//reverse the answer linked list to get the answer.

//Time Complexity: O(N+M)
//Space Complexity: O(N+M)

Node* reverse(Node* head)
    {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int carry = 0;
        bool condition = true;
        first = reverse(first);
        second = reverse(second);
        Node* head = NULL;
        Node* temp = NULL;
        Node* prev = NULL;
        while(first && second)
        {
            temp = new Node((carry + first->data + second->data)%10);
            carry = (carry + first->data + second->data)/10;
            first = first->next;
            second = second->next;
            
            if(condition)
            {
                condition = false;
                head = temp;
                prev = temp;
            }
            else
            {
                prev->next = temp;
                prev = temp;
            }
        }
        if(first)
        {
            while(first)
            {
                temp = new Node((carry + first->data)%10);
                carry = (carry + first->data)/10;
                first = first->next;
                prev->next = temp;
                prev = temp;
            }
        }
        if(second)
        {
            while(second)
            {
                temp = new Node((carry + second->data)%10);
                carry = (carry + second->data)/10;
                second = second->next;
                prev->next = temp;
                prev = temp;
            }
        }
        if(carry)
        {
            temp = new Node(carry);
            prev->next = temp;
        }
        head = reverse(head);
        return head;



//another way to solve it and not use extra memory is to find the bigger linked list and 
//keep updating the sum in this linked list. so we dont have to use any extra memory.
//only in case last carry is not 0, one extra node will be needed.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

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
    
    Node* reverse(Node* head)
    {
        Node* current = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        bool condition = false;
        int s1 = size(first);
        int s2 = size(second);
        Node* head1 = NULL;
        Node* head2 = NULL;
        first = reverse(first);
        second = reverse(second);
        
        if(s1>s2)
        {
            head1 = first;
            head2 = second;
            condition = true;
        }
        else
        {
            head1 = second;
            head2 = first;
        }
        Node* prev = NULL;
        int carry = 0;
        int a;
        while(head2)
        {
            a = ((head1->data + head2->data + carry)%10);
            carry = ((head1->data + head2->data + carry)/10);
            head1->data = a;
            prev = head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1)
        {
            a = ((head1->data + carry)%10);
            carry = ((head1->data + carry)/10);
            head1->data = a;
            prev = head1;
            head1 = head1->next;
        }
        if(carry)
        {
            prev->next = new Node(carry);
        }
        if(condition)
        {
            first = reverse(first);
            return first;
        }
        second = reverse(second);
        return second;
    }



//if we do not want to make changes to any of the list then, we have to use recursion

//first we check the sizes of the two lists. then we find the difference in their sizes
//then we move forward in the larger list by the amount of their difference.
//now that we have moved forward, we call a recursive function to add the two lists
//for the larger list we start this addition after moving forward so the the size of both
//the lists is same from that point forward.
//after addition of two lists, we have to add carry with the remaining numbers in the
//larger list. so, we call a function addremaining to do this
//at last we check if carry is 0 or not. if not then we add a new node to accomodate the 
//carry.

//Time Complexity: O(N+M)
//Space Complexity: O(N+M) for storing resultant sum
//                  O(max(max(N,M)-min(N,M), min(N,M) )) for recursive calls

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
    
    Node* add(Node* head1, Node* head2)  //adds the two lists after making them equal in size
    {
        Node* ans = NULL;
        int carry = 0;
        if(head1->next == NULL)
        {
            ans = new Node(head1->data + head2->data); //storing complete number as answer
            return ans; //for ex if sum is 18 then we store 18 instead of 8. it becomes 
        } //8 in next step(after returning to previous call) and carry becomes 1
        ans = new Node(0);
        ans->next = add(head1->next, head2->next);
        carry = ans->next->data/10; //getting carry from returned node
        ans->next->data = ans->next->data%10; //making 8 of 18 in returned node
        ans->data = carry + head1->data + head2->data;
        return ans;
    }
    
    Node* addremaining(Node* head, Node* end, Node* ans) //adds remaining elements of larger
    {                                                    //list with carry
        Node* temp = NULL;
        int carry = 0;
        if(head == end)
        {
            return ans;
        }
        temp = new Node(0);
        temp->next = addremaining(head->next, end, ans);
        carry = temp->next->data/10;
        temp->next->data = temp->next->data%10;
        temp->data = carry + head->data;
        ans = temp;
        return ans;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        bool condition = false;
        int s1 = size(first);
        int s2 = size(second);
        Node* head1 = NULL;
        Node* head2 = NULL;
        int diff;
        if(s1>s2)
        {
            head1 = first;
            head2 = second;
            diff = s1-s2;
            condition = true;
        }
        else
        {
            head1 = second;
            head2 = first;
            diff = s2-s1;
        }
        int count = 0;
        while(count < diff)
        {
            head1 = head1->next;
            count++;
        }
        Node* ans = add(head1,head2);
        if(condition)
            ans = addremaining(first,head1,ans);
        else
            ans = addremaining(second,head1,ans);
        int carry = ans->data/10;
        ans->data = ans->data%10;
        if(carry) //if some carry is left then we add a new node.
        {
            Node* temp = new Node(carry);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
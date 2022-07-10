//Approach - 1
//find the mid point of the given list. in case of even number of elements take the second 
//middle element. now, from this node, reverse the linked list.
//Now, traverse in the first half and in the reversed second half of the linked list 
//while comparing their value and see if the original list was palindrome or not. If all
//the values match then its a palindrome else it is not.

//Time Complexity: O(N)
//Space Complexity: O(1)

        int size = 0;
        Node* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        int count = size/2;
        Node* head2 = head;
        while(count--)
        {
            head2 = head2->next;
        }
        temp = head2;
        Node* prev = NULL;
        Node* next = NULL;
        while(temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head2 = prev;
        while(head2)
        {
            if(head->data == head2->data)
            {
                head = head->next;
                head2 = head2->next;
            }
            else
                return false;
        }
        return true;



//Approach - 2
//we use recursion. In this approach, we use two pointers and call recursion while moving
//the right pointer forward.
//as for the left pointer, we use pointer to a pointer to a Node i.e, a Node** pointer.
//this allows us to move the left pointer forward while returning in recursion.
//Here passing Node* pointer for left is as good as passing by value because we need to 
//change the value of the pointer and not the value of the element pointed by the pointer.
//to accomplish this, we need to pass the address of the left pointer and hence, we use
//Node** pointer for left pointer.

//Time Complexity: O(N)
//Space Complexity: O(N) because of recursion stack

    bool palindrome(Node** left, Node* right)
    {
        if(right == NULL)
            return true;
        
        bool condition = palindrome(left, right->next);
        if(!condition)
            return condition;
            
        bool condition2 = (*left)->data == right->data? true : false;
        
        *left = (*left)->next;
        return condition2;
                
    }
    
    bool isPalindrome(Node *head)
    {
        return palindrome(&head, head);
    }
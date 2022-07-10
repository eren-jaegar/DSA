//link to question: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/


//simple three pointer approach
//Time Complexity: O(N)
//Space Complexity: O(1)


Node* prev = NULL;
        Node* temp = NULL;
        while(head != NULL)
        {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head = prev;
        return head;



//Iterative Approach
//simple approach
//Time Complexity: O(N)
//Space Complexity: O(N) (because of iterative calls)


    Node* reverse(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    struct Node* reverseList(struct Node *head)
    {
        head = reverse(head);
        return head;
    }
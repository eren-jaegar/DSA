//Approach - 1
//we create two separate linked lists foe even and odd nodes and join them together in
//the end.
//even points to the last element in even node list, odd points to the first element in the
//odd node list and end points to the last element in the odd node list.
//head points to the first element in even node list.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution{
public:
    Node* divide(int N, Node *head){
        
        Node* current = head;
        Node* even = NULL;
        Node* odd = NULL;
        Node* end = NULL;
        while(current)
        {
            if(current->data%2 == 0)
            {
                if(even == NULL)
                {
                    even = current;
                    head = current;
                }
                else
                {
                    even->next = current;
                    even = current;
                }
                current = current->next;
            }
            else
            {
                if(odd == NULL)
                {
                    odd = current;
                    end = current;
                }
                else
                {
                    end->next = current;
                    end = current;
                }
                current = current->next;
            }
        }
        if(even)
            even->next = odd;
        else
            head = odd;
        if(end)
            end->next = NULL;
        return head;
        
    }
};



//Approach - 2
//another approach is to push all the odd nodes in the end.
//first we take a pointer named end and make it point to the last node of the list.
//we take another pointer new_end and make it equal to end.
//now take two pointers current and prev. make current = head and make prev as NULL.
//Now start iterating with current.
//if we encounter an odd node then we push it to last by making new_end->next = current
//and then new_end = new_end->next;
//if we encounter an even node then in case its the first even node(check if prev == NULL)
//then make prev = current and head = prev.
//else if it is not the first even node then we connect it to the previous even node(pointed
//by prev) by making prev->next = current and prev = current.

//we keep doing these steps until we have covered all the elements of the original list and
//this can be checked by the condition current != end->next. since, end points to the last
//element of the original list so when current becomes equal to the next element pointed by
//end(it will be an odd node if we have encountered it before the last element or else it
//will be NULL), then we can stop as we have now covered all the elements of the original
//list.

//after the loop is over:
//now, if prev is not NULL i.e., we have encountered an even element then, make
//prev->next = current. This will have no effect if the last node(pointed by end) was even
//but in case that last node was odd then it will have been moved to end of the
//new list and now we will need a link first odd node to the last even node.
//so, basically it just connects the last even node to the first even node but in case 
//the node pointed by end is even the last even node is already connectec to the first
//odd node.

//make new_end->next = NULL, as new_end points to the last node of the new list.

//if prev == NULL i.e., there were no even elements then make head = current so that head
//points to the first odd element.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution{
public:
    Node* divide(int N, Node *head){
        
        Node* current = head;
        Node* prev = NULL;
        Node* end = head;
        Node* new_end = NULL;
        while(end->next)
            end = end->next;
        new_end = end;
        while(current != end->next)
        {
            if(current->data%2 == 0)
            {
                if(prev == NULL)
                {
                    prev = current;
                    head = prev;
                }
                else
                {
                    prev->next = current;
                    prev = current;
                }
                current = current->next;
            }
            else
            {
                new_end->next = current;
                new_end = new_end->next;
                current = current->next;
            }
        }
        if(prev)
            prev->next = current;
        new_end->next = NULL;
        if(prev == NULL)
            head = current;
            
        return head;
        
    }
};

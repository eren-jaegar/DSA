//Approach - 1
//we chnage the data of the nodes.
//we first iterate through the entire list and count the number of 0s, 1s and 2s.
//then we put 0 in the first x nodes, where x is the number of 0s that we have counted in
//the first step.
//then we put 1s in the following y nodes, where y is the number of 1s that we have counted
//in the first step.
//then we put 2s in the following z nodes, where z is the number of 2s that we have counted
//in the first step.

//Time Complexity: O(N)
//Space complexity: O(1)

//This will not work when these have some values associated with them. For example if these
//represent three different colors and we have different types of objects associated with 
//these colors and we have to sort the objects based on their color.
//Using this process, we would just be sorting the color and not the objecs.

class Solution
{
    public:
    Node* segregate(Node *head) {
        
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        Node* current = head;
        while(current)
        {
            if(current->data == 0)
                count0++;
            else if(current->data == 1)
                count1++;
            else
                count2++;
            current = current->next;
        }
        current = head;
        while(count0--)
        {
            current->data = 0;
            current = current->next;
        }
        while(count1--)
        {
            current->data = 1;
            current = current->next;
        }
        while(count2--)
        {
            current->data = 2;
            current = current->next;
        }
        return head;
        
    }
};



//Approach - 2
//initialize a pointer current = head;
//declare a pointer next.
//iterate the entire list using current while keeping track of the next node using 
//next pointer.
//maintain three pointers zero_first, one_first, and two_first.
//we make three independent lists for 0,1 and 2. these three pointers keep track of the
//first element of their respective lists.
//while iterating through the entire list, when we encounter an element, let's say 1,
//we add this node before the respective list(here the list pointed by one_first).
//keep doing this until you hit the end of the list.

//if zero_first is not null then, assign it to head. if it is null then check for one_first
//if it is not null then assign it to head else assign two_first to head.

//iterate till last of list of 0s and then connect the last node to the first node of list
//of 1s by doing node->next = one_first. if one_first is null, i.e., list of 1s is empty
//then connect the last node of list of 0s to the first node of list of 2s.
//do all this only if list of 0s is not empty(i.e. zero_first is not null) else there would
//be nothing to connect from ;)

//if list of 1s is not empty(i.e. one_first is not null) then connect it to list of 2s by 
//going to the last element of list of 1s and making node->next = two_first.

//Time Complexity: O(N)
//Space Complexity: O(1)

//in this method two iterations are required, one for making three individual lists and
//then one for connecting them. it can be done in one iteration also but then we will have 
//to maintain 3 more pointers for last node of all three lists.


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* current = head;
        Node* next = current->next;
        Node* zero_first = NULL;
        Node* one_first = NULL;
        Node* two_first = NULL;
        while(current)
        {
            next = current->next;
            if(current->data == 0) //the entire code in this if bracket does the same work
            { //as the code in the following else if and else brackets. 
                if(zero_first == NULL)
                {
                    zero_first = current;
                    zero_first->next = NULL;
                }
                else
                {
                    current->next = zero_first;
                    zero_first = current;
                }
            }
            else if(current->data == 1) //the code in these brackets works the same as the
            { //above code in the if brackets.
                current->next = one_first;
                one_first = current;
            }
            else //the code in these brackets works the same as the above code in the if 
            { //brackets.
                current->next = two_first;
                two_first = current;
            }
            current = next;
        }
        
        if(zero_first)
            head = zero_first;
        else if(one_first)
            head = one_first;
        else
            head = two_first;
        
        if(zero_first)
        {
            while(zero_first->next)
                zero_first = zero_first->next;
            zero_first->next = one_first;
            if(!one_first)
                zero_first->next = two_first;
        }
         
        if(one_first)
        {
            while(one_first->next)
                one_first = one_first->next;
            one_first->next = two_first;
        }
        
        return head;
    }
};
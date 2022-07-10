//Approach - 1
//Brute force approach
//Run two nested for loops.
//for every element of the linked list, iterate the elements on its right. if a larger
//element is found, then we delete the current node pointed by the outer for loop.

//Time Complexity: O(N^2)
//Space Complexity: O(1)



//Approach - 2
//reverse the list.
//now we iterate through the list while maintaining the largest element till found.
//if the data of the current node is smaller than the largest element found upto that node,
//then we delete the current node else the data of current node is greater than or equal to
//the largest element found till now so, we update the largest element by making
//largest_element = current->data. And then we move the current node forward.
//finally, after iterating through the list, reverse it to gain original order of the 
//remaining elements.

//after reversing the list, the task becomes simpler, as now we have to delete the nodes 
//that have a larger number on their left and this can easily be done by maintaining the
//largest number found till the current node.

//Time Complexity: O(N)
//Space Complexity: O(1)


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

class Solution
{
    public:
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node* current = head;
        Node* prev = NULL;
        int maxnum = current->data;
        while(current)
        {
            if(current->data < maxnum)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                maxnum = current->data; //same as maxnum = max(maxnum,current->data);
                prev = current;
                current = current->next;
            }
        }
        head = reverse(head);
        return head;
    }
    
};



//Approach - 3
//we can also use recursion.
//we call a recursive function. it takes us to the end of the list and then starts returning.
//while returning, we check if data of the returned node is greater than the data of the
//current node(for which the current recursive call was made), if it is, then we delete
//the current node as the returned node is a node on its right; and return the nextnode(the
//node that had been returned is returned again).
//else we connect the current node to the returned node using current_node->next = returned_node
//and we return the current node now.

//Time Complexity: O(N)
//Space Complexity: O(N) space used by recursive stack

class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        Node* nextnode = compute(head->next);
        
        if(nextnode->data > head->data)
        {
            delete head;
            return nextnode;
        }
        head->next = nextnode;
        return head;
    }
    
};
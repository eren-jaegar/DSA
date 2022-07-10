//reverse the linked list

//if the data of the first node is <9 then add 1 to it and thats it
//if it is 9, then make it 0 and move on to the next node and check its data whether its <9 or not

//keep repeating these steps until you encounter a data <9. in case you do not encounter 
//a data <9 and reach the end of the list then, add a new node with data as 1 and link it
//to the previously last node.

//reverse the linked list again.

//Time Complexity: O(N)
//Space Complexity: O(1)

//we reverse the linked list because in case the number a lot of 9s in the end, then to add
//1 to them we will have to iterate from beginning till that element again and again.
//consider 845699999999999999999 for example. in this case we will have to start again and
//again from the start to reach every 9 and then change it until we encounter an element <9
//this will give a bad time complexity, worst case O(N^2) for 9999999... such numbers.

//so instead we prefer to reverse the linked list and then add 1.
//this method requires only 3 traversals. 1 for reversing, 1 for adding 1 and another for
//reversing again.

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
        head = prev;
        current = head;
        next = NULL;
        
        while(current)
        {
            if(current->data < 9)
            {
                current->data++;
                break;
            }
            else
            {
                current->data = 0;
                if(current->next == NULL)
                    prev = current;
                current = current->next;
            }
        }
        if(!current)
        {
            prev->next = new Node(1);
        }
        current = head;
        prev = NULL;
        next = NULL;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;


//another approach is to save the position of last element which is <9 in temp.
//then if the last element of list is 9 then add 1 to temp->data and then make all elements
//after temp 0 as they will all be 9.
//if temp = NULL then it means all the elements in the list are 9 so just add 1 new node and
//then make all other elements 0.

//seems like a better approach than the previous one.

//Time Complexity: O(N)
//Space Complexity: O(1)

        Node* temp = NULL;
        Node* current = head;
        while(current->next != NULL)
        {
            if(current->data<9)
                temp = current;
            current = current->next;
        }
        if(current->data == 9)
        {
            if(temp == NULL)
            {
                temp = new Node(0);
                temp->next = head;
                head = temp;
            }
            temp->data++;   //adding 1 to temp->data
            temp = temp->next;
            while(temp != NULL)
            {
                temp->data = 0;
                temp = temp->next;
            }
        }
        else
            current->data++;
        return head; 
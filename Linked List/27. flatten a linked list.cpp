//Approach - 1
//first, we consider the first two nodes. declare two pointers below and fwd.
//below iterates in the sub linked list of the first node whereas fwd iterates in the
//sub linked list of the second node.
//initialize below with first node and fwd with second node.
//initialize another pointer tail as NULL.
//now, we compare the data of the two nodes and make the tail and root point to the node with 
//smaller number, and we also move forward in that sublist using the bottom pointer.

//STEPS:
//Now, we again compare the data of the two nodes pointed by the below and fwd pointer.
//now we connect the node with the smaller data to the node pointed by tail pointer, using 
//the bottom pointer. and now, we make the tail pointer point at this new node.
//we move forward in the sublist with the node whose data is smaller.
//keep repeating these steps until you reach the end of one of the sublist.

//Now, we have merged the first two sublists into one. Now, we again run the same process
//but with the merged list and the next list(third list after merging first two lists,
//or fourth list after merging first three lists and so on). keep doing this until we reach
//the end of the main linked list.

//Time Complexity: O(N*N*M)
//Time Complexity Analysis: let there be M1, M2, M3...elements in the first, second, third...
//sublists. let there be N elements in the main list.
//the first sublist is iterated (N-1) times, the second sublist is iterated (N-2) times and
//so on.
//total time complexity: (N-1)*M1 + (N-2)*M2 + (N-3)*M3...
//This rounds up to or for large values of M and N is equal to N*N*M.

//Space Complexity: O(1)

    Node* current = root->next;
    Node* below = NULL;
    Node* fwd = NULL;
    Node* tail = NULL;
    Node* temp = NULL;
    while(current)
    {
        tail = NULL;
        below = root;
        fwd = current;
        while(fwd && below)
        {
            if(below->data <= fwd->data)
            {
                tail = below;
                below = below->bottom;
            }
            else  //we join the node from sublist-2 between the node pointed by below
            {     //and the node before it in the merged list.
                if(tail == NULL) //if the first element of second list in smaller than the
                { //first element of merged list, i.e, if we encounter a smaller element in
                  //the main list than the previous elements in the main list, as we keep 
                  //progressing in it.	
                    temp = fwd->bottom;
                    fwd->bottom = below;
                    tail = fwd;
                    root = tail;
                    fwd = temp;
                }
                else
                {
                	temp = tail->bottom;
                	tail->bottom = fwd;
                	tail = fwd;
               		fwd = fwd->bottom;
                	tail->bottom = temp;
                }
            }
        }
        if(fwd) //in case first list(merged list is over) we join the remaining second
        {       //sublist with the last element of the merged list(first list).
            tail->bottom = fwd;
        }
        current = current->next;
    }
    return root;



//Approach - 2
//we use priority queue. priority queue is implemented using an underlying data structure
//which is heap for the STL priority queue(we are using this one), though the i guess
//the underlying data structure can also be array, linked list, or binary search tree.

//we create a priority queue and a comparator function using which priority queue sorts 
//its elements.
//In heap data structure, we can insert elements in logN time(same as set) and since our
//priority queue also uses heap data structure so we can insert elements in it in logN time.

//we have made the comparator function as such that it sorts the list in increasing order.
//if the condition a->data > b->data is true then, a will be on top of b else it will be
//below it.

//we start by inserting all the elements of the main list in the priority queue.
//after this, we run a while loop with a condition !priority_queue.empty(), i.e., till the
//priority queue is not empty.
//in the loop we first, take the topmost(smallest) element in temp. Then if prev is NULL,
//we assign root to this element as it will be the smallest element in the entire list,
//including the sublists as well.
//if prev is not NULL then, we assign prev->bottom = temp, this connects the previous node
//of the sorted and flattened list to the node currently pointed by temp.
//now the common steps(irrelevant of whether prev is NULL or not):
//we assign temp to prev.
//remove the topmost(smallest) element.
//if there are more elements in sublist of that element then, add the next element using
//priority_queue.push(temp->bottom).

//This works because all the sublists are sorted. So initially we take the smallest 
//element in the main list and then remove it from priority queue and in its place add the
//next element in its sublist. Now, of all the elements currently present in the priority
//queue, the smallest element will be the second smallest element in the flattened list
//as the smallest element as already been removed and there cannot be any other element 
//smaller than this current element(this is because all the sublists are sorted, so all
//the remaining elements must be greater than or equal to the current element).

//Time Complexity: O(N*M*logN)
//Time Complexity Analysis: we initially insert N elements one by one and then we keep 
//removing and adding one element in each step. this continues till we encounter the end
//a sublist. this is when the size of the priority queue decreases. As we more and more
//sublists hit their end, the size of the priority queue decreses until there are no
//elements left in it.
//So, for the major part of the process the priority queue contains N elments, and we push
//N*M(sum of all the elements in all the sublists i.e., M1+M2+M3...) elements and since
//insertion takes logN time so, we get the time complexity as N*M*logN

//Space Complexity: O(N)  priority queue contains atmost N elements


struct comparator //we are dealing with Node which is a structure hence we have to make
{ //comparator a structure.
    bool operator()(Node* a, Node* b) //this is a fixed syntax. operator word has to be
    { //used and we cannot use any other word instead.
        return a->data > b->data;
    }
};

Node *flatten(Node *root)
{
   priority_queue <Node*, vector <Node*>, comparator > nums;
   
   Node* current = root;
   while(current)
   {
       nums.push(current);
       current = current->next;
   }
   Node* temp = NULL;
   Node* prev = NULL;
   while(!nums.empty())
   {
       temp = nums.top();
       if(prev == NULL)
       {
           root = temp;
       }
       else
       {
           prev->bottom = temp;
       }
       prev = temp;
       nums.pop();
       if(temp->bottom)
       {
            nums.push(temp->bottom);
       }
   }
   return root;
}
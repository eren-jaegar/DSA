//Approach - 1
//iterate to the node that has to be deleted(current pointer). take a pointer prev which
//points to the node previous to the required node. do prev->next = current->next and then
//delete the current node.
//if the current node is head node then iterate to the last node by using condition
//prev->next != head. then do prev->next = curren->next, delete current and head = prev->next
//if the head node is the only node in the list then, delete it and make head = NULL.

//Time Complexity: O(N)
//Space Complexity: O(1)

//Link to the question: https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1/#

void deleteNode(struct Node **head, int key)
{

    Node* current = *head;
    Node* prev = NULL;
    while(current->data != key)
    {
        prev = current;
        current = current->next;
    }
    if(prev == NULL)
    {
        prev = current;
        while(prev->next != current)
        {
            prev = prev->next;
        }
    }
    prev->next = current->next;
    if(current == *head)
        *head = current->next;
    if(prev == current)
        *head = NULL;
    delete current;

}
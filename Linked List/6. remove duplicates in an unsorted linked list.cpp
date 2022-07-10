//create an unordered map and keep track of all the elements in the linked list.
//if the element has occured before then remove its current occurence.

//Time Complexity: O(N)
//Space Complexity: O(N)

        unordered_map <int,int> nums;
        Node* current = NULL;
        Node* fwd = head;
        while(fwd)
        {
            if(nums[fwd->data] == 0)
            {
                nums[fwd->data]++;
                current = fwd;
                fwd = fwd->next;
            }
            else
            {
                current->next = fwd->next;
                delete fwd;
                fwd = current->next;
            }
        }
        return head;


//could have also used brute force by using two loops
//Time Complexity: O(N^2)
//Space Complexity: O(1)


//could have also sorted the list and then traversed it once to remove the duplicates.
//this does not maintain the original order of elements.

//Time Complexity: O(NlogN)
//Space Complexity: O(1)

//learn about this method. Don't actually know how to implement it
/*
Approach - 1
we can do an inorder traversal and store the elements in a vector and then find the median
from that.

Time Complexity: O(N)
Space Complexity: O(N) */



/*
Approach - 2
we can find the size and then depending on size we can find the n/2th element or
n/2th and n/2+1th element and find the median.

Time Complexity: O(N)
Space Complexity: O(height) */



/*
Approach - 3
we can do inorder traversal using morris method and find the size.
then we again do inorder traversal using morris to find the median by finding the n/2th
or both n/2th and n/2+1th element.

Time Complexity: O(N)
Space Complexity: O(1) */


int morris(Node* root)
{
    int count = 0;
    Node* current = root;
    Node* pre = NULL;
    while(current)
    {
        if(current->left == NULL)
        {
            count++;
            current = current->right;
        }
        else
        {
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current)
                pre = pre->right;
                
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                count++;
                pre->right = NULL;
                current = current->right;
            }
        }
    }
    return count;
}

float median(Node* root, int size) //remember that prev will only be updated at places
//where we print the element for inorder traversal, as at only those places will we
//find the previous element in inorder traversal.
{
    float ans;
    int mid = ((size/2)+1);
    Node* current = root;
    Node* prev = NULL;
    Node* pre = NULL;
    while(current)
    {
        if(current->left == NULL)
        {
            mid--;
            if(mid == 0)
            {
                if(size%2 == 0)
                {
                    ans = (current->data + prev->data)/(2.0);
                }
                else
                    ans = current->data;
            }
            prev = current;
            current = current->right;
        }
        else
        {
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current)
                pre = pre->right;
                
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left; //don't update prev here.
            }
            else
            {
                mid--;
                if(mid == 0)
                {
                    if(size%2 == 0)
                    {
                        ans = (current->data + prev->data)/(2.0);
                    }
                    else
                        ans = current->data;
                }
                pre->right = NULL;
                prev = current;
                current = current->right;
            }
        }
    }
    return ans;
    
}

float findMedian(struct Node *root)
{
    int size = morris(root);
    float a = median(root, size);
    return a;
}
//LINK: https://practice.geeksforgeeks.org/problems/heap-sort/1/


/*
Approach - 1
first build a heap then delete the elements one by one.
while deleting elements, we swap it with last element so, the current element automatically
gets put down in the last and we don't have to do it manually.

Time Complexity: O(NlogN)
Space Complexity: O(1) */

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int l = 2*i+1;
        int r = l+1;
        if(l<n && arr[l] > arr[largest])
            largest = l;
        if(r<n && arr[r] > arr[largest])
            largest = r;
        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int i = n/2-1;
        for(; i>=0; i--)
            heapify(arr, n, i);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        while(n>1)
        {
            swap(arr[0], arr[n-1]);
            n--;
            heapify(arr, n, 0);
        }
    }
};
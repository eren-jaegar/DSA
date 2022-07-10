/*
Approach - 1
use the heapify approach.

Time Complexity: O(N)
Space Complexity: O(logN) since we are using recursion */


void heapify(int* arr, int n, int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && arr[l] > arr[largest])
		largest = l;
	if(r<n && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void buildheap(int arr[], int n)
{
	int i = (n/2)-1;
	for(; i>=0; i--)
	{
		heapify(arr, n, i);
	}
}
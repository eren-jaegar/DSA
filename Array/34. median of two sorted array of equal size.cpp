//to find the median of two sorted arrays we can use the following approaches:

//first approach is simple to use the sort and merge process.
//first thing we need to realise is that we have n elements in first array and n
//elements in secind array. so, in total we have 2n elements. if the arrays were
//combined ans sorted and then the elements were putback in these wo arrays then,
//the median would be the average of the last element of first array and first element
//of second array.

//the arrays are already sorted individually. so we use the process for merging two
//sorted arrays into one sorted array.
//using this we find the nth and (n+1)th (indexing from 1) element and take their
//average

//time complexity: O(N)
//space complexity: (1)


//link to article: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

int i=0;
int j=0;
int count = 0;
int m1 = -1;
int m2 = -1;
for(; count<=n; count++)
{
	if(i == n)  //if all the elements of first array are smaller than all the elements
	{           //of the second array
		m1 = arr1[n-1];
		m2 = arr2[0];
		break;
	}
	if(j == n)  //if all the elements of second array are smaller than all the elements
	{           //of the first array
		m1 = arr2[n-1];
		m1 = arr1[0];
		break;
	}
	if(arr1[i] < arr2[j])
	{
		m1 = m2;
		m2 = arr1[i];
		i++;
	}
	else
	{
		m1 = m2;
		m2 = arr2[j];
		j++;
	}
	return (m1+m2)/2;
}



//another method to do it in logN time complexity is as follows


//link to article: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

//youtube videos link:
//https://www.youtube.com/watch?v=OXIHGa949IE
//https://www.youtube.com/watch?v=MHNTl_NvOj0


//see the videos then read this

//DIVIDE AND CONQUER

//if m1 = m2, then the number of elements greater than m1(or m2) is same as the number
//of elements smaller than m1(or m2). hence m1 will be the median as it will be the
//middle element or rather sum (m1+m2)/2 will be the median i.e m1 since m1 = m2.

//if m1 is smaller than m2, then the two elements that will make up the median lie
//either in arr1 from m1 to n-1 or in arr2 from 0 to m2.
//this is because we will have a maximum of n-1 elements greater than m2 and smaller 
//than m1 each.
//this ensures that none of the elements left(that are not in the picked elements)  
//in the two arrays are median elements as none of them will be the last element of 
//arr1 or first element of arr2 after sorting of combination of both the arrays.

//similarly if m1 is greater than m2 then the median elements will lie either in 
//arr1 from 0 to m1 or in arr2 from m2 to n-1.

//after picking such a subset from both the arrays, we again have two arrays and we 
//again find their median and repeat the process.
//this continues until we are left with  elements in both the arrays.
//after this we use (max(A[0],B[0])+min(A[1],B[1]))/2 to find the median when both
//the arrays have only 2 elements left.


//IMPORTANT

//this approach works because after we have found the median elements, and then if we
//combine all the elements that we have left out until now, to form the complete 
//sorted array that is a combination of both the arrays; then firstly, none of the 
//element is added in between the median elements, i.e there is no element which is
//greater than one median element and smaller than the other median element.
//secondly, equal number of elements are added on both sides of the median elements
//i.e number of elements greater and less than the median elements is equal.
//this is because at every stage we have left equal number of elements on the right
//and on the left that have not been selected

//inequalities exisitng(because the arrays were intitially sorted) between numbers 
//can easily be used to show these two properties if work up our way from when the
//arrays contain two elements to when the arrays are of full size.

//these two properties also ensure that the median elements remain middle elements 
//even after we work up our way from size 2 to n fo arrays.


//Time complexity: O(logN)
//Space complexity: O(1)


int getmedian(int arr1[], int arr2[], int n)
{
	if(n <= 0)
		return -1; //invalid size
	if(n == 1)
		return (arr1[0]+arr2[0])/2;
	if(n == 2)
		return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;

	if(n%2 != 0)
	{
		m1 = arr1[n/2];
		m2 = arr2[n/2];
	}
	else
	{
		int m1 = (arr1[n/2-1]+arr1[n/2])/2;
		int m2 = (arr2[n/2-1]+arr2[n/2])/2;
	}


	if(m1 == m2)
		return m1;
	else if(m1 < m2)
	{
		if(n%2 == 0)
			return getmedian(arr1+n/2-1, arr2, n-n/2+1);
		else
			return getmedian(arr1+n/2, arr2, n-n/2);
	}
	else  //m1 > m2
	{
		if(n%2 == 0)
			return getmedian(arr2+n/2-1, arr1, n-n/2+1);
		else
			return getmedian(arr2+n/2, arr1, n-n/2);
	}
}
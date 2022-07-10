//we just keep printing the boundary. after we have printed a boundary we update the 
//boundaries. for ex: let a,b represent the starting & ending of boundary rows
//and c,d represent starting & ending of boundary columns.
//first we print the starting row and then update the starting row boundary as a++,
//then we print the ending column and update the ending column boundary as d--,
//then we print the ending row and update ending row boundary as b--,
//then we print the starting column and update the starting column boundary as c++.
//before going into each loop we check if the count of elements has been reached or
//not.

//time complexity: O(m*n)
//space complexity: O(m*n) for storing the elements else O(1) if we directly print them


        vector <int> ans;
        int right = c, lower = r, upper = -1, left = -1;
        int count = 0;
        int i=0, j=0;
        while(count < r*c)
        {
            j = left+1;
            while(j < right)
            {
                ans.push_back(matrix[upper+1][j]);
                count++;
                j++;
            }
            upper++;
            i = upper+1;
            if(count >= r*c)
                break;
            while(i < lower)
            {
                ans.push_back(matrix[i][right-1]);
                count++;
                i++;
            }
            right--;
            j = right-1;
            if(count >= r*c)
                break;
            while(j > left)
            {
                ans.push_back(matrix[lower-1][j]);
                count++;
                j--;
            }
            lower--;
            i = lower-1;
            if(count >= r*c)
                break;
            while(i > upper)
            {
                ans.push_back(matrix[i][left+1]);
                count++;
                i--;
            }
            left++;
        }
        return ans;



//another solution is to use recursion.
//I think it will use more space because of its repeated recursive recalls.
//though gfg says no extra space required.

//link to article: https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//method-3 in the above article        

//skipped method-4 fo DFS approach, see once

//code directly copied from gfg 



#include <iostream>
using namespace std;

#define R 4
#define C 4

// Function for printing matrix in spiral
// form i, j: Start index of matrix, row
// and column respectively m, n: End index
// of matrix row and column respectively
void print(int arr[R][C], int i, int j, int m, int n)
{
	// If i or j lies outside the current matrix
	if (i >= m or j >= n)
		return;

	// Print First Row
	for (int p = j; p < n; p++)
		cout << arr[i][p] << " ";

	// Print Last Column
	for (int p = i + 1; p < m; p++)
		cout << arr[p][n - 1] << " ";

	// Print Last Row, if Last and
	// First Row are not same
	if ((m - 1) != i)
		for (int p = n - 2; p >= j; p--)
			cout << arr[m - 1][p] << " ";

	// Print First Column, if Last and
	// First Column are not same
	if ((n - 1) != j)
		for (int p = m - 2; p > i; p--)
			cout << arr[p][j] << " ";

	print(arr, i + 1, j + 1, m - 1, n - 1);
}

// Driver Code
int main()
{

	int a[R][C] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };

	// Function Call
	print(a, 0, 0, R, C);
	return 0;
}


//question link - https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1/#

//simple solution is to move in cycles.
//first cycle consists of first column, first row, last column and last row.
//next cycle will consist of second column, second row, second-last column and
//second-last row.
//in one cycle we switch 4 elements(one from each of the rows and columns)
//there will be n/2 cycles. do this for all of them.

//Time Complexity: O(N*N)
//Space Complexity: O(1)


void rotate(vector <vector <int> >& arr, int i, int j)
{
    int a;
    for(int k=0; k<i-1; k++)
    {
        a = arr[j+k][j];
        arr[j+k][j] = arr[j][i+j-1-k];
        arr[j][i+j-1-k] = arr[i+j-1-k][i+j-1];
        arr[i+j-1-k][i+j-1] = arr[i+j-1][j+k];
        arr[i+j-1][j+k] = a;
    }
}

class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    
	    int j = 0;
	    for(int i=n; i>=2;)
	    {
	        rotate(arr, i, j);
	        i -= 2;
	        j++;
	    }
	    
	}

};


//another way to do is to reverse all the rows and then take transpose.
//the order of executing these two operations might be different for clockwise and
//anti-clockwise rotations.

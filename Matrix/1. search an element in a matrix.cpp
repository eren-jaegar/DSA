//just compare the first element of each row to find the row in which the element may
//exist. the row before the first row in which the first element is greater than
//the target may contain the target.
//take care when target < matrix[0][0] because this will give row as -1 which will give
//error.
//now iterate through all the elements in the row to check if target exists or not.

///time complexity: O(n+m)
//space complexity: O(1)

        bool ans = false;
        int i = 0, j = 0;
        if(target < matrix[i][j])
            return ans;
        while(i < matrix.size() && matrix[i][j] <= target)
            i++;
        i--;
        for(; j<matrix[i].size(); j++)
        {
            if(matrix[i][j] == target)
                ans = true;
        }
        return ans;



//another solution is to do binary search
//first we search in the first column to find the row in which our element mat lie
//then we search in that row to find the element.

//time complexity: O(logN + logM)
//space complexity: O(1)


if(target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1]) //second condition can be removed
            return false; //if target is smaller than first or greater than last element
        int low = 0;
        int high = matrix.size()-1;
        int mid = (low+high)/2;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(matrix[mid][0] > target)
                high = mid-1;
            else if(matrix[mid][0] < target)
                low = mid+1;
            else
                return true;
        }
        int i = mid; //binary search may either give me the row in which the element
        if(matrix[mid][0] > target) //will lie or it may give me the next row. so, this
            i--; //if condition checks if we have been given the next row, if so 
//reduce row no. by 1. it may give one row ahead because binary search  tries to find
//the target but in case the target does no exist(i.e. target is not the first element of any row)
//mid may either point to the element just smaller than the target or it may point 
//to the element just greater than the target. in case the element pointed is just smaller
//then its fine as the target may exist in that row. but, if the element pointed by mid
//is greater then target cannot exist in that row and we should reduce row no. by 1
//as it can only exist in the previous row. and hence, the if condition.        
        low = 0;
        high = matrix[i].size()-1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(matrix[i][mid] > target)
                high = mid-1;
            else if(matrix[i][mid] < target)
                low = mid+1;
            else
                return true;
        }
        return false;



//another approach
//can't tell the time complexity now, as it is based on binary search tree.
//start from top right corner. elements below it are always greater and elements of 
//left are smaller
//look at matrix by rotating it 45 degrees so that top right corner is at peak


//link to the solution: https://leetcode.com/problems/search-a-2d-matrix/discuss/1895837/C%2B%2B-BINARY-SEARCH-TREE-(**)-Explained-with-IMG

//code directly copied and not written by self.

        


        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
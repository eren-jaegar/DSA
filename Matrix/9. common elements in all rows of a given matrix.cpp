//make an unordered_map and store the elements of first row in it
//now iterate over all other rows.
//if the element is not repeated in that row and has appeared in all the rows before
//then increase the count of that element in the map.
//this can be ensured by checking for condition unordered_map[element] == i
//at last, the elements with frequency n are the only elements that have appeared in
//all the rows.
//we need to ignore repeated elements in a row else they will also add towards the
//frequency and hence might give wrong answer.



//if we have row-wise sorted matrix, then first we compare all the elements of the
//last column. now for all the rows except the ones whose last element is the smallest
//element in the last column, we decrease the column number by one. we keep the 
//column number same for all the rows with the smallest element.
//at the same time before decreasing we obviously check if the element of the current 
//row is same as the smallest element or not. if it is same then we increase the count
//by 1. if count reaches M then we have found the common element.
//if we reach column -1(which does not exist) then there is no common element.
//keep doing this until you find the common element or hit column -1(which does not exist)
//hence, meaning that there is no common element.

//we can also start from first element of each row but then we will have to look for
//the maximum element and move on for the rows with smaller elements.


//Link to this approach: https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
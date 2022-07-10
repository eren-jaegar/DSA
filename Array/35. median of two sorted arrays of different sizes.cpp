//article link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
//yt video link: https://www.youtube.com/watch?v=NTop3VTjmxk
//leetcode question link: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/





//we use binary search
//logic is that, if we combine both the arrays and sort them, then the median will
//divide that array in two parts, the left half and the right half.
//now, in our logic we try to make that left half.
//we know exactly how many elements will be in the left half as we know the sizes of
//both the arrays.
//what we do is that we select some elements from array1 and remaining from array2 and
//check if they make up the required left half.
//the last element of the selected subarray from array1 is left1 and the element
//next to left1 in array1 is right1. similarly we have left2 and right2 for array2
//now, we know that in the combined array all elements of left half will be less 
//than all the elements of right ha;f. or, since the array is sorted we can also say 
//that the last element of left half will be smaller than the first element of right
//half. max(left1,left2) is the last element of left half and min(right1,right2) is 
//the first element of right half.
//so we ensure max(left1,left2) < min(right1,right2) or in other words 
//left1<right2 && left2<right1 since left1 and left2 are already less than right1 
//and right2 respectively.
//we do binary search on number of elements to be selected from array1 i.e. from
//0 to array1.size().
//also in array1.size()>array2.size(), we call the function again by replacing
//array1 with array2 so that we only apply the search to array with minimum size.

//TIME COMPLEXITY: O(min(logN,logM))
//SPACE COMPLEXITY: O(1)

if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left1,left2,right1,right2;
        int l = 0;
        int r = n1;
        int cut1,cut2;
        while(l<=r)
        {
            cut1 = (l+r)/2;
            cut2 = (n1+n2)/2 - cut1;
            left1 = cut1 == 0? INT_MIN : nums1[cut1-1];
            right1 = cut1 == n1? INT_MAX : nums1[cut1];
            left2 = cut2 == 0? INT_MIN : nums2[cut2-1];
            right2 = cut2 == n2? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1)
            {
                break;
            }
            else if(left1 > right2)
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        if((n1+n2)%2 == 0)
            return ((double)max(left1,left2)+min(right1,right2))/2;
        else
            return min(right1,right2);




//we can also use the merge sort algorithm to do it
//time complexity: O(n+m)
//space complexity: O(1)



//copied code not self written



        int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
    /*loop till (m+n)/2*/
    for (count = 0; count <= (m + n)/2; count++)
    {
        //store (n+m)/2-1 in m2
        m2=m1;
        if(i != n && j != m)
        {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if(i < n)
        {
            m1 = ar1[i++];
        }
        // for case when j<m,
        else
        {
            m1 = ar2[j++];
        }
    }
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    // index is median i.e. (m+n)/2
    // other wise median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    if((m + n) % 2 == 1){
        return m1;
    }
    else{
        return (m1+m2)/2;




//simple solution
//just sort the array and check the differences of all the elements at a distance of m
//number from each other.
//time complexity: O(NlogN) because of sorting
//space complexity: O(1)

int l = 0;
        int r = n-1;
        int leftmax = arr[l];
        int rightmax = arr[r];
        long long int res = 0;
        while(l<r)
        {
            if(arr[l] <= arr[r])
            {
                if(leftmax < arr[l])
                    leftmax = arr[l];
                else
                {
                    res += (leftmax - arr[l]);
                    l++;
                }
            }
            else
            {
                if(rightmax < arr[r])
                    rightmax = arr[r];
                else
                {
                    res += (rightmax - arr[r]);
                    r--;
                }
            }
        }
        return res;
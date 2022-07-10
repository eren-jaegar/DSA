//link to the question: https://techiedelight.com/practice/?problem=MinimumMergeOperations
//link to the gfg article: https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/


//we again use two pointer method
//we place the first pointer(i) on the first element of the array and second pointer(j)
//on the last element of the array.
//if the elements are equal we increase the first pointer by 1 and decrease the second
//pointer by 1
//if nums[i] < nums[j] then we have to increase nums[i] to make it equal to nums[j]
//as we dont have any method to reduce nums[j].
//so we increase i by 1 and keep adding until sum1>=nums[j].
//if it exceeds nums[j], then we increase nums[j] by 1 and keep adding the next
//numbers.
//this works because either at some point either they become equal or all the numbers
//between them are added to give one single number and that makes the array palindrome.

//case for vector/array size 0 is dealt with separately in the starting.

//time complexity: O(N)
//space complexity: o(1)



if(nums.size() == 0)
			return 0;
		int count = 0;
		int i = 0, j = nums.size() - 1;
		int sum1, sum2;
		sum1 = nums[i];
		sum2 = nums[j];
		while (i < j)
		{
			if (sum1 == sum2)
			{
				i++;
				j--;
				sum1 = nums[i];
				sum2 = nums[j];
			}
			else if (sum1 < sum2)
			{
				i++;
				sum1 += nums[i];
				count++;
			}
			else
			{
				j--;
				sum2 += nums[j];
				count++;
			}
		}

		return count;
//Approach - 1
//Brute force approach is to form all possible pairs of triplets and see if the sum is equal
//to required sum or not.
//It requires three nested for loops.

//Time Complexity: O(N^3)
//Space Complexity: O(1)



//Approach - 2
//we create a hash map and store all the values. Then for each element we iterate through
//the dll while checking if the pair exists in hash map or not(this is similar to how we
//check for pairs of elements with a required sum). start iterating from the node next
//to the node for which you are currently iterating in the outer loop.
//everytime we iterate through the list for a element, we half the number of pairs found
//for that element, because each pair will be counted twice. for example if we are iterating
//for 4 and a pair is formed by 2 & 3, then it will be counted twice, once when we encounter 2
//and secondly when we encounter 3.

//Time Complexity: O(N^2)
//Space Complexity: O(N)



//Approach - 3
//we can use two pointer approach. iterate through the list for every element.
//while iterating for every element, create two pointers, one pointing to the element next
//to the current element for which we are iterating and other pointing to the last element
//of the list.
//to move the pointers, use the same method which is used for finding pairs of numbers with
//the required sum.

//Time Complexity: O(N^2)
//Space Complexity: O(1)
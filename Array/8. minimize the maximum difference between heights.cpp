//link to useful article - https://stackoverflow.com/questions/63000076/minimize-the-maximum-difference-between-the-heights


//we first sort the array and then run a loop from right to left.
//in the loop, we try to make the current tower as the tallest tower.
//we can try to achieve this by incresing the height of the current tower and decreasing
//the heights of all the towers to the right of it. the heights of he towers to the 
//left of the current tower can either be increased or deceased as they wont
//surpass the height of the current tower after its height has been increased.
//but still we will increase the heights of the towers to the left of the current towers
//because we want to minimize the height difference(will be cleared later on).
//now, this doesnt guarantee that the current tower will become the tallest tower
//but its the only way we can try to make it the tallest tower.
//now the tallest tower will either be the current tower or the last tower when its
//height has been decreased.
//the smallest tower will either be the first tower with its height increased or it
//will be the tower next to the current tower with its height decreased.
//take the difference between the tallest and smallest tower and repeat this process
//for all the towers.
//minimum of all such differences will be our final answer.

//the reason why we have increased the heights of all the towers the left of the 
//current tower is because 
//firstly they cant become taller than the current tower with its height increased
//secondly to maximize the smallest height. i.e. if the tower to the right of the
//current tower is selected as the smallest tower then, if we would have decreased the 
//height of the first tower then it would have become the smallest tower but that 
//would have increased the difference between the hieghts of the tallest and the
//shortest tower, which is undesirable.
//similar logic can be applied when the first tower with its increased height is
//chosen as the samllest tower.

//while iterating from right to left, if we encounter a situation when the height
//of some of the towers cant be decreased then we stop after considering the case for 
//first such tower. because for first such tower, height will not have to be decreased
//for any tower whose height is already smaller than k.
//but for second such tower, the first such tower will come on its right and hence we
//will have to decrease its height but we cant do it so we increase it.
//and hence its the same as the preious case when the current tower was the first tower
//with height less than k.
//hence we stop after considering the case of the first tower with height less than k.
//if no such tower is encountered, then we keep iterating till index 0.


//time complexity: O(NlogN)    because of sorting
//space complexity: O(1)


sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int maxh,minh;
        int j = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i] < k && j!=1) //j is used so that the loop executes for first tower
                continue; //with height <k and then skips all the towers with height <k
            if(arr[i] < k && j == 1)
                j++;
            
                
            maxh = max(arr[i] + k, arr[n-1]-k);
            minh = min(arr[0] + k, arr[i+1] - k);
            ans = min(ans,maxh-minh);
        }
        return ans; 
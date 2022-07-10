//simplest approach is to just put all the elements in a vector and sort it.
//then take the middle element

//time complexity: O((R*C)log(R*C))
//space complexity: O(R*C)

        vector <int> v;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
                v.push_back(matrix[i][j]);
        }
        
        sort(v.begin(), v.end());
        return v[r*c/2];



//another approach is to create a vector but instead of sorting it, use the method used
//in finding the kth smallest/largest element.
//time complexity: O(r*c)
//space complexity: O(r*c)





//another approach
//we first compare all the elements in first column to find the minimum element
//simultaneously, we compare all the elements in the last column to find the maximum
//element.
//now, we know that are median will lie in this range i.e., between maximum and minimum
//element. so we do binary search on this range.
//in binary search we select mid and then count the number of elements that are 
//less than or equal to mid. we count by using upper_bound.
//upper_bound returns the iterator to the first element that is just greater than mid
//we subtract that iterator from the current row's beginning iterator matrix[i].begin()
//to find the number of such elements.



//time complexity: O(32*R*logC).
//upper_bound takes the time that is equal to log of difference between last and
//first iterator. since, maximum difference can be C so we get logC.
//upper_bound is used for each row, hence we get the factor of R, and time complexity
//becomes R*logC
//now, the binary search loop will run for a maximum of 32 times. this is because int
//takes 32 bits so, max number it can store is 2^32 and after every loop our, range
//is halved, so it will take 32 loops to find the ans.
//hence, time complexity becomes 32*R*logC
//in this question, the range of number is 1 to 2000 so instead of 32, it will actually
//take log2000 to the base 2 no. of iterations.
//space complexity: O(1)




        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i=0; i<r; i++)
        {
            minn = min(minn,matrix[i][0]);
            maxx = max(maxx,matrix[i][c-1]);
        }
        int req = (r*c+1)/2; //note this. v.imp
        int mid;
        int count = 0;
        while(minn < maxx)
        {
            count = 0;
            mid = (minn+maxx)/2; //use minn + (maxx-minn)/2 to prevent overflow
            for(int i=0; i<r; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(count < req)
                minn = mid+1;
            else
                maxx = mid; //we dont do maxx = mid+1 because even if count >req 
            //the current number can be the answer because if it has duplicates 
            //then count will be greater than req.
        }
        return minn;

//the answer will be minn because in the end loop will terminate only when minn
//becomes equal to maxx. since lies in [minn,maxx] and in the end they both are equal
//so, that would mean that minn (or maxx since they are equal) is the answer.

//one thing to note is that, this gives the smallest number which satisfies
//count >= req as the answer. because if there had existed a number even smaller 
//which satisfied count >= req then in the end high would have been equal to that 
//number but this is not the case hence, it gives the smallest number satisfying
//count >= req as the answer.

//another thing to note is that req = (r*c+1)/2 and not just r*c/2.
//this ensures that we are counting the median element also.
//for example: if the elements were 1,2,3,5,6,7,8
//if we take req = r*c/2 then we get the answer as 4 as it is the smallest number for 
//which count >= req. But 4 does not exist in the matrix.
//on the other hand if we take req = (r*c+1)/2, we get 5 as answer as it is the
//smallest number for which count >= req. this is because req this time is 4 instead 
//of 3. so, median element needs to be counted for count to be greater than req.
//and median element will be the smallest such element hence it gives the answer. 
//putting all the elements in a vector and then sorting it
//and then putting all the sorted elements back in the given matrix.

//Time Complexity: O(N*Nlog(N*N))
//Space complexity: O(N*N)

//here, matrix is of size N*N


        vector <int> nums;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                nums.push_back(Mat[i][j]);
            }
        }
        
         sort(nums.begin(), nums.end());
         
         int k = 0;
         for(int i=0; i<N; i++)
         {
             for(int j=0; j<N; j++)
             {
                 Mat[i][j] = nums[k];
                 k++;
             }
         }
        
        return Mat;


//MIN HEAP can be used to get the solution in O(N*NlogN)
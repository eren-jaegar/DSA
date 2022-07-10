 
        long long int best;
        long long int sum = 0;
        best = arr[0];
        for(int i=0; i<n; i++)
        {
            sum = max(sum+arr[i],(long long int)arr[i]);
            best = max(best,sum);
        }
        return best;
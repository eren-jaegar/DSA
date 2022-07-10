//if the sum of any subarray is zero then the sum before that subarray and after that
//subarray should be same.
//so we start iterating the array and calculating the sum and recordinf its frequency
//in a map. This way if frequency of any sum is greater than 1 than it assured that
//there is a zero sum subarray.
//one frequency for sum = 0 is added initially because if the sum ever goes to 0
//then 1 time is enough, it need not go to zero for the second time and also it might
//actually never get zero the second time as well for ex: {-20,5,5,5,5,5,5};
//unordered set with its find funtion can also be implemented instead of map.


for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
                return true;
        }
        int sum = 0;
        map <int,int> m;
        m[0]++;                 //frequency for sum 0 is added additionally
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            m[sum]++;
        }
        // if(sum == 0)
        // return true;
        auto it = m.begin();
        for(; it != m.end(); it++)
        {
            if(it->second > 1)
            return true;
        }
        return false;



//solution using unordered set


        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
                return true;
        }
        int sum = 0;
        unordered_set <int> m;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(sum == 0 || m.find(sum) != m.end())
            return true;
            m.insert(sum);
        }
        return false;
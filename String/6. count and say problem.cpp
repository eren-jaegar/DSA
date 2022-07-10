//the idea is simple. we run a loop for n-1 times.
//in that loop we have a nested loop that iterates over the entire string to find
//the next string. we just keep counting till the elements are same and then for the
//next string, we push_back the count and the number we were counting.

//in the code given below, if(n == 1) condition is in vain and the code will work
//just fine without it as well.


        int count;
        string dummy = "1";
        string dummy2;
        if(n == 1)
        {
            return dummy;
        }
        n--;
        while(n--)
        {
            count = 1;
            dummy2.clear();
            for(int i=0; i<dummy.size()-1; i++)
            {
                count = 1;
                while(dummy[i] == dummy[i+1])
                {
                    count++;
                    i++;
                }
                dummy2.push_back(count + '0');
                dummy2.push_back(dummy[i]);
            }
            if(dummy.size() < 2)
            {
                dummy2.push_back('1');
                dummy2.push_back('1');
            }
            else if(dummy[dummy.size()-2] != dummy[dummy.size()-1])
            {
                dummy2.push_back('1');
                dummy2.push_back(dummy[dummy.size()-1]);
            }
            dummy.clear();
            dummy = dummy2;
        }
        return dummy;

//we cant use long long int because the result exceeds its range.
//we start by storing 1 in our answer vector and then multiplying it by further
//numbers. For ex: for 10! we store 1 then multiply it by 2 then by 3 and so on till 10.
//we store the number digit by digit in a vector and in reverse order such that
//a number, say 123456 will be stored in ans vector as {6,5,4,3,2,1}
//for each multiplication we multiply the number with each digit of the ans vector and 
//add carry. Rightmost digit of the resulting number is stored at the position of the
//original digit and the remaining digits are taken as carry over(in code variable b)
//For ex: for 6!, lets say we have reached till 5!=120 and now only 6 is left to be
//multiplied, this will be carried out as follows:
//120 is stored as {0,2,1}. Start multiplying by 6 from left so we get 0
//rightmost digit of 0 is stored in place of original 0 and carry over is remaining 
//digits. So, ans vector is now {0,2,1} and carryover is 0. Now multiply 2 by 6 and add
//carryover. We get 12. store rightmost digit of 12 in place of 2 and rest is carryover.
//So now, ans vector is {0,2,1} and carryover is 1. now, multiply 6 by 1 and add
//carryover. we get 7. store 7 in place of 1. ans vector is {0,2,7}. ans is 720.
//also if lets say carryover with last multiplication would have been non zero, then
//we would have push_backed it into the vector digit by digit from the right.



//another approach could have been by using the string but that would have probably
//been very complicated.

//another approach could have been using BigInteger. Look into that if you want to.
//Its probably an ADT(Abstract Data Structure?)


vector <int> ans = {1};
    int a;
    int b = 0;
    for(int i=1; i<=N; i++)
    {
        b = 0;
        for(int j=0; j<ans.size(); j++)
        {
            a = ans[j]*i + b;
            b = a/10;
            a = a%10;
            ans[j] = a;
        }
        while(b > 0)
        {
            ans.push_back(b%10);
            b = b/10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
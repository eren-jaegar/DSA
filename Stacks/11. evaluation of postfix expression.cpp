//did just like taught in Abdul Bari course

//it is for operands with single digits but can be extended to operands with multiple 
//digits. This can be achieved if we give space between every new operand and operator.
//when encountering an operand, run a while loop to extract all its digits.

//see this for extended code for operands with multiple digits.
//https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/


//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack <int> nums;
        int num1,num2;
        for(int i=0; i<S.size(); i++)
        {
            if(S[i]!='+' && S[i]!='-' && S[i]!='*' && S[i]!='/')
                nums.push(S[i]-'0');
            else
            {
                if(S[i] == '+')
                {
                    num1 = nums.top();
                    nums.pop();
                    num2 = nums.top();
                    nums.pop();
                    num2 += num1;
                    nums.push(num2);
                }
                else if(S[i] == '-')
                {
                    num1 = nums.top();
                    nums.pop();
                    num2 = nums.top();
                    nums.pop();
                    num2 -= num1;
                    nums.push(num2);
                }
                else if(S[i] == '*')
                {
                    num1 = nums.top();
                    nums.pop();
                    num2 = nums.top();
                    nums.pop();
                    num2 *= num1;
                    nums.push(num2);
                }
                else
                {
                    num1 = nums.top();
                    nums.pop();
                    num2 = nums.top();
                    nums.pop();
                    num2 /= num1;
                    nums.push(num2);
                }
            }
        }
        return nums.top();
    }
};




//Approach - 1
//push all the characters of the string into the stack and then one by one, assign 
//the top chracter of the stack to the string and then pop the top character.

//Time Complexity: O(N)
//Space Complexity: O(N)

char* reverse(char *S, int len)
{
    
    stack <char> string;
    for(int i=0; i<len; i++)
    {
        string.push(S[i]);
    }
    int j = 0;
    while(!string.empty())
    {
        S[j] = string.top();
        string.pop();
        j++;
    }
    return S;
}

//If we don't use stack then we can do it in O(1) space.
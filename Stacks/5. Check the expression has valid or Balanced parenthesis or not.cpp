//Approach - 1
//traverse through the entire string, one character at a time.
//if you encounter opening brackets then push them into the stack.
//if you encounter closing brackets then check the top element, if it is the opening
//bracket of the same kind(ex: ( for ) or { for } ) then pop the top element else if it
//is not of the same type then return false.
//in the end, check if the stack is empty or not. if not emmpty then return false
//else return true.

//Time Complexity: O(N)
//Space Complexity: O(N) for stack

class mystack
{
    struct Node
    {
        char data;
        Node* next;
        
        Node(char c)
        {
            data = c;
            next = NULL;
        }
    };
    
    Node* top;
    
public:
    mystack()
    {
        top = NULL;
    }
    
    void push(char c)
    {
        Node* temp = new Node(c);
        if(top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }
    
    char pop()
    {
        char x;
        if(top == NULL)
            return '\0';
        else
        {
            x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        return x;
    }
    
    bool isEmpty()
    {
        if(top == NULL)
            return true;
        return false;
    }
    
};

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        mystack ob;
        char c;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[')
                ob.push(x[i]);
            else
            {
                c = ob.pop();
                if(x[i] == ']' && c != '[')
                    return false;
                else if(x[i] == '}' && c != '{')
                    return false;
                else if(x[i] == ')' && c != '(')
                    return false;
            }
        }
        if(!ob.isEmpty())
            return false;
            
        return true;
    }

};


//NOTE: We could have used stl stack as well(infact should have used that only).
//Approach - 1
//not a good approach
//reverse both the numbers and run two nested while loops.
//multiply the first digit of the second number by all the digits of the first number
//and store all the results. now, multiply the second digit of the second number with
//all the digits of the first number and add them with the previous digits obtained.
//while adding leave the first node and then add as now yu have multiplied with the tens
//digit.
//basically we do it like normal multiplication.

//Time Complexity: O(N*M)
//Space Complexity: O(N+M) to store the result in a linked list.

Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int size(Node* head)
{
    Node* current = head;
    int count = 0;
    while(current)
    {
        count++;
        current = current->next;
    }
    return count;
}

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long int x = 1000000007;
    Node* l3 = NULL;
    l1 = reverse(l1);
    l2 = reverse(l2);
    int s1 = size(l1);
    int s2 = size(l2);
    if(s2 > s1)
        swap(l1,l2); //we do this because using start in the while loop can give some 
    //unwanted results.
    Node* current1 = l1;
    Node* current2 = l2;
    Node* current3 = l3;
    Node* prev = NULL;
    Node* start = NULL;
    Node* temp = NULL;
    long long int prod;
    long long int carry;
    while(current2)
    {
        current1 = l1;
        carry = 0;
        while(current1)
        {
            prod = current1->data * current2->data + carry;
            if(current3 == NULL)
            {
                carry = prod/10;
                prod = prod%10;
                temp = new Node(prod);
                current3 = temp;
                if(prev == NULL)
                    prev = current3;
                else
                    prev->next = current3;
                prev = current3;
                current3 = current3->next;
                if(l3 == NULL)
                    l3 = temp;
            }
            else
            {
                current3->data += prod;
                carry = current3->data/10;
                current3->data = current3->data%10;
                current3 = current3->next;
                prev = prev->next;
            }
            current1 = current1->next;
        }
        if(carry)
        {
            temp = new Node(carry);
            prev->next = temp;
            prev = temp;
            current3 = temp->next; //temp->next is NULL
        }
        current2 = current2->next;
        if(start == NULL) //if we have added only one digit(possible only when l1 is a single digit number and its multiplication with l2's first digit gives a single digit number) when we first arrive here
        	//then l3->next will again make start as NULL which will cause trouble 
        	//in the next run as start will again be initialized to l3->next i.e the 
        	//second node in l3 but for the third run we want it to point to third node
        	//this is why we check for size and give smaller size to l2
        {
            start = l3->next;
            prev = l3;
        }
        else
        {
            prev = start;
            start = start->next;
        }
        current3 = start;
    }
    long long int sum = 0;
    long long int i = 1;
    long long int number;
    current3 = l3;

    while(current3)
    {
        number = ((current3->data * i)%x);
        sum = ((sum + number)%x);
        current3 = current3->next;
        i *= 10;
        i = i%x;
    }
    return sum;
}



//Approach - 2
//reverse the given two lists.
//Now, extract the two numbers from them by iterating over them and multiplying by
//an increased power of 10 as you proceed further and adding all the numbers
//and taking their mod by 1000000007.

//multiply both the numbers and take their mod. this will be the answer.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    
    long long int num1 = 0,num2 = 0,ans = 0;
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node* current1 = l1;
    Node* current2 = l2;
    long long int temp,i = 1;
    long long int x = 1000000007;
    while(current1)
    {
        temp = (current1->data * i)%x;
        num1 = (num1 + temp)%x;
        i *= 10;
        i = i%x;
        current1 = current1->next;
    }
    i = 1;
    while(current2)
    {
        temp = (current2->data * i)%x;
        num2 = (num2 + temp)%x;
        i *= 10;
        i = i%x;
        current2 = current2->next;
    }
    ans = (num1*num2)%x;
    return ans;
}



//Best Solution
//Could have been done like this also, without reversing the lists.
//the method to extract the numbers is a little different.
//in each step we multiply the partially extracted number by 10 and then add current->data
//to it.

//Time Complexity: O(N+M)
//Space Complexity: O(1)

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    
    long long int num1 = 0,num2 = 0,ans = 0;
    Node* current1 = l1;
    Node* current2 = l2;
    long long int x = 1000000007;
    while(current1)
    {
        num1 = (num1*10 + current1->data)%x;
        current1 = current1->next;
    }
    while(current2)
    {
        num2 = (num2*10 + current2->data)%x;
        current2 = current2->next;
    }
    ans = (num1*num2)%x;
    return ans;
}
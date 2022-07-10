//Approach - 1
//create an unordered_map to keep track of frequency of each element.
//create a queue.
//we start traversing the given string.
//when we encounter an element whose frequency is zero then, we push it into the queue.
//this step is done for all the elements of the string: increase the frequency of the
//current element by 1.
//now, if the frequency of the front element of the queue is 1 then it is the first non
//repeating character.
//else if its frequency is not 1 then, keep popping the elements until the list is empty
//or the frequency of the front element is 1.
//if the ist gets empty then there is no non-repeating character.
//else the front character is the first non-repeating character.

//Time Compleexity: O(N) //each element is pushed and popped at max once each
//Space Complexity: O(N)

class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    string ans;
		    unordered_map <char,int> num;
		    queue <char> charque;
		    for(int i=0; i<A.size(); i++)
		    {
		        if(num[A[i]] == 0)
		        {
		            charque.push(A[i]);
		        }
		        num[A[i]]++;
		        if(num[charque.front()] == 1)
		        {
		            ans.push_back(charque.front());
		        }
		        else
		        {
		            while(!charque.empty() && num[charque.front()]>1)
		                charque.pop();
		            if(charque.empty())
		                ans.push_back('#');
		            else
		            {
		                ans.push_back(charque.front());
		            }
		        }
		    }
		    return ans;
		}

};



//Approach - 2
//we create a doubly linked list.
//maintain a frequency hash map also.
//create a Node* array also. it stores the address of the node for each element in the DLL.
//if the frequency of current element is 0 then add it to the list.
//also update its pointer in the array so that it can be accessed in constant time.

//do this irrespective of the frequency: increase the frequency of the current element by 1.

//check if the frequency of current element is 2.
//if it is 2 then the element has repeated, access its Node* pointer from the array and
//delete it from the DLL.

//check if the head is NULL,i.e., if the DLL is empty or not. if it is empty then, there
//is no non repeating element. push_back('#')
//else push_back() the element pointed by head.

//using this approach, we can always get the first non-repeating element in O(1) time.

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    
		    struct Node
		    {
		        char val;
		        Node* next;
		        Node* prev;
		        
		        Node(char c)
		        {
		            val = c;
		            next = NULL;
		            prev = NULL;
		        }
		    };
		    
		    Node* head = NULL;
		    Node* tail = NULL;
		    Node* temp = NULL;
		    string ans;
		    Node* pointer[26] = {NULL};
		    unordered_map <char,int> freq;
		    for(int i=0; i<A.size(); i++)
		    {
		        if(freq[A[i]] == 0)
		        {
		            temp = new Node(A[i]);
		            if(!head)
		            {
		                head = temp;
		                tail = temp;
		            }
		            else
		            {
		                tail->next = temp;
		                temp->prev = tail;
		                tail = temp;
		            }
		            pointer[A[i]-'a'] = temp;
		        }
		        freq[A[i]]++;
		        if(freq[A[i]] == 2)
		        {
		            temp = pointer[A[i]-'a'];
		            pointer[A[i]-'a'] = NULL;
		            if(head == tail)
		            {
		                head = NULL;
		                tail = NULL;
		                delete temp;
		            }
		            else if(temp == tail)
		            {
		                temp->prev->next = NULL;
		                tail = temp->prev;
		                delete temp;
		            }
		            else if(temp == head)
		            {
		                temp->next->prev = NULL;
		                head = temp->next;
		                delete temp;
		            }
		            else
		            {
		                temp->prev->next = temp->next;
		                temp->next->prev = temp->prev;
		                delete temp;
		            }
		        }
		        if(head == NULL)
		            ans.push_back('#');
		        else
		        {
		            ans.push_back(head->val);
		        }
		    }
		    return ans;
		}

};
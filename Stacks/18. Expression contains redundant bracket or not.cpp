//Approach - 1
//create a stack.
//we start iterating through the expression.
//if the current character is anything except ')' then, push it into the stack.
//if the current character is ')' then, keep popping the elements out of the stack until
//the stack is empty or until we get '('.
//if the first character popped out of stack is '(' then, the expression contains 
//redundant brackets. this case finds redundancy of type ((a+b)).

//else if while popping characters, we do not encounter any operator beofre encountering
//'(' then also it contains redundant brackets. this case finds out the redundancy of
//type a+(b). here brackets around b are redundant. so basically, while popping, if
//we encounter only one element before getting '(' and if that element is not an
//operator then, we have a redundancy.

//else if no such case is encountered, then we don't have a redundancy.

//it works because, if we have the first kind of redundancy, then the inner brackets
//pop everything out and there is nothing left to be popped out by the outer brackets.
//so while popping for the outer brackets, the first character that we encounter is '('
//and hence, this logic works.


//Time Complexity: O(N)
//Space Complexity: O(N)



//Link to the article: https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
//prerequisite kind of similar article that deals only with first kind of redundancy 
//and not the second kind: https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
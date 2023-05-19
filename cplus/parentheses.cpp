#include <string>
#include <iostream>
#include <stack>
using namespace std;

/*
 *STACK METHOD
 *TIME COMPLEXITY: O(n)
 *SPACE COMPLEXITY: O(n)
 *THOUGHT PROCESS: to validate the string, I check if every "open-something" have a complement.
 *Because I dont know the inner structure of the string, would be very difficult to check individually
 *every pair. So, for this, I store all "open-something" I come across in a structure (in this case a
 *stack, due to its fast insertion, removal and lookup time) and, when I find a "close-something", I
 *see if it makes a pair with the last element added to the structure. If it does, I pop the last element
 *and continue traversing the string.
 */
bool solution(string s) {
    
    stack<char> my_stack;
    if (s.size() % 2 != 0)
        return false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' or s[i] == '(' or s[i] == '[')
            my_stack.push(s[i]);

        else if (my_stack.empty())
            return false;

        else 
        {
            if (s[i] == '}')
            {
                if (my_stack.top() != '{')
                    return false;
                my_stack.pop();
            }
            else if (s[i] == ')')
            {
                if (my_stack.top() != '(')
                    return false;
                my_stack.pop();
            }
            else if (s[i] == ']')
            {
                if (my_stack.top() != '[')
                    return false;
                my_stack.pop();
            }
        }
    }
    if (my_stack.empty())
        return true;

    return false;
}

"""
STACKMETHOD
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
THOUGHT PROCESS: to validate the string, I check if every "open-something" have a complement.
Because I dont know the inner structure of the string, would be very difficult to check individually
every pair. So, for this, I store all "open-something" I come across in a structure (in this case a
stack, due to its fast insertion, removal and lookup time) and, when I find a "close-something", I
see if it makes a pair with the last element added to the structure. If it does, I pop the last element
and continue traversing the string. 
"""
def solution(s):
    stack = []

    if len(s) % 2 != 0:
        return False

    for char in s:
        if char == '{' or char == '(' or char == '[':
            stack.append(char)

        elif len(stack) == 0:
            return False

        else:
            if char == '}':
                if stack[len(stack) - 1] != '{':
                    return False
                stack.pop()
            elif char == ')':
                if stack[len(stack) - 1] != '(':
                    return False
                stack.pop()
            elif char == ']':
                if stack[len(stack) - 1] != '[':
                    return False
                stack.pop()

    if len(stack) == 0:
        return True




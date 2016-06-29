# Excercise 4.3.1.py #

def IsPalindrome(string):
    l = len(string)
    if l <= 0:
        return False
    if l % 2:
        string = string.replace(string[(l-1)//2], '')
    stack = []
    stack.append(string[0])
    for c in string[1:]:
        if c != stack[-1]:
            stack.append(c)
        else:
            stack.pop()
    print(stack)
    return len(stack) == 0


def isValid(s: str) -> bool:
    stack = []
    
    for ch in s:
        if ch in "({[":
            stack.append(ch)
        elif stack and ((ch == ')' and stack[-1] == '(') or
                        (ch == ']' and stack[-1] == '[') or
                        (ch == '}' and stack[-1] == '{')):
            stack.pop()
        else:
            return False
    
    return not stack


s = "{[()]()}"
print(isValid(s))  # Output: True

s = "{(([)])}"
print(isValid(s))  # Output: False

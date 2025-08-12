import sys
def myAtoi(s):
    i = 0
    n = len(s)
    sign = 1
    ans = 0
    while i < n and s[i] == ' ':
        i += 1
    if i < n and (s[i] == '+' or s[i] == '-'):
        sign = -1 if s[i] == '-' else 1
        i += 1
    while i < n and '0' <= s[i] <= '9':
        digit = ord(s[i]) - ord('0')
        if ans > (sys.maxsize - digit) // 10:
            return sys.maxsize if sign == 1 else -sys.maxsize -1
        ans = ans * 10 + digit
        i += 1
    return ans * sign

s = input()
print(myAtoi(s))
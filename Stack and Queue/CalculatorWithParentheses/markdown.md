## Problem Calculator with + - * / and Parentheses

Implement a calculator to evaluate a string expression containing non-negative integers, operators `'+', '-', '*', '/'`, parentheses '(' and ')', and spaces. Division should truncate toward zero (i.e., integer division behavior).

```
Example

Input:  "3+2*2"                         Output: 7
Input:  " (1+(4+5+2)-3)+(6+8) "         Output: 23
Input:  "14-3/2"                        Output: 13  (since 3/2 -> 1, 14-1 = 13)

```

## Approach
Two common choices:

- Convert to Reverse Polish Notation (Shunting-yard) then evaluate RPN.
- Single-pass with two stacks: ops (operators including parentheses) and nums (numbers)
- Use operator precedence: * and / higher than + and -.
- When reading an operator, apply operators from ops while top operator has ≥ precedence.
- Parentheses push '(' and when encountering ')' apply until '('.
- At the end, apply remaining operators.

I'll use the two-stacks approach. Careful with integer division: Python int(a/b) truncates toward zero; Java/C++ integer division truncates toward zero for modern standards.

## Code

### Python 
```python
class Solution:
    def calculate(self, s: str) -> int:
        def prec(op: str) -> int:
            if op in ('+', '-'): return 1
            if op in ('*', '/'): return 2
            return 0

        def apply_op(ops, nums):
            op = ops.pop()
            b = nums.pop()
            a = nums.pop()
            if op == '+': nums.append(a + b)
            elif op == '-': nums.append(a - b)
            elif op == '*': nums.append(a * b)
            else: nums.append(int(a / b))  # trunc toward 0

        ops = []
        nums = []
        i = 0
        n = len(s)
        while i < n:
            c = s[i]
            if c == ' ':
                i += 1
                continue
            if c.isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + (ord(s[i]) - ord('0'))
                    i += 1
                nums.append(num)
                continue
            if c == '(':
                ops.append(c)
            elif c == ')':
                while ops and ops[-1] != '(':
                    apply_op(ops, nums)
                ops.pop()  # pop '('
            else:
                # operator + - * /
                while ops and prec(ops[-1]) >= prec(c):
                    apply_op(ops, nums)
                ops.append(c)
            i += 1

        while ops:
            apply_op(ops, nums)
        return nums[-1]

# quick tests
if __name__ == "__main__":
    sol = Solution()
    print(sol.calculate("3+2*2"))              # 7
    print(sol.calculate(" (1+(4+5+2)-3)+(6+8) "))  # 23
    print(sol.calculate("14-3/2"))             # 13
```

### Java
```java
import java.util.*;

public class java_code {
    private int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    private void applyOp(Deque<Character> ops, Deque<Integer> nums) {
        char op = ops.removeLast();
        int b = nums.removeLast();
        int a = nums.removeLast();
        int res = 0;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break; // trunc toward 0
        }
        nums.addLast(res);
    }

    public int calculate(String s) {
        Deque<Character> ops = new ArrayDeque<>();
        Deque<Integer> nums = new ArrayDeque<>();
        int i = 0, n = s.length();
        while (i < n) {
            char c = s.charAt(i);
            if (c == ' ') { i++; continue; }
            if (Character.isDigit(c)) {
                int num = 0;
                while (i < n && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                nums.addLast(num);
                continue;
            }
            if (c == '(') ops.addLast(c);
            else if (c == ')') {
                while (!ops.isEmpty() && ops.peekLast() != '(') applyOp(ops, nums);
                ops.removeLast(); // pop '('
            } else {
                while (!ops.isEmpty() && prec(ops.peekLast()) >= prec(c)) applyOp(ops, nums);
                ops.addLast(c);
            }
            i++;
        }
        while (!ops.isEmpty()) applyOp(ops, nums);
        return nums.peekLast();
    }

    public static void main(String[] args) {
        java_code s = new java_code();
        System.out.println(s.calculate("3+2*2")); // 7
        System.out.println(s.calculate(" (1+(4+5+2)-3)+(6+8) ")); // 23
        System.out.println(s.calculate("14-3/2")); // 13
    }
}
```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void applyOp(deque<char>& ops, deque<long long>& nums) {
    char op = ops.back(); ops.pop_back();
    long long b = nums.back(); nums.pop_back();
    long long a = nums.back(); nums.pop_back();
    long long res = 0;
    if (op == '+') res = a + b;
    else if (op == '-') res = a - b;
    else if (op == '*') res = a * b;
    else res = a / b; // trunc toward 0 for integers
    nums.push_back(res);
}

long long calculate(const string &s) {
    deque<char> ops;
    deque<long long> nums;
    int i = 0, n = s.size();
    while (i < n) {
        char c = s[i];
        if (c == ' ') { i++; continue; }
        if (isdigit(c)) {
            long long num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums.push_back(num);
            continue;
        }
        if (c == '(') ops.push_back(c);
        else if (c == ')') {
            while (!ops.empty() && ops.back() != '(') applyOp(ops, nums);
            ops.pop_back(); // pop '('
        } else {
            while (!ops.empty() && prec(ops.back()) >= prec(c)) applyOp(ops, nums);
            ops.push_back(c);
        }
        i++;
    }
    while (!ops.empty()) applyOp(ops, nums);
    return nums.back();
}

int main() {
    cout << calculate("3+2*2") << "\n";                 // 7
    cout << calculate(" (1+(4+5+2)-3)+(6+8) ") << "\n"; // 23
    cout << calculate("14-3/2") << "\n";                // 13
    return 0;
}
```

## Complexity
- Time: O(n) — each character processed constant times (operators applied ≤ numbers).

- Space: O(n) — stacks for numbers and operators.
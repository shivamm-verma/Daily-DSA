# Reverse Integer

## Problem Statement
Given a signed 32-bit integer `x`, return `x` with its digits reversed.  
If reversing `x` causes the value to go outside the signed 32-bit integer range  
`[-2^31, 2^31 - 1]`, return `0`.

**Note:**
- Assume the environment does not allow storing 64-bit integers (long).

---

## Example 1
**Input:**
x = 123

**Output:**
321

---

## Example 2
**Input:**
x = -123

**Output:**
-321

---   

## Constraints
- `-2^31 <= x <= 2^31 - 1`
- No usage of 64-bit integers allowed.

---

## Solution (Java)
```java
public class Solution {
    public int reverse(int x) {
        int rev = 0;
        boolean isNegative = false;

        if (x < 0) {
            isNegative = true;
            if (x == Integer.MIN_VALUE) // special case to avoid overflow
                return 0;
            x = -x;
        }

        while (x > 0) {
            int digit = x % 10;

            // Overflow check before multiplying
            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && digit > 7))
                return 0;

            rev = rev * 10 + digit;
            x /= 10;
        }

        return isNegative ? -rev : rev;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.reverse(123));   // Output: 321
        System.out.println(sol.reverse(-123));  // Output: -321
        System.out.println(sol.reverse(120));   // Output: 21
    }
}
```
---

## Solution (C++)
```C++
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        bool isNegative = false;

        if (x < 0) {
            isNegative = true;
            if (x == INT_MIN) // special case to avoid overflow
                return 0;
            x = -x;
        }

        while (x > 0) {
            int digit = x % 10;

            // Overflow check before multiplying
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return 0;

            rev = rev * 10 + digit;
            x /= 10;
        }

        return isNegative ? -rev : rev;
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(123) << endl;   // Output: 321
    cout << sol.reverse(-123) << endl;  // Output: -321
    cout << sol.reverse(120) << endl;   // Output: 21
    return 0;
}
```
---

## 📊 Complexity Analysis
**Time Complexity:**
O(log₁₀n) — where n is the absolute value of x.
We process each digit once, so the complexity is proportional to the number of digits.

**Space Complexity:**
O(1) — constant extra space is used; no additional data structures are needed.

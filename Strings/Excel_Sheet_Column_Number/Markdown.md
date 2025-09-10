# 🏃 Excel Sheet Column Number Problem

## 📝 Problem Statement

Given a string `columnTitle` that represents the column title as it appears in an Excel sheet (e.g., "A", "AB", "ZY"), return its corresponding column number.

### Example Mapping:

- "A" → 1
- "Z" → 26  
- "AA" → 27
- "AB" → 28

## ✅ Example

**Input:**
```
columnTitle = "AB"
```

**Output:**
```
28
```

**Explanation:**
- 'A' → 1 and 'B' → 2
- Calculation: (1 × 26^1) + (2 × 26^0) = 26 + 2 = 28

**Input:**
```
columnTitle = "ZY"
```

**Output:**
```
701
```

**Explanation:**
- 'Z' → 26 and 'Y' → 25
- Calculation: (26 × 26^1) + (25 × 26^0) = 676 + 25 = 701

## ✅ Approach (Iterative Calculation)

### Step-by-Step Breakdown

1. Initialize `result = 0` to store the final column number.
2. Iterate through each character in `columnTitle`:
   - For each character `char`, calculate `charValue = ord(char) - ord('A') + 1`.
   - Update `result = result * 26 + charValue`.
3. Return the computed result.

### ⏱️ Time and Space Complexity

| Metric | Value | Explanation |
|--------|-------|-------------|
| Time Complexity | O(n) | Single pass through the input string |
| Space Complexity | O(1) | Constant extra space used |
### 📌 Notes

- This is a straightforward base-26 number system problem.
- The key insight is to treat the string as a base-26 number and compute the equivalent decimal number.
- Edge case: Input always contains uppercase letters.

### 🎯 Key Insights

- **Character Conversion:** Use ASCII values to map characters 'A' to 'Z' to numbers 1 to 26.
- **Cumulative Multiplication:** Multiply previous result by 26 to shift the digit place.
- **Direct Mapping:** No need for extra data structures.

##  Python Solution : 

```python
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        for char in columnTitle:
            result = result * 26 + (ord(char.upper()) - ord('A') + 1)
        return result

if __name__ == "__main__":
    columnTitle = input("Enter Excel column title (e.g., 'AB'): ")
    solution = Solution()
    print("Column Number is:", solution.titleToNumber(columnTitle))
```

##  Java Solution :

```java
import java.util.Scanner;

public class Solution {
    public int titleToNumber(String columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            result = result * 26 + (columnTitle.charAt(i) - 'A' + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Excel column title (e.g., 'AB'): ");
        String columnTitle = sc.nextLine();
        Solution solution = new Solution();
        System.out.println("Column Number is: " + solution.titleToNumber(columnTitle));
        sc.close();
    }
}
```

##  C++ Solution : 

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

int main() {
    string columnTitle;
    cout << "Enter Excel column title (e.g., 'AB'): ";
    cin >> columnTitle;

    Solution solution;
    cout << "Column Number is: " << solution.titleToNumber(columnTitle) << endl;

    return 0;
}
```

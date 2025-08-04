## ✅ DSA Question: Reverse a String In-Place

---

### 🧠 Problem  
Given a string as an array of characters, reverse it in-place using **O(1)** extra memory.

You **must not return a new string**; instead, modify the input character array.

**Examples:**  
- Input: `"hello"` → Output: `"olleh"`  
- Input: `"Hannah"` → Output: `"hannaH"`

---

## 🧭 Approach

1. Initialize two pointers:  
   – `left` at index `0`  
   – `right` at index `length - 1`

2. While `left < right`:  
   – Swap `s[left]` and `s[right]`  
   – Increment `left` and decrement `right`

3. Once all elements have been swapped, the string is reversed in-place.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function reverseString(s):
    left = 0
    right = length of s - 1

    while left < right:
        temp = s[left]
        s[left] = s[right]
        s[right] = temp
        left += 1
        right -= 1
```
---
## Code

### Java
```java
package problems.strings.reverse;

public class Solution {
     public static void reverseString(char[] s) {
        int l=0,r=s.length-1;
        while(l<r){
            char temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;
            r--;
        }
    }
    public static void main(String[] args) {
        String str="hello";
        char[] ch=str.toCharArray();
        reverseString(ch);
        for(char chr:ch) System.out.print(chr); //Output : "olleh"
    }
}
```


### Python
```python
def reverse_string(s):
    l, r = 0, len(s) - 1
    while l < r:
        s[l], s[r] = s[r], s[l]
        l += 1
        r -= 1

# Main
s = list("hello")  # Convert string to list of characters
reverse_string(s)
print("".join(s))  # Output: olleh
```

### C++
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main() {
    string str = "hello";
    vector<char> ch(str.begin(), str.end());
    reverseString(ch);
    for (char c : ch) cout << c; // Output: olleh
    return 0;
}
```
---
## ⏱️ Complexities
 >Time Complexity
**O(n)** — where n is the number of characters in the string.

 >Space Complexity
**O(1)** — in-place reversal using only two pointers.
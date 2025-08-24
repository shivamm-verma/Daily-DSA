## ✅ DSA Question: Find Repeating and Missing Numbers

---

### 🧠 Problem  
You are given an array of size n containing numbers from 1 to n.
One number is repeating, and one number is missing. Find both.

**Examples:**  
- Input: `"nums = [3,1,2,5,3]"` → Output: `Repeating = 3, Missing = 4`  
- Input: `"nums = [1,1]"` → Output: `Repeating = 1, Missing = 2`

**Constraints:**  
- 2 <= n <= 10^5 
- 1 <= nums[i] <= n
- Exactly one number is missing and one is repeating.

---

## 🧭 Approach [ Brute Force ]

1. For each number i from 1 to n:
    - Count how many times i appears in the array.
    - If frequency = 2 → Repeating
    - If frequency = 0 → Missing

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function findRepeatingAndMissing(nums, n):
    for i from 1 to n:
        count = 0
        for j from 0 to n-1:
            if nums[j] == i:
                count += 1

        if count == 2:
            repeating = i
        if count == 0:
            missing = i

    return repeating, missing
```

## ⏱️ Complexities
 > Time Complexity
**O(n^2)** — nested loops

> Space Complexity
**O(1)** — no extra data structures

---

## 🧭 Approach [ Better Approach ]

1. Create a frequency array of size n+1 (or a hashmap).
2. Traverse nums and increment frequency for each number.
3. Traverse frequency array:
   - Frequency = 2 → Repeating
   - Frequency = 0 → Missing
---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function findRepeatingAndMissing(nums, n):
    freq = array of size n+1 initialized with 0

    for num in nums:
        freq[num] += 1

    for i from 1 to n:
        if freq[i] == 2:
            repeating = i
        if freq[i] == 0:
            missing = i

    return repeating, missing
```

## ⏱️ Complexities
 > Time Complexity
**O(n)** — single pass for frequency + single pass for checking

> Space Complexity
**O(n)** — for frequency array

---

## 🧭 Approach [ Optimal Approach ]

1. Compute:
   - Sn = n*(n+1)/2 → expected sum of 1…n
   - S2n = n*(n+1)*(2n+1)/6 → expected sum of squares of 1…n

2. Compute actual sums from the array:
   - S = sum(nums)
   - S2 = sum(nums[i]^2)

3. Let x = repeating, y = missing. Then:
   - S - Sn = x - y
   - S2 - S2n = x² - y² = (x-y)(x+y)

4. Solve these two equations to get x and y.
---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function findRepeatingAndMissing(nums, n):
    Sn = n*(n+1)/2
    S2n = n*(n+1)*(2n+1)/6

    S = sum(nums)
    S2 = sum(num*num for num in nums)

    diff = S - Sn          # x - y
    sq_diff = S2 - S2n     # x^2 - y^2

    sum_xy = sq_diff / diff # x + y

    repeating = (diff + sum_xy) / 2
    missing = repeating - diff

    return repeating, missing
```

## ⏱️ Complexities
 > Time Complexity
**O(n)** — single pass to compute sums

> Space Complexity
**O(1)** — only a few variables

---

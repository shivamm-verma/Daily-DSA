# 🧮 DSA QUESTION: Max Consecutive Ones III

---

## 📝 Problem Statement

You are given a binary array `nums` and an integer `k`.  
You can flip **at most `k` 0's** to `1's` in the array.  
Return the **maximum number of consecutive 1's** in the array after at most `k` flips.

---

## 💡 Example

**Input:**  
`nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`

**Output:**  
`6`

**Explanation:**  
Flip the 0's at index **5 and 10**.  
The array becomes:  
`[1,1,1,0,0,1,1,1,1,1,1]`  
Which has **6 consecutive 1's** from index **5 to 10**.

---

## ✅ Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`
- `0 <= k <= nums.length`

---

## 🐢 Brute-Force Approach

### 💡 Idea

For every subarray, count the number of 0's.  
If the number of 0's is ≤ `k`, check if it's the longest such subarray.

### 🔁 Steps

1. Loop over every possible starting index `i`.
2. From `i`, try every possible ending index `j`.
3. For each subarray `nums[i...j]`, count number of 0's.
4. If zero count ≤ `k`, update max length.

---

## ⚡ Optimal Approach: Sliding Window

### 🧠 Key Idea

Maintain a window that contains at most `k` zeroes.

- Expand the window by moving the **right pointer**.
- If the window contains more than `k` zeroes, shrink it from the **left**.
- Keep track of the **maximum length**.

---

### 🔁 Steps

1. Use two pointers: `left` and `right` to maintain the window.
2. Track the count of `zeroes` in the window.
3. When the count exceeds `k`, move the `left` pointer forward until the count is ≤ `k`.
4. At each step, update the max length.

---

## 📜 Pseudocode

```text
function longestOnes(nums, k):
    initialize zeros = 0
    initialize maxLength = 0
    initialize i = 0, j = 0
    n = length of nums

    while j < n:
        if nums[j] is 0:
            increment zeros

        while zeros > k:
            if nums[i] is 0:
                decrement zeros
            increment i

        update maxLength as max of (maxLength, j - i + 1)
        increment j

    return maxLength
```

### ⏱️ Complexity

- **Time:** `O(n^2)` (Brute) and `O(n)` (Optimal).
- **Space:** `O(1)`.

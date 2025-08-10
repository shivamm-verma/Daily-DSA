## 📘 Problem Statement: Split Array Largest Sum

Given an integer array `nums` and an integer `k`, split the array into `k` non-empty **contiguous** subarrays such that the **largest sum among these subarrays is minimized**.

Return this **minimized largest sum**.

---

## 🧪 Example

### Input:

```plaintext
nums = [7, 2, 5, 10, 8], k = 2
```

### Output:

```plaintext
18
```

### Explanation:

We can split the array in the following ways:

* \[7] and \[2, 5, 10, 8] → max sum = 25 ❌
* \[7, 2] and \[5, 10, 8] → max sum = 23 ❌
* \[7, 2, 5] and \[10, 8] → max sum = **18** ✅
* \[7, 2, 5, 10] and \[8] → max sum = 24 ❌

**Optimal split:** \[7, 2, 5] and \[10, 8]

---

## 1️⃣ Optimal Approach — Binary Search + Greedy Check

## 💡 Key Idea

Instead of trying every possible split (which is exponential), we **binary search** on the answer — the **minimum possible maximum subarray sum**.

To do this:

* Define a range of possible answers: `low = max(nums)`, `high = sum(nums)`
* Perform binary search on this range
* For each mid, check if it's **possible to split into <= k subarrays** such that **no subarray exceeds mid**

---

## ✅ isPossible Function (Greedy Check)

* Try to divide the array into subarrays
* Start a new subarray **only when adding current element exceeds mid**
* If number of subarrays becomes more than `k`, return false

---

## ⚙️ Time & Space Complexity

> Time: O(n \* log(sum - max))
> Space: O(1) (only using counters and variables)

---

## 📝 Algorithm Steps

1. Set `low = max(nums)` and `high = sum(nums)`
2. While low <= high:

   * Set `mid = (low + high) / 2`
   * If it's possible to split with max sum <= mid → try smaller value (move left)
   * Else → increase mid (move right)
3. Return the first value where possible = true

---

## 💭 Key Insights

* **Binary Search on Answer**: We're searching over the answer space, not the input
* **Greedy Validation**: We simulate the splits with a greedy approach
* **Range Logic**: min possible max sum = max element, max possible = sum of array

---

## 🎯 Edge Cases

* `nums.length == k`: Each element becomes a subarray → return max(nums)
* `k == 1`: Entire array is one subarray → return sum(nums)
* `nums` has large numbers → use `long` in languages like Java

---


## 🧠 Alternative Approaches

* **DP**: Possible but time-consuming for large arrays (O(n^2 \* k))
* **Backtracking/Brute Force**: Exponential, not feasible for `n > 20`

---

## ✅ Final Thought

Use binary search not only on indices, but **on the value space** when the answer lies in a monotonic range. Combine with a greedy check to validate feasibility efficiently.

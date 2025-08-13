## Split Array Largest Sum — Approaches Explained

### Problem Statement
Given an integer array `nums` and an integer `k`, split the array into `k` non-empty subarrays such that the largest sum among these subarrays is minimized. Return the minimized largest sum of the split.

### 📘 Example

#### Input
```text
Array: [10, 20, 30, 40]
k = 2
Output: 60
```

#### Visual Explanation
```text
Possible splits for k=2:
Split 1: [10] and [20, 30, 40] → max sum = 90
Split 2: [10, 20] and [30, 40] → max sum = 70  
Split 3: [10, 20, 30] and [40] → max sum = 60 ✓ (optimal)
```
**Answer**: 60 (minimized largest sum)

---

### 1️⃣ Brute Force Approach (Try All Possible Splits)

#### Idea
- Generate all possible ways to split the array into exactly `k` subarrays.
- For each split configuration, calculate the maximum sum among all subarrays.
- Return the minimum of all these maximum sums.

#### Implementation Concept
- Use recursive backtracking to generate all valid splits
- For each complete split, compute max subarray sum
- Track the global minimum across all splits

#### Why Brute Force?
- Explores every possible combination without any optimization
- Doesn't use any mathematical properties to prune search space
- Processes exponential number of split configurations

#### Complexity
- Time: O(2^n) (exponential - trying all possible split points)
- Space: O(k) (recursion depth for k splits)

---

### 3️⃣ Optimal Approach (Binary Search + Greedy)

#### Idea
- **Key Insight**: Binary search on the answer (the minimized largest sum)
- **Search Range**: From max element (minimum possible answer) to total sum (maximum possible answer)
- **Validation**: Use greedy function to check if a given sum limit allows splitting into ≤ k subarrays

#### Greedy Validation Function
```text
For a given maxSum limit:
1. Iterate through array with running sum
2. If adding next element exceeds limit → start new subarray
3. Count total partitions needed
4. Return true if partitions ≤ k
```

#### Binary Search Logic
- If `countPartitions(mid) > k`: Limit too small → increase lower bound
- If `countPartitions(mid) ≤ k`: Limit feasible → try smaller limit

#### Why Optimal?
- **Logarithmic Search**: Binary search reduces search space exponentially
- **Efficient Validation**: Greedy checking in linear time
- **Mathematical Insight**: Searches on answer rather than exploring all splits
- **Space Efficient**: Uses only constant extra space

#### Complexity
- Time: O(n × log(sum)) where sum is total array sum
- Space: O(1) (only using a few variables)

---

### 📊 Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|----------------|------------------|------|------|
| **Brute Force** | O(2^n) | O(k) | Easy to understand | Exponentially slow |
| **Optimal (Binary Search)** | O(n × log(sum)) | O(1) | Very efficient, space optimal | Requires insight about searching on answer |

---
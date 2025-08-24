### ✅ DSA Question: Maximum XOR of Two Numbers in an Array

### 🧠 Problem

Given an array of integers, find two numbers whose XOR is maximum and return that maximum value.

Examples:

> Input: [3, 10, 5, 25, 2, 8] → Output: 28

> Input: [14, 70, 53, 83, 49, 91, 36, 80] → Output: 127

### 🧭 Approach

* We can solve this problem using a Trie (prefix tree) with bitwise representation of numbers:

* Insert numbers into a binary Trie:

* Each number is represented in 32-bit binary form.

* Each Trie node stores 0 or 1 links.

* Find maximum XOR:

* For each number, traverse the Trie from most significant bit (31) to least significant bit (0).

At each bit position:
– Prefer the opposite bit (1 - bit) to maximize XOR.
– If available, add the contribution (1 << i) to result.
– Otherwise, move along the same bit.

Keep track of the maximum XOR found during the traversal.

### 🔁 Generic Logic (Pseudocode)
```function findMaximumXOR(nums):
    trie = new Trie()
    maxXor = 0

    for num in nums:
        trie.insert(num)
        candidate = trie.getMax(num)
        maxXor = max(maxXor, candidate)

    return maxXor
```
### ⏱️ Complexities

 >Time Complexity

Insertion: O(32 * n) → O(n)

Query (getMax): O(32 * n) → O(n)

Overall: O(n), since 32 is constant.

>Space Complexity

Each number uses up to 32 Trie nodes.

Worst case: O(32 * n) ≈ O(n)
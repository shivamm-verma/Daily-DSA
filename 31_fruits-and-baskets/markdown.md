🍎 Problem: Fruit Into Baskets
📜 Problem Statement:
You are visiting a farm that has a single row of fruit trees, represented by an integer array fruits, where fruits[i] is the type of fruit the i-th tree produces.

You want to collect as much fruit as possible under the following conditions:

You have two baskets, each of which can only hold one type of fruit (but unlimited quantity).

You can start collecting from any tree and must pick exactly one fruit from each tree, moving only to the right.

You must stop once you encounter a third fruit type that doesn’t fit in your baskets.

🔍 Goal: Return the maximum number of fruits you can pick.

📥 Example:
Input: fruits = [1, 2, 3, 2, 2]
Output: 4
Explanation: We can pick [2, 3, 2, 2] — only 2 types of fruits, total of 4.

.

🔒 Constraints:
1 <= fruits.length <= 10⁵

0 <= fruits[i] < fruits.length

🔴 Problem Summary:
You're given an array of integers fruits representing fruit types.
You're allowed 2 baskets, and can collect fruits from left to right, one per tree, until you encounter more than two types.

🎯 Objective: Return the maximum number of fruits that can be collected under these constraints.

🧠 Idea:
Try every starting index and count how many fruits you can collect until a third fruit type is found.

✅ Steps:
Initialize maxFruits = 0

For every i from 0 to n-1:

Use a set or map to track fruit types.

For every j from i to n-1:

Add fruits[j] to the set.

If set size > 2 → break

Else, update maxFruits = max(maxFruits, j - i + 1)

Return maxFruits

⏱ Time Complexity:
Outer loop: O(n)

Inner loop: O(n)

Overall: O(n²)

📦 Space Complexity:
O(1) (at most 3 fruit types in the set)

✅ Optimal Approach: Sliding Window
🧠 Idea:
Use a sliding window (two-pointer technique) to maintain a valid window with at most 2 fruit types.

✅ Steps:
Initialize:

start = 0, maxFruits = 0

A map (or HashMap<Integer, Integer>) to count fruit types in the current window.

Loop end from 0 to n-1:

Add fruits[end] to the map and increase its count.

While map.size() > 2:

Decrease count of fruits[start]

If count becomes 0, remove from map

Move start++

Update maxFruits = max(maxFruits, end - start + 1)

Return maxFruits

⏱ Time Complexity:
O(n): Each element is added and removed from the map at most once.

📦 Space Complexity:
O(1): Maximum 3 fruit types in the map.


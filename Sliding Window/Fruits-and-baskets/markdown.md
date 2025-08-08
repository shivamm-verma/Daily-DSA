## ✅ DSA Question: Fruit Into Baskets
---

### 🧠 Problem
You are given an array fruits where each element represents the type of fruit a tree produces. You have two baskets, each of which can only hold one type of fruit, but with unlimited quantity.
You must pick exactly one fruit per tree, starting from any tree and moving to the right, until you encounter a third type of fruit.
Goal: Return the maximum number of fruits you can pick in this way.

**Examples:**
-Input: [1, 2, 1] → Output:3
-Input: [0, 1, 2, 2] → Output:3
-Input: [1, 2, 3, 2, 2] → Output:4

---

##🧭 Brute Force Approach

1.Try starting from every tree (index i).

2.From each starting point, move to the right collecting fruits.

3.Use a set or map to track the number of unique fruits in your baskets.

4.Stop when you encounter a third type of fruit.

5.Track the maximum fruits collected for all possible starting points.

---
## 🔁 Generic Logic (Pseudocode)
```plaintext
function totalFruit(fruits):
    maxFruits = 0
    for i from 0 to n - 1:
        create empty set basket
        count = 0
        for j from i to n - 1:
            add fruits[j] to basket
            if size of basket > 2:
                break
            count += 1
        maxFruits = max(maxFruits, count)
    return maxFruits
    ```
## ✅ Optimal Approach(Sliding Window)

1.Use two pointers start and end to define a sliding window.

2.Use a hashmap to count the fruits in the current window.

3.Expand end to include new fruits.

4.If the map has more than 2 fruit types, shrink the window by moving start forward.

5.Update the maximum size of a valid window.

---
##🔁 Optimal Logic(Pseudocode)
```plaintext
function totalFruit(fruits):
    start = 0
    maxFruits = 0
    hashmap = empty map
    for end from 0 to n - 1:
        hashmap[fruits[end]] += 1
        while size of hashmap > 2:
            hashmap[fruits[start]] -= 1
            if hashmap[fruits[start]] == 0:
                remove fruits[start] from hashmap
            start += 1
        maxFruits = max(maxFruits, end - start + 1)
    return maxFruits
    ```
## ⏱️Complexities
Brute Force:
>Time Complexity
**O(n²)** — Checking all possible subarrays.

>Space Complexity
**O(1)** — Only a small set of fruit types (max 3).

Optimal(Sliding Window):
>Time Complexity
**O(n)** — Each fruit is added and removed from the map at most once.

>Space Complexity
**O(1)** — Only up to 3 fruit types in the map.








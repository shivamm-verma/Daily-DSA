## DSA Question: Magic Fruit Basket

---

## Problem  
A wizard gave you a basket that can only hold fruits of **at most 2 different types**.

You are given an array of fruits:  
```

arr[i] = type of fruit

```

Your task is to find the **maximum number of fruits you can collect consecutively** in a row while respecting the basket's limit of 2 types.

---

## Examples  

### Example 1:
**Input:**  
```

arr = [1, 2, 1]

```

**Output:**  
```

3

```

**Explanation:**  
All fruits can be collected since there are only 2 types.

---

### Example 2:
**Input:**  
```

arr = [0, 1, 2, 2]

```

**Output:**  
```

3

```

**Explanation:**  
The longest subarray with at most 2 types is `[1, 2, 2]`.

---

### Example 3:
**Input:**  
```

arr = [1, 2, 3, 2, 2]

```

**Output:**  
```

4

```

**Explanation:**  
The longest subarray with at most 2 types is `[2, 3, 2, 2]`.

---

## Approach  

### 🧩 Simple / Beginner Approach
**(Brute-Force)**  
1. Iterate through all subarrays.  
2. Count the number of distinct fruit types in each subarray.  
3. If ≤ 2 types, update the maximum length.  

**Time Complexity:** O(n²)  
**Space Complexity:** O(n)  

---

### ⚙️ Medium / Logic Approach
**(Sliding Window with HashMap)**  
1. Use two pointers to maintain a sliding window.  
2. Keep a hashmap to count the frequency of each fruit type in the current window.  
3. Expand the window to the right.  
4. If the window has more than 2 types, shrink from the left until valid.  
5. Track the maximum window length during the process.  

**Time Complexity:** O(n)  
**Space Complexity:** O(1) (at most 2 keys in the hashmap)  

---

### 🚀 Hard / Optimized Approach
**(Optimized Sliding Window)**  
1. Use the same sliding window and hashmap logic.  
2. Dynamically update the maximum window length without extra loops.  
3. Efficiently handles very large arrays in linear time.  

**Time Complexity:** O(n)  
**Space Complexity:** O(1)  

---

## Topics of this Problem  
- **Sliding Window**  
- **HashMap / Dictionary**  
- **Two Pointers**
```

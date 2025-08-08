## ✅ DSA Question: Maximum Product Subarray

---

### 🧠 Problem  
Given an array `arr` of size `n` containing positive and negative numbers, find the maximum product obtained by a subarray. 

A subarry is a contiguous part of an array.

**Examples:**  
- Input: 
  `n = 4`
  `arr = [2, 3, -2, 4]` 
  Output: `6`  
- Input: 
  `n = 6`
  `arr = [-2, 6, -3, -10, 0, 2]` 
  Output: `180`

---

## 🧭 Approach

1. Initialize three variables: 
   – `curr_max` to track max product ending at current index – `curr_min` to track min product (in case a negative flips it) 
   – `max_product` to hold the overall max seen so far

2. Iterate through the array: 
   – Update `curr_max` and `curr_min` using current value and previous results 
   – Choose maximum/minimum among: current element, product with `curr_max`, product with `curr_min` 
   – Update `max_product` if `curr_max` is larger

3. Return the `max_product` found at the end.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function maxProduct(arr):
    curr_max = arr[0]
    curr_min = arr[0]
    max_product = arr[0]
    for i from 1 to length of arr - 1:
        temp = max(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_min = min(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_max = temp
        max_product = max(max_product, curr_max)
    return max_product
```
## ⏱️ Complexities
 >Time Complexity
**O(n)** — single-pass through the array, where n = number of elements in array.
 >Space Complexity
**O(1)** — only constant space used for tracking variables.
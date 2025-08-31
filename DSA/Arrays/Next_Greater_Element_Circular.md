# Next Greater Element in Circular Array

## 📌 Problem Statement  
Given a circular array `nums`, for each element, find the **next greater element**.  
The next greater element of a number `x` is the first element greater than `x` traversing circularly from its position.  
If it does not exist, return `-1` for that element.  

---

## 📝 Example  

### Example 1
**Input:**  
nums = [1, 2, 1]  

**Output:**  
[2, -1, 2]  

**Explanation:**  
- For `1` (index 0), the next greater element is `2`.  
- For `2` (index 1), no greater element exists → `-1`.  
- For `1` (index 2), circularly the next greater is `2`.  

---

### Example 2
**Input:**  
nums = [5, 3, 8, -2, 7]  

**Output:**  
[8, 8, -1, 7, 8]  

---

## ⚡ Approach  

1. Use a **monotonic stack** to keep track of elements.  
2. Traverse the array **twice** (simulate circular nature using `i % n`).  
3. For each element, if the stack’s top is smaller, pop it and assign the current element as its next greater.  
4. Push indices into the stack for later processing.  

---

## 💻 Pseudocode  


## ✅ DSA Question: Insertion Sort

---

### 🧠 Problem  

Insertion Sort is a sorting algorithm that builds a sorted array one element at a time by placing each new element into its correct position.

---

## 🧭 Approach

1. Start from the second element (index 1) and compare it with the elements before it.  
2. Shift all larger elements one position to the right to make space.  
3. Insert the current element into its correct position.  
4. Repeat for all elements until the array is sorted.  

**Properties:**  
- Stable: preserves the relative order of equal elements.  
- In-place: rearranges elements directly without extra memory.  

---

## 🔁 Generic Logic (Pseudocode)
```text
for i = 1 to n-1:
    key = arr[i]
    j = i-1
    while j >= 0 and arr[j] > key:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key
```

## ⏱️ Complexities
 > Time Complexity
* Best case: **O(n)** (array already sorted)
* Average case: **O(n²)**
* Worst case: **O(n²)**


> Space Complexity
**O(1)** 
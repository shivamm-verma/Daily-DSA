## ✅ DSA Question: Bubble Sort

---

### 🧠 Problem  

Bubble Sort is a sorting algorithm that sorts a given array of numbers in ascending order by repeatedly swapping adjacent elements, pushing the largest elements toward the end in each pass.

---

## 🧭 Approach


1. Compare each pair of adjacent elements in the array.  
2. Swap them if the current element is larger than the next element.  
3. After each pass, the largest unsorted element moves to its correct position.  
4. Repeat for all elements (`n-1` passes).  

**Properties:**  
- Stable: preserves the relative order of equal elements.  
- In-place: swaps elements directly without extra space.  


---

## 🔁 Generic Logic (Pseudocode)
```text
for i = 0 to n-1:
    for j = 0 to n-i-2:
        if arr[j] > arr[j+1]:
            swap(arr[j], arr[j+1])
```

## ⏱️ Complexities
 > Time Complexity
* Best case: **O(n)** (array already sorted)
* Average case: **O(n²)**
* Worst case: **O(n²)**


> Space Complexity
* **O(1)** — no extra space used 



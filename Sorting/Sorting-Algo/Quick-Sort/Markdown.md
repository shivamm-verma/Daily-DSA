## ✅ DSA Question: Quick Sort

---

### 🧠 Problem  

Quick Sort is a divide-and-conquer sorting algorithm that selects a pivot element, partitions the array around the pivot such that elements less than the pivot come before it and elements greater come after, and then recursively sorts the partitions.

---

## 🧭 Approach

1. Select a pivot element (commonly the last element in the array).  
2. Partition the array so that elements less than the pivot are on the left, and elements greater than the pivot are on the right.  
3. Recursively apply Quick Sort on the left and right partitions.  
4. Repeat until the entire array is sorted.  

**Properties:**  
- Not stable: equal elements may change their relative order.  
- In-place: sorts the array directly without extra space.  

---

## 🔁 Generic Logic (Pseudocode)
```text
function quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j = low to high-1:
        if arr[j] <= pivot:
            i += 1
            swap(arr[i], arr[j])
    swap(arr[i+1], arr[high])
    return i + 1
```
## ⏱️ Complexities
 > Time Complexity
* Best/Average case: **O(n log n)**
* Worst case: **O(n²)**[occurs when the array is already sorted or reverse sorted and pivot choice is poor]



> Space Complexity
 **O(log n)** (recursion stack)




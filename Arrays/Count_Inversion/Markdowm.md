# Count Inversions in an Array

## Problem Statement

**Difficulty:** Medium  
**Topics:** Array, Divide and Conquer, Sorting  
**Companies:** Amazon, Microsoft, Adobe, Google

Given an array `arr[]` of size `n`, the task is to count the number of inversions.  
An **inversion** is defined as a pair of indices `(i, j)` such that:

- `i < j` and  
- `arr[i] > arr[j]`

Return the total number of inversions in the array.

---

## Examples

### Example 1
Input: arr = [5, 4, 3, 2, 1]
Output: 10
Explanation: All pairs form inversions because the array is sorted in reverse order.

shell
Copy code

### Example 2
Input: arr = [1, 20, 6, 4, 5]
Output: 5
Explanation: The inversion pairs are (20,6), (20,4), (20,5), (6,4), (6,5).

shell
Copy code

### Example 3
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The array is already sorted, so no inversions exist.

yaml
Copy code

---

## Constraints
- `1 <= n <= 10^5`
- `1 <= arr[i] <= 10^9`

---

## Solutions

### Approach 1: Brute Force (Not Recommended)

**Intuition:**  
Check every possible pair `(i, j)` where `i < j` and count if `arr[i] > arr[j]`.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

### Approach 2: Merge Sort Based (Optimal Solution)

**Intuition:**  
Use a modified Merge Sort.  
While merging two sorted halves:
- If `arr[i] <= arr[j]`, no inversion.  
- If `arr[i] > arr[j]`, then all elements from `i` to `mid` form inversions with `arr[j]`.

**Algorithm:**
1. Implement merge sort
2. During merge, count inversions
3. Return total inversion count

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

---

## Step-by-Step Walkthrough

For `arr = [5, 4, 3, 2, 1]`:

- Split: [5,4,3] & [2,1]  
- Count inversions during merge:  
  - (5,4), (5,3), (4,3) → 3  
  - (5,2), (4,2), (3,2), (5,1), (4,1), (3,1), (2,1) → 7  
- Total = 10

---

## LeetCode-Style Solutions

### C++ Solution
```cpp
class Solution {
public:
    long long mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        long long inv = mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
        return inv;
    }

    long long merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);
        int i = 0, j = 0, k = l;
        long long inv = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                inv += (left.size() - i);
            }
        }
        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
        return inv;
    }

    long long inversionCount(vector<int> arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
```


### Java Solution
```Java
class Solution {
    private long mergeSort(int[] arr, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        long inv = mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
        return inv;
    }

    private long merge(int[] arr, int l, int mid, int r) {
        int[] left = Arrays.copyOfRange(arr, l, mid + 1);
        int[] right = Arrays.copyOfRange(arr, mid + 1, r + 1);
        int i = 0, j = 0, k = l;
        long inv = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                inv += (left.length - i);
            }
        }
        while (i < left.length) arr[k++] = left[i++];
        while (j < right.length) arr[k++] = right[j++];
        return inv;
    }

    public long inversionCount(int[] arr) {
        return mergeSort(arr, 0, arr.length - 1);
    }
}
```


### Python Solution
```Python
class Solution:
    def merge_sort(self, arr, l, r):
        if l >= r:
            return 0
        mid = (l + r) // 2
        inv = self.merge_sort(arr, l, mid)
        inv += self.merge_sort(arr, mid + 1, r)
        inv += self.merge(arr, l, mid, r)
        return inv

    def merge(self, arr, l, mid, r):
        left, right = arr[l:mid+1], arr[mid+1:r+1]
        i, j, k = 0, 0, l
        inv = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
                inv += (len(left) - i)
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1; k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1; k += 1
        return inv

    def inversionCount(self, arr):
        return self.merge_sort(arr, 0, len(arr) - 1)
```
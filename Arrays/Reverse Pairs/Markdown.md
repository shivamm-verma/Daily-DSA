# Reverse Pairs in an Array

## Problem Statement

Given an integer array `nums`, return the **number of reverse pairs** in the array.

A **reverse pair** is defined as a pair `(i, j)` where:

- `0 <= i < j < nums.length`
- `nums[i] > 2 * nums[j]`

---

## Example

### Example 1:


Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
- (1, 4) -> 3 > 2*1
- (3, 4) -> 3 > 2*1

### Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
- (1, 4) -> 4 > 2*1
- (2, 4) -> 3 > 2*1
- (3, 4) -> 5 > 2*1

### Approaches
## 1. Brute Force (O(n²))

## Python

```
def reversePairsBrute(nums):
    count = 0
    n = len(nums)
    for i in range(n):
        for j in range(i+1, n):
            if nums[i] > 2 * nums[j]:
                count += 1
    return count

# Example
nums = [1,3,2,3,1]
print(reversePairsBrute(nums))  # Output: 2
```

## Java
```
public class ReversePairsBrute {
    public static int reversePairsBrute(int[] nums) {
        int count = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] > 2L * nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
    
    public static void main(String[] args) {
        int[] nums = {1,3,2,3,1};
        System.out.println(reversePairsBrute(nums)); // Output: 2
    }
}
```

## Cpp

```
#include <iostream>
#include <vector>
using namespace std;

int reversePairsBrute(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if ((long)nums[i] > 2 * (long)nums[j]) count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1,3,2,3,1};
    cout << reversePairsBrute(nums) << endl; // Output: 2
    return 0;
}
```

### 2. Optimized Approach using Merge Sort (O(n log n))


## Python
```
def reversePairs(nums):
    def merge_sort(start, end):
        if start >= end:
            return 0
        mid = (start + end) // 2
        count = merge_sort(start, mid) + merge_sort(mid + 1, end)
        
        # Count reverse pairs
        j = mid + 1
        for i in range(start, mid + 1):
            while j <= end and nums[i] > 2 * nums[j]:
                j += 1
            count += (j - mid - 1)
        
        # Merge step
        temp = []
        i, j = start, mid + 1
        while i <= mid and j <= end:
            if nums[i] <= nums[j]:
                temp.append(nums[i])
                i += 1
            else:
                temp.append(nums[j])
                j += 1
        while i <= mid:
            temp.append(nums[i])
            i += 1
        while j <= end:
            temp.append(nums[j])
            j += 1
        nums[start:end+1] = temp
        return count
    
    return merge_sort(0, len(nums)-1)

# Example
nums = [2,4,3,5,1]
print(reversePairs(nums))  # Output: 3
```


## Java

```
public class ReversePairsMergeSort {
    
    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length - 1);
    }
    
    private int mergeSort(int[] nums, int start, int end) {
        if(start >= end) return 0;
        int mid = (start + end) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid+1, end);
        
        // Count reverse pairs
        int j = mid + 1;
        for(int i = start; i <= mid; i++) {
            while(j <= end && (long)nums[i] > 2L * nums[j]) j++;
            count += (j - mid - 1);
        }
        
        // Merge
        int[] temp = new int[end - start + 1];
        int i = start, k = 0;
        j = mid + 1;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= end) temp[k++] = nums[j++];
        System.arraycopy(temp, 0, nums, start, temp.length);
        return count;
    }
    
    public static void main(String[] args) {
        int[] nums = {2,4,3,5,1};
        ReversePairsMergeSort obj = new ReversePairsMergeSort();
        System.out.println(obj.reversePairs(nums)); // Output: 3
    }
}
```

## Cpp

```
#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int>& nums, int start, int end) {
    if(start >= end) return 0;
    int mid = (start + end)/2;
    int count = mergeSort(nums, start, mid) + mergeSort(nums, mid+1, end);
    
    // Count reverse pairs
    int j = mid + 1;
    for(int i = start; i <= mid; i++) {
        while(j <= end && (long)nums[i] > 2*(long)nums[j]) j++;
        count += (j - mid - 1);
    }
    
    // Merge
    vector<int> temp;
    int i = start;
    j = mid + 1;
    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
        else temp.push_back(nums[j++]);
    }
    while(i <= mid) temp.push_back(nums[i++]);
    while(j <= end) temp.push_back(nums[j++]);
    
    for(int k = 0; k < temp.size(); k++) nums[start + k] = temp[k];
    
    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {2,4,3,5,1};
    cout << reversePairs(nums) << endl; // Output: 3
    return 0;
}
```

| Approach      | Time Complexity | Space Complexity | Notes                  |
|---------------|-----------------|------------------|------------------------|
| Brute Force   | O(n²)           | O(1)             | Simple but slow        |
| Merge Sort    | O(n log n)      | O(n)             | Efficient & widely used|

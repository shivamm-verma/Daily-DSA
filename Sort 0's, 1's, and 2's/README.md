# 🇳🇱 Dutch National Flag Algorithm 

## ✅ Problem Statement
Given an array consisting of only 0s, 1s, and 2s, sort the array in **ascending order** in-place and in **linear time** without using extra space.

---

## 🔍 Key Observations

- Only **three unique values**: {0, 1, 2}
- Can’t use built-in sort due to **O(n log n)** complexity
- In-place, single-pass (O(n)) solution is expected
- **Dutch flag Algo** is the optimal algorithm

---

## 💡 Algorithmic Strategy (Dutch Flag)

Approach:
- Use three pointers: low, mid, high
- Traverse the list once and rearrange values based on their category

Maintain three regions:

- `0 to low-1`: all 0s
- `low to mid-1`: all 1s
- `mid to high`: unknown zone
- `high+1 to end`: all 2s

Time Complexity: O(n)  – single pass
Space Complexity: O(1) – in-place sorting

---

## 🧾 Pseudocode

```plaintext
function mysort(arr):
    low ← 0
    mid ← 0
    high ← length(arr) - 1

    while mid ≤ high:
        if arr[mid] == 0:
            swap arr[low] and arr[mid]
            low ← low + 1
            mid ← mid + 1

        else if arr[mid] == 1:
            mid ← mid + 1

        else:
            swap arr[mid] and arr[high]
            high ← high - 1


This approach ensures optimal sorting of tri-valued arrays in linear time and constant space, making it ideal for real-time systems.
# 🐒 Koko Eating Bananas – DSA Problem

## 📝 Problem Statement

Koko loves to eat bananas. There are `n` piles of bananas, and the `i-th` pile has `piles[i]` bananas. The guards will return in `h` hours.

Koko can decide her eating speed `k` (bananas per hour). Every hour, she eats `k` bananas from a single pile. If the pile has less than `k` bananas, she eats all of them in that hour and does not continue that hour.

Koko wants to eat as slowly as possible, but must finish all bananas before the guards return.

---

## 🧩 Task

print the **minimum integer `k`** such that Koko can eat all the bananas within `h` hours.

---

## 📥 Input

- `piles[]`: array of integers (each representing a pile of bananas)
- `h`: integer representing total hours before the guards return

---

## 📤 Output

- Minimum integer `k` (bananas per hour) to eat all piles within `h` hours.

---

## 🧪 Examples

### Example 1
```
Input:  piles = [3, 6, 7, 11], h = 8  
Output: 4
```

### Example 2
```
Input:  piles = [30, 11, 23, 4, 20], h = 6  
Output: 23
```

---

## 💡 Brute Force Approach – Step-by-Step Explanation

We want to find the **minimum integer `k` (bananas per hour)** such that Koko can eat all the bananas in `h` hours.

Let’s take an example:

```
piles = [3, 6, 7, 11], h = 8
```

We know Koko wants to eat `k` bananas per hour.

---

### Try k = 1
- 1st pile (3 bananas): 3 hours  
- 2nd pile (6 bananas): 6 hours  
- 3rd pile (7 bananas): 7 hours  
- 4th pile (11 bananas): 11 hours  
**Total = 3 + 6 + 7 + 11 = 27 hours ❌**

---

### Try k = 3
- 1st pile (3 bananas): 1 hour  
- 2nd pile (6 bananas): 2 hours  
- 3rd pile (7 bananas): 3 hours  
- 4th pile (11 bananas): 4 hours  
**Total = 1 + 2 + 3 + 4 = 10 hours ❌**

---

### Try k = 4
- 1st pile (3 bananas): 1 hour  
- 2nd pile (6 bananas): 2 hours  
- 3rd pile (7 bananas): 2 hours  
- 4th pile (11 bananas): 3 hours  
**Total = 1 + 2 + 2 + 3 = 8 hours ✅**

---

### Try k = 5
- 1st pile: 1 hour, 2nd: 2 hours, 3rd: 2 hours, 4th: 3 hours  
**Total = 8 hours ✅**

---

### Try k = 6
- 1st pile: 1 hour, 2nd: 1 hour, 3rd: 2 hours, 4th: 2 hours  
**Total = 6 hours ✅**

---

So, for all `k >= 4`, she can eat all bananas in ≤ 8 hours.  
But the question asks for the **minimum possible `k`**, so we return:  
✅ **Answer = 4**

---

## ❌ Why Brute Force Fails

Let:
- `n = piles.length`
- `m = max(piles)`

Brute force checks all `k` from `1` to `m`, and for each `k` scans all `n` piles.

⛔ **Time Complexity** = O(n × max(piles)) → TLE for large inputs

---

## ⚡ Optimal Approach – Binary Search on Answer

We observed:

- If Koko **can** finish at `k`, then she can finish at any `k' > k`
- If Koko **cannot** finish at `k`, then she cannot finish at any `k' < k`

This makes the function **monotonic**:

```
F F F F T T T T ...
```

That’s a perfect case for **binary search on answer space**.

---

### 🎯 Binary Search Strategy

We binary search in the range `[1, max(piles)]`:

```java
low = 1
high = max(piles)

while (low < high):
    mid = (low + high) / 2
    if canFinish(mid):
        high = mid  // try smaller k
    else:
        low = mid + 1  // need higher k

return low
```

---

### 🔍 How canFinish(k) works

```java
int hours = 0;
for (int pile : piles) {
    hours += (pile + k - 1) / k;  // ceil(pile / k)
}
return hours <= h;
```

---

## ⏱️ Time and Space Complexity

| Approach        | Time Complexity                 | Space Complexity |
|----------------|----------------------------------|------------------|
| Brute Force     | O(n × max(piles))               | O(1)             |
| Binary Search   | O(n × log(max(piles)))          | O(1)             |

---

### ✅ Summary

- Brute Force gives intuition but is inefficient for large `piles` or `h`
- Binary Search leverages the **monotonic property** of `canFinish(k)`
- Much faster and optimal for constraints up to `1e9`
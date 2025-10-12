# Problem — Find Number of Ways to Reach the K-th Stair - Hard Problem

## Problem Summary

You are given a non-negative integer `k`.  
There is an infinite staircase with the lowest stair numbered `0`.

Suppose ,Alice starts on stair **1** with an initial `jump = 0`.  
She wants to reach stair **k** using the following two operations:

1. **Go Down:**  
   - Move from stair `i` → `i - 1`.  
   - ⚠️ Cannot be used **consecutively** or when `i = 0`.

2. **Go Up:**  
   - Move from stair `i` → `i + 2^jump`.  
   - After that, set `jump = jump + 1`.

Return the total **number of ways** Alice can reach stair `k`.

---

## Key Observations to be Noted

- Movement depends not only on **position** but also on the **current jump value**.
- Since down moves cannot be consecutive, we also need to track the **last move** type.
- Therefore, each *state* is described by **three parameters**.

---

## DP State Definition

Let
```
dp[i][jump][prevDown] = number of ways to reach stair i
                         with current jump = jump
                         and previous move was 'down' or not.
```

Where:
- `i` → current stair number
- `jump` → current jump value
- `prevDown` → 0 if previous move was up, 1 if previous move was down

---
## DP Transitions
1. **Go Up**
   ```
   nextStair = i + 2^jump
   dp[nextStair][jump + 1][0] += dp[i][jump][prevDown]
   ```

2. **Go Down** (only if previous move was not down)
   ```
   if prevDown == 0 and i > 0:
       dp[i - 1][jump][1] += dp[i][jump][prevDown]
   ```

---

## Base Case
```
dp[1][0][0] = 1  # Alice starts on stair 1 with jump = 0, last move not down
```
for solving this problem, i have used the recursion with memoization..
---

## Type and Category
| Aspect               |                        Type                                  |
|----------------------|--------------------------------------------------------------|
| **DP Dimension**     | 3D DP (`position`, `jump`, `prevDown`)                       |
| **Category**         | State-Transition DP / Simulation DP                          |
| **Pattern Type**     | DP with constrained transitions                              |
| **Related Problems** | Frog Jump , Number of Ways to Reach Target (LC 2585)         |

---

## ⏱️ Time and Space Complexity
Let `maxJump` ≈ `log2(k)` (since jump grows exponentially).

| Complexity  |    Value     |
|-------------|--------------|
| **Time**    | O(k * log k) |
| **Space**   | O(k * log k) |

---
## 🧩 Example
### Input
```
k = 3
```
### Possible Sequences
1. **Start(1, jump=0)** → Up → `(3, jump=1)` ✅  
   → Alice reached 3 directly.

2. **Start(1)** → Up → `(3)` → Down → `(2)` → Up → `(4)` → Down → `(3)` ✅  
   → Reached 3 again via multiple steps.

Hence, total ways = 2.
---

## 📘 Summary

| Concept            |                    Description                          |
|--------------------|---------------------------------------------------------|
| **Problem Type**   | DP with movement and state constraints                  |
| **DP Dimensions**  | 3 (position, jump, previous move)                       |
| **Main Challenge** | Non-consecutive down restriction & exponential up jumps |
| **Approach**       | State-transition DP                                     |
| **Complexity**     | O(k * log k)                                            |

---
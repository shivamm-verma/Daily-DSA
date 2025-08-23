# 🍬 Candy Distribution Problem

## 📝 Problem Statement

There are `n` children standing in a line, each with a rating value. You are to distribute candies to these children such that:

1. Each child must have at least one candy.
2. Children with a higher rating than their immediate neighbors must get more candies than those neighbors.

Return the **minimum number of candies** you must give to satisfy these conditions.

---

## 📊 Example

**Input:**  
`ratings = [1, 0, 2]`

**Output:**  
`5`

**Explanation:**  
- Child 1 (rating 1) → 2 candies  
- Child 2 (rating 0) → 1 candy  
- Child 3 (rating 2) → 2 candies  
Total = 2 + 1 + 2 = **5 candies**

---

## 🧠 Approach (Two-Pass Greedy)

### ✅ Step-by-Step Breakdown

1. **Initialize** a candies array of size `n` with all values set to `1`.
2. **Left to Right Pass**:  
   - If `ratings[i] > ratings[i-1]`, then `candies[i] = candies[i-1] + 1`.
3. **Right to Left Pass**:  
   - If `ratings[i] > ratings[i+1]`, then `candies[i] = max(candies[i], candies[i+1] + 1)`.
4. **Sum up** all values in the candies array to get the minimum required candies.

---

## ⏱️ Time and Space Complexity

| Metric            | Value         | Explanation                                      |
|-------------------|---------------|--------------------------------------------------|
| Time Complexity   | `O(n)`        | Two linear passes over the ratings array         |
| Space Complexity  | `O(n)`        | Extra array to store candies for each child      |

---

## 📌 Notes

- This is a classic greedy problem that benefits from a two-pass strategy.
- The left-to-right pass ensures increasing ratings get more candies.
- The right-to-left pass corrects any violations from the first pass.


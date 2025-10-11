# 🏛 Find the Town Judge

In a town, there are `n` people labeled from `1` to `n`.  
There is a rumor that one of these people is secretly the **town judge**.  

---

## 🔹 Conditions for the Town Judge
If the town judge exists, then:  

1. The judge **trusts nobody**.  
2. Everybody **(except for the judge)** trusts the judge.  
3. There is **exactly one** person that satisfies conditions 1 and 2.  

You are given an array `trust` where `trust[i] = [a, b]` means person `a` trusts person `b`.  
If a trust relationship does not exist in `trust`, then it doesn’t exist in the town.  

---

## 🔹 Task
Return the **label of the town judge** if they exist and can be identified, otherwise return `-1`.  

---

## 🔹 Examples

### Example 1
Input: n = 2, trust = [[1,2]]
Output: 2

### Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

### Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

### Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n

## 🔹 Pattern Identification
This problem is a **Graph / Indegree-Outdegree Problem**.
- Think of people as **nodes** in a graph.
- A trust relationship `a -> b` means a **directed edge** from `a` to `b`.

👉 To find the judge:
- Judge’s **outdegree = 0** (they trust nobody).
- Judge’s **indegree = n - 1** (everybody else trusts them).

This is the **indegree-outdegree difference pattern** often used in:
- **Celebrity Problem**
- **Graph Center / Universal Sink Problems**

---

## 🔹 Approach to Solve
1. Create two arrays:
    - `outdegree[i]` → how many people person `i` trusts.
    - `indegree[i]` → how many people trust person `i`.

2. Traverse the `trust` list:
    - For each pair `(a, b)` →
        - Increment `outdegree[a]`
        - Increment `indegree[b]`

3. After processing, check each person `i`:
    - If `outdegree[i] == 0` **and** `indegree[i] == n - 1` → `i` is the judge.

4. If no such person exists → return `-1`.

---

## 🔹 Time and Space Complexity
- **Time:** `O(n + trust.length)`
- **Space:** `O(n)`

---

✅ This is a **Graph Degree Checking** pattern.  
Memorize it as: **“Judge/Celebrity → Outdegree = 0, Indegree = n-1.”**
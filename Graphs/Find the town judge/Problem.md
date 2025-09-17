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
# ✅ DSA Question: Determine Top 2 Teams in a Champions League Group


## 🧠 Problem  
Given results of 12 football matches in a group of 4 teams, determine the top 2 ranked teams based on:  
1. **Points** (win = 3, draw = 1, loss = 0)  
2. **Goal Difference** (goals scored − goals conceded)  

No ties in top 2.

### 📌 Example
**Input:**
```
a 2 vs. 0 b
c 1 vs. 1 d
a 1 vs. 1 c
b 3 vs. 0 d
```

**Output:** `a b`

**Explanation:**
- `a`: 1 win, 1 draw → 4 pts, GD +2  
- `b`: 1 win, 1 loss → 3 pts, GD +1  
- `c`: 2 draws → 2 pts, GD 0  
- `d`: 1 draw, 1 loss → 1 pt, GD −3  

Top 2 teams by points and goal difference: **a** and **b**


## 🧭 Approach

1. Create a map for each team to track:  
   – `points`  
   – `goal difference`

2. For each match:  
   – Update goals scored and conceded  
   – Award points based on result

3. After all matches, sort teams by:  
   – Higher `points`  
   – Higher `goal difference` (if tied)

4. Return top 2 teams.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function getTopTeams(matches):
    teamStats = {}

    for match in matches:
        parse teamA, goalsA, goalsB, teamB
        update goals for both teams
        assign points based on result

    sort teams by points desc, then goalDiff desc
    return top 2 team names
```

## ⏱️ Complexities
> Time Complexity
O(n log n) — sorting 4 teams after match processing

> Space Complexity
O(1) — fixed number of teams



# Remove Duplicate Letters — Approaches Explained

## Problem Statement
Given a string `s`, remove duplicate letters so that every letter appears exactly once. You must make sure your result is the **smallest in lexicographical order** among all possible results.

## 📘 Example

### Input
```text
s = "bcabc"
Output: "abc"
```

### Another Example
```text
s = "cbacdcbc"
Output: "acdb"
```

### Visual Step-by-Step for "bcabc"
![Remove Duplicate Letters Animation](https://github.com/shivamm-verma/Daily-DSA/blob/main/29_Remove_Duplicate_letters/Explaination.gif)

**Why "abc" and not "bca"?**
- Both contain each letter exactly once
- "abc" < "bca" lexicographically, so "abc" is the answer

---

## Approach (Monotonic Stack)

### Idea
- Use a **monotonic stack** to maintain lexicographically smallest result
- Keep track of:
  - `last_index`: Last occurrence of each character
  - `seen`: Characters already included in result
  - `stack`: Current result being built

### Algorithm Steps
1. **Preprocessing**: Record the last index of each character
2. **Process each character**:
   - Skip if already seen (avoid duplicates)
   - **Pop from stack** if:
     - Stack top > current character (maintain lexicographical order)
     - Stack top appears later in string (we can use it later)
   - Add current character to stack and mark as seen

### Why Optimal?
- **Single Pass**: Processes string only once
- **Smart Backtracking**: Uses stack to "undo" suboptimal choices
- **Lexicographical Guarantee**: Monotonic stack ensures smallest order
- **Duplicate Handling**: `seen` set prevents duplicates efficiently

### Visual Example for "bcabc"
```text
Step | Char | Stack | Seen | Action
-----|------|-------|------|--------
1    | b    | [b]   | {b}  | Add b
2    | c    | [b,c] | {b,c}| Add c  
3    | a    | [a]   | {a}  | Pop c,b (both appear later), add a
4    | b    | [a,b] | {a,b}| Add b (a < b, so keep a)
5    | c    | [a,b,c]|{a,b,c}| Add c
```

### Complexity
- **Time**: O(n) - each character pushed/popped at most once
- **Space**: O(1) - stack size bounded by alphabet size (26)



## 🔑 Key Insights

### Why Monotonic Stack Works
- **Monotonic Property**: Stack maintains increasing lexicographical order
- **Future Opportunity**: Only remove characters if they appear later
- **Greedy Choice**: Always prefer smaller characters when possible

### Edge Cases Handled
- Single character strings
- All characters unique
- All characters same
- Reverse lexicographical order input

### Pattern Recognition
This problem combines several algorithmic patterns:
- **Monotonic Stack**: For maintaining order while allowing removals
- **Greedy Algorithm**: Making locally optimal choices
- **Hash Map/Array**: For O(1) lookups of character positions


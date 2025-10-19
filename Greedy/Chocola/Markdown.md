# 🍫 Chocola Problem (Minimum Cost to Cut Chocolate)

## 📌 Problem Statement

You are given a chocolate bar of size **n × m**.  
The bar needs to be cut into **1×1 squares**.

- Each cut has a cost associated with it.
- There are **horizontal cuts** (**costHor**) and **vertical cuts** (**costVer**).
- When making a cut, the cost is multiplied by the **number of pieces in the perpendicular direction**.

Your task is to **minimize the total cost** to cut the entire chocolate into squares.

This is a **classic greedy algorithm problem**.

---

## ✅ Example

### Input

```
Number of horizontal cuts (n-1): 3
Horizontal cut costs: 4 1 2
Number of vertical cuts (m-1): 5
Vertical cut costs: 2 1 3 1 4
```

### Output

```
Minimum cost to cut the chocolate: 42
```

---

## 🔎 Steps to Solve

1. Sort **horizontal cut costs** (**costHor**) in descending order.
2. Sort **vertical cut costs** (**costVer**) in descending order.
3. Initialize pointers and counters:
   - **h = 0, v = 0** → current horizontal/vertical cut index
   - **hp = 1, vp = 1** → number of horizontal/vertical pieces
4. While both arrays have cuts remaining:
   - Compare **costHor[h]** and **costVer[v]**.
   - If **costHor[h] >= costVer[v]**:
     - Add **costHor[h] \* vp** to total cost.
     - Increment **h** and **hp**.
   - Else:
     - Add **costVer[v] \* hp** to total cost.
     - Increment **v** and **vp**.
5. Add remaining horizontal cuts: multiply each by current **vp**.
6. Add remaining vertical cuts: multiply each by current **hp**.
7. Return total cost.

**This greedy approach ensures that the largest cuts are done first**, reducing multiplication by the number of pieces and minimizing total cost.

---

## ⏱️ Time Complexity

- Sorting horizontal and vertical costs: **O(n log n + m log m)**
- Linear traversal to combine cuts: **O(n + m)**
- **Total:** `O(n log n + m log m)`

---

## 💾 Space Complexity

- **O(1)** → Only a few extra variables (**h**, **v**, **hp**, **vp**, **cost**)
- Sorting uses minimal extra memory depending on language implementation.

---

## 💻 Implementations

You can implement this problem in multiple languages:

- **Java:** **Chocola.java**
- **C:** **chocola.c**
- **C++:** **Chocola.cpp**
- **Python:** **chocola.py**
- **JavaScript:** **chocola.js**

> Each implementation follows the same greedy logic outlined above.

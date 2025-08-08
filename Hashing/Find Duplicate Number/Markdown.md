# 🔍 Find the Duplicate Number — Array Problem

## 🧾 Problem Statement
Given an array of `n` integers where each number is between `1` and `n - 1`, and exactly **one number is duplicated**, find and return the duplicate.

---

## 🧠 Example

**Input:**
n = 5 nums = [1, 3, 4, 2, 2]

**Output:**
2

---

## 🧩 Approach

- Use a **set** or **hash structure** to track seen numbers.
- Iterate through the array:
  - If a number is already in the set, it's the duplicate.
  - Otherwise, insert it into the set.
- Return the duplicate when found.

---

## 📈 Time Complexity
O(n)

- Single pass through the array

---

## 🧠 Space Complexity
O(n)

- For storing seen elements in a set or hash table

---

## 📌 Topics Covered

- Arrays  
- Hashing  
- Duplicate Detection  
- Set/Map Usage

---







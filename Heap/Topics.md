# 🏔️ Heap - Topics and Problems

## 📚 Table of Contents
- [What is a Heap?](#what-is-a-heap)
- [Types of Heaps](#types-of-heaps)
- [Time Complexities](#time-complexities)
- [Why Use Heaps?](#why-use-heaps)
- [Heap Properties](#heap-properties)
- [Built-in Functions (Python)](#built-in-functions-python)


---

## 💡 What is a **Heap**?

A **heap** is a **special tree-based data structure** that satisfies the **heap property**.

### ✅ Types of Heaps

#### 1. **Min-Heap**:
- Every parent node is **less than or equal to** its children
- The **smallest** element is always at the root

#### 2. **Max-Heap**:
- Every parent node is **greater than or equal to** its children  
- The **largest** element is always at the root

---

## ⏱️ Time Complexities

| Operation     | Time Complexity |
| ------------- | --------------- |
| Insert        | O(log n)        |
| Delete (Root) | O(log n)        |
| Peek (Root)   | O(1)            |
| Build Heap    | O(n)            |

---

## 📦 Why Use Heaps?

Heaps are **efficient** when you want to:

- Continuously access the **highest** or **lowest** priority item
- Implement **priority queues**
- Sort elements efficiently (Heap Sort)
- Handle streaming or dynamic data

### 🎯 Common Use Cases:
- K largest/smallest elements
- Median of data stream  
- Merging k sorted arrays/lists
- Task scheduling (OS or event management)
- Graph algorithms (Dijkstra's, A*)

---

## 🧠 Heap Properties

### 1. **Complete Binary Tree**:
- All levels are full except possibly the last
- Last level is filled **from left to right**

### 2. **Heap Property**:
- **Min-heap**: `parent ≤ children`
- **Max-heap**: `parent ≥ children`

### 3. **Array Implementation**:
- Usually implemented as an **array**, not using tree nodes
- No pointers needed to children

**Array Index Mapping** (0-based):
- Parent: `i`
- Left child: `2i + 1`  
- Right child: `2i + 2`
- Parent of node at `i`: `(i - 1) // 2`

---

## 🔧 Built-in Functions (Python)

Python provides the `heapq` module for **Min Heap** functionality:

### Basic Operations
```python
import heapq

# Initialize empty heap
heap = []

# Push values
heapq.heappush(heap, 5)
heapq.heappush(heap, 1) 
heapq.heappush(heap, 3)

# Peek at smallest
print(heap[0])  # Output: 1

# Pop smallest
print(heapq.heappop(heap))  # Output: 1
```

### Max Heap Implementation
```python
import heapq

# Use negative values for max heap
max_heap = []
nums = [1, 5, 3, 10]

for num in nums:
    heapq.heappush(max_heap, -num)

# Pop max (smallest negative)
print(-heapq.heappop(max_heap))  # Output: 10
```

### Essential Functions

| Function | Purpose |
|----------|---------|
| `heapq.heappush(heap, x)` | Push `x` into heap |
| `heapq.heappop(heap)` | Pop and return smallest item |
| `heapq.heapify(list)` | Convert list into heap |
| `heapq.heappushpop(heap, x)` | Push then pop in one step |
| `heapq.heapreplace(heap, x)` | Pop then push (faster) |
| `heapq.nlargest(k, iterable)` | Return k largest elements |
| `heapq.nsmallest(k, iterable)` | Return k smallest elements |

---


## 🚀 Learning Path

1. **Start with Basics**
   - Understand heap properties
   - Learn array representation
   - Practice basic operations

2. **Master Built-in Functions**
   - Use `heapq` module in Python
   - Practice with simple problems
   - Understand min vs max heap

3. **Solve Problem Categories**
   - Begin with Top-K problems
   - Move to streaming data problems
   - Practice merge operations

4. **Advanced Topics**
   - Implement heap sort
   - Learn about other heap types
   - Practice complex applications

---

## 💭 Key Insights

- **Priority Queue** is a **concept**, **Heap** is the **implementation**
- Heaps are perfect for problems requiring repeated min/max access
- For large n (up to 10^9), heap-based approaches become more efficient than sorting
- Always consider heap when you see "K largest/smallest" in problem statements

---

## 📖 Additional Resources

- [Python heapq Documentation](https://docs.python.org/3/library/heapq.html)
- [GeeksforGeeks Heap Tutorial](https://www.geeksforgeeks.org/heap-data-structure/)
- [LeetCode Heap Problems](https://leetcode.com/tag/heap-priority-queue/)

---

**Happy Coding! 🎉**
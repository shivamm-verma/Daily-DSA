# 📦 Min Stack

## 📝 Problem Statement

Design a stack that supports the following operations in **O(1)** time:

- `void push(int val)`
- `void pop()`
- `int top()`
- `int getMin()` — retrieves the minimum element in the stack

---

## 🧠 Approach

We use **two stacks**:

- One to store all values.
- Another to store the current minimum at each step.

Whenever an element is pushed:

- If it's smaller than or equal to the current min, push to min stack.

On pop:

- If the element being popped is the current min, pop from min stack as well.

---

## 💻 Available Code

- [`min_stack.cpp`](./min_stack.cpp) - C++
- [`min_stack.java`](./min_stack.java) - Java
- [`min_stack.py`](./min_stack.py) - Python

---

## 📊 Complexity

| Operation  | Time | Space |
| ---------- | ---- | ----- |
| `push()`   | O(1) | O(n)  |
| `pop()`    | O(1) | O(n)  |
| `top()`    | O(1) | O(1)  |
| `getMin()` | O(1) | O(1)  |

---

## 📌 Example

```java
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // returns -3
minStack.pop();
minStack.top();    // returns 0
minStack.getMin(); // returns -2
```

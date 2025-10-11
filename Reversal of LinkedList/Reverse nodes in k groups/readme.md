
---

# 📂 File 2: `reverse_nodes_in_k_group.md`

```markdown
# Reverse Nodes in k-Group (LeetCode 25)

## Description
Given a linked list, reverse the nodes of the list `k` at a time and return its modified list.  
If the number of nodes is not a multiple of `k`, the remaining nodes are left as-is.

---

## Constraints
- Number of nodes: `[1, 5000]`
- `0 <= Node.val <= 1000`
- `1 <= k <= length of list`

---

## Test Cases
```text
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


## Tips to Identify Pattern

Break problem into:

Reverse first k nodes.

Recursively process rest.

Iterative approach uses dummy node and pointer manipulation.
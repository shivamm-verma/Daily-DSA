# Binary Tree Right Side View

## Problem Statement

Given the root of a binary tree, return the values of the nodes you can see ordered from top to bottom when looking at the tree from the right side.

**Constraints:**
- The number of nodes in the tree is in the range `[0, 100]`
- `-100 <= Node.val <= 100`

## Explanation

To solve this problem, we perform a level-order traversal (BFS) of the tree. At each level, the rightmost node is the one visible from the right side. We collect these nodes and return them as the result.

The key insight is that when we look at a binary tree from the right side, we can only see:
- The root node
- The rightmost node at each subsequent level

## Examples

### Example 1
**Input:**
```
   1
  / \
 2   3
/     \
4      5
```

**Output:** `[1, 3, 5]`

**Explanation:**  
- Level 0: Node `1` is visible from the right
- Level 1: Node `3` is the rightmost node (even though `2` exists, it's blocked by `3`)
- Level 2: Node `5` is the rightmost node (node `4` is blocked by `5`)

### Example 2
**Input:**
```
  1
 / \
2   3
\   \
5   4
```

**Output:** `[1, 3, 4]`

**Explanation:**  
- Level 0: Node `1` is visible from the right
- Level 1: Node `3` is the rightmost node
- Level 2: Node `4` is the rightmost node (node `5` is blocked by `4`)

### Example 3 (Edge Cases)
**Single node:**
```
1
```
**Output:** `[1]`

**Empty tree:**
```
null
```
**Output:** `[]`

**Left-skewed tree:**
```
  1
 /
2
/
3
```
**Output:** `[1, 2, 3]` (Each level has only one node, so it's always visible)

## Visual Representation

```
Original Tree (side view):        Right Side View:
       1                              1  ← Level 0
      / \                             3  ← Level 1  
     2   3                            5  ← Level 2
    /     \
   4       5
```

From the right side, nodes `2` and `4` are hidden behind nodes `3` and `5` respectively.

## Algorithm Steps

1. **Initialize**: Create an empty result array and a queue for BFS
2. **Base Case**: If root is null, return empty array
3. **Level Processing**: 
   - For each level, process all nodes currently in the queue
   - Keep track of the level size to know when a level ends
   - Add children (left first, then right) to queue for next level
   - The last node processed in each level is the rightmost visible node
4. **Result**: Return the collected rightmost nodes

## Time Complexity

- **O(N)**, where N is the number of nodes in the tree
- **Reasoning**: Each node is visited exactly once during the level-order traversal

## Space Complexity

- **O(W)**, where W is the maximum width of the tree
- **Reasoning**: 
  - The queue stores at most W nodes (the maximum number of nodes at any level)
  - In the worst case (perfect binary tree), W = N/2
  - The result array stores at most H elements (height of tree)
  - Overall: O(W) where W ≤ N

## Edge Cases Handled

- **Empty tree**: Returns `[]`
- **Single node**: Returns `[root.val]`
- **Left-skewed tree**: Each level has one node, all are visible
- **Right-skewed tree**: Each level has one node, all are visible
- **Perfect binary tree**: Only rightmost nodes are visible
- **Nodes with same values**: Algorithm works based on position, not value

## Related Problems

- **Binary Tree Left Side View**: Similar approach, but take the first node of each level
- **Binary Tree Level Order Traversal**: Foundation technique used in this problem
- **Binary Tree Zigzag Level Order Traversal**: Advanced level-order traversal pattern

## Notes

- This problem is a classic example of **level-order traversal** application
- The BFS approach is preferred over DFS for its intuitive nature
- Can be solved with DFS as well, but BFS is more straightforward for this specific problem
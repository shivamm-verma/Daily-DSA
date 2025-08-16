# Count Good Nodes in Binary Tree

## Problem Statement
Given the root of a binary tree, a node X is considered good if on the path from the root to X, there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

## Approaches

1. Recursive DFS (Top-Down with Max Tracking)

Keep track of the maximum value seen so far (mx) on the path from root to current node.

At each node, check if node->val >= mx. If yes, count it as a good node.

Recurse left and right while updating mx.

Time Complexity: $$O(N)$$ (visit each node once)
Space Complexity: $$O(H)$$ (recursion stack, where H is tree height; worst-case O(N) for skewed tree)

2. Iterative DFS using Stack

Use an explicit stack storing {node, mx}.

Similar logic to recursive DFS, but avoids recursion.

Pop nodes from stack, update answer, and push children with updated mx.

Time Complexity: $$O(N)$$
Space Complexity: $$O(H)$$ (stack size; up to O(N) worst-case)

3. BFS using Queue

Use a queue for level-order traversal while tracking {node, mx}.

For each node, check if it’s good, update mx, and push children into queue.

Processes nodes breadth-first but logic is same.

Time Complexity: $$O(N)$$
Space Complexity: $$O(W)$$ (queue size; W = max width of tree, up to O(N))
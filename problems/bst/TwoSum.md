##  Two Sum in a BST — Approaches Explained
###  Problem Statement
Given a  `root` of a Binary Search Tree (BST) and an integer `k`, determine if there exist two nodes such that their values add up to `k`.
### 📘 Example

#### Input

```text
BST Elements (level-order input): 10, 5, 15, 3, 7, null, 18  
Target Sum (k): 22
output : True 
The valid pairs are (7,15)
```
#### Visual Diagram
```text
         10
        /  \
       5    15
      / \     \
     3   7     18
```


### 1️⃣ Brute Force Approach (Level Order + Sorting + Two Pointers)
#### Idea
- Traverse the BST in level order and store all node values.

- Sort the list.

- Use two pointers to check if any pair sums up to k.

#### Complexity
- Time: O(n log n) (due to sorting)

- Space: O(n) (storing the values)

#### Code Base
Used in:
✔️ C++ (Level Order)
✔️ Java / Python equivalent provided

### Better Approach (Using Hash Set)
#### Idea
- Perform inorder traversal of the BST to get a sorted array of values.

- Use the two-pointer technique to check if any pair sums to k.


#### Advantage
- No sorting needed.


#### Complexity
- Time: O(n)

- Space: O(n)

#### Code Base
Used in:
✔️ C++ 
✔️ Java 
✔️ Python

#### Optimal Approach (Hash set)
#### Idea
- Use a hash set to store values.

- While traversing the tree, check if the complement k - node->val exists in the set.

- This avoids extra space for sorting and supports early exit.

#### Why Optimal?
No need for hashing or external sort.

#### Complexity
- Time: O(n)

- Space: O(n)

#### Code Base
Used in:
✔️ C++ 
✔️ Java & Python equivalents

---

## Code 
Brute
### Java
```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTTargetSum {

    public static void insertBST(TreeNode root, int val) {
        if (val < root.val) {
            if (root.left == null) root.left = new TreeNode(val);
            else insertBST(root.left, val);
        } else {
            if (root.right == null) root.right = new TreeNode(val);
            else insertBST(root.right, val);
        }
    }

    public static boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;

        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> values = new ArrayList<>();
        q.add(root);

        // BFS to collect node values
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            values.add(node.val);
            if (node.left != null) q.add(node.left);
            if (node.right != null) q.add(node.right);
        }

        Collections.sort(values); // two-pointer
        int i = 0, j = values.size() - 1;
        while (i < j) {
            int sum = values.get(i) + values.get(j);
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter target sum k: ");
        int k = sc.nextInt();

        System.out.println("Enter values for BST (type non-integer to stop):");
        TreeNode root = null;
        while (sc.hasNextInt()) {
            int val = sc.nextInt();
            if (root == null) root = new TreeNode(val);
            else insertBST(root, val);
        }

        if (findTarget(root, k))
            System.out.println("True: A pair exists with the given sum.");
        else
            System.out.println("False: No such pair exists.");
    }
}

```

### Python

```python 
from collections import deque

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

def find_target(root, k):
    if not root:
        return False

    queue = deque([root])
    values = []

    # Level-order traversal
    while queue:
        node = queue.popleft()
        values.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

    values.sort()
    i, j = 0, len(values) - 1
    while i < j:
        total = values[i] + values[j]
        if total == k:
            return True
        elif total < k:
            i += 1
        else:
            j -= 1
    return False

if __name__ == "__main__":
    k = int(input("Enter target sum k: "))
    print("Enter values for BST (press Ctrl+D or Ctrl+Z to end):")

    root = None
    try:
        while True:
            val = input()
            if not val.strip():
                break
            root = insert_bst(root, int(val))
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")

```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool find_target(TreeNode* root, int k) {
    queue<TreeNode*> q; // used to push node in level order
    vector<int> values;
    if (!root) return false;

    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        values.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    sort(values.begin(), values.end()); // sort the values to use two-pointer technique
    int i = 0, j = values.size() - 1;
    while (i < j) {
        int sum = values[i] + values[j];
        if (sum == k) return true;//
        else if (sum < k) i++; //move the left pointer to increase the sum
        else j--; //move the right pointer to decrease the sum
    }
    return false;
}

void insertBST(TreeNode*& root, int val) {
    if (!root) { // if the tree is empty, create a new node
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) insertBST(root->left, val);// if the value is less than the root, insert in the left subtree
    else insertBST(root->right, val);// if the value is greater than or equal to the root, insert in the right subtree
}

int main() {
    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    cout << "Enter values for BST :" << endl;

    int n;
    TreeNode* root = nullptr;

    while (cin >> n) {
        insertBST(root, n);
    }

    if (find_target(root, k))
        cout << "True: A pair exists with the given sum." << endl;
    else
        cout << "False: No such pair exists." << endl;

    return 0;
}

```
---
Better

### Java
```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTTargetSumInorder {

    public static TreeNode insertBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insertBST(root.left, val);
        else root.right = insertBST(root.right, val);
        return root;
    }

    public static void inorder(TreeNode root, List<Integer> values) {
        if (root == null) return;
        inorder(root.left, values);
        values.add(root.val);
        inorder(root.right, values);
    }

    public static boolean findTarget(TreeNode root, int k) {
        List<Integer> values = new ArrayList<>();
        inorder(root, values);

        int i = 0, j = values.size() - 1;
        while (i < j) {
            int sum = values.get(i) + values.get(j);
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter target sum k: ");
        int k = sc.nextInt();

        System.out.println("Enter values for BST (type non-integer to stop):");
        TreeNode root = null;
        while (sc.hasNextInt()) {
            int val = sc.nextInt();
            root = insertBST(root, val);
        }

        if (findTarget(root, k))
            System.out.println("True: A pair exists with the given sum.");
        else
            System.out.println("False: No such pair exists.");
    }
}

```

### Python 
```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

def inorder(root, values):
    if not root:
        return
    inorder(root.left, values)
    values.append(root.val)
    inorder(root.right, values)

def find_target(root, k):
    values = []
    inorder(root, values)
    i, j = 0, len(values) - 1
    while i < j:
        total = values[i] + values[j]
        if total == k:
            return True
        elif total < k:
            i += 1
        else:
            j -= 1
    return False

if __name__ == "__main__":
    k = int(input("Enter target sum k: "))
    print("Enter values for BST (Ctrl+D or Ctrl+Z to end):")
    root = None
    try:
        while True:
            line = input()
            if not line.strip(): break
            root = insert_bst(root, int(line))
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")

```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertBST(TreeNode*& root, int val) {
    if (!root) { // if the tree is empty, create a new node
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) insertBST(root->left, val);// if the value is less than the root, insert in the left subtree
    else insertBST(root->right, val);// if the value is greater than or equal to the root, insert in the right subtree
}

void inorder(TreeNode* root, vector<int>& values) {
    if (!root) return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

bool find_target(TreeNode* root, int k) {
    vector<int> values;
    if(!root) return false;
    inorder(root, values); // Get all values in sorted order using inorder traversal
    int i = 0, j = values.size() - 1;
    while (i < j) {
        int sum = values[i] + values[j];
        if (sum == k) return true; // Found the pair
        else if (sum < k) i++; // Move left pointer to increase sum
        else j--; // Move right pointer to decrease sum
    }

    return false;
}



int main() {
    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    cout << "Enter values for BST :" << endl;

    int n;
    TreeNode* root = nullptr;

    while (cin >> n) {
        insertBST(root, n);
    }

    if (find_target(root, k))
        cout << "True: A pair exists with the given sum." << endl;
    else
        cout << "False: No such pair exists." << endl;

    return 0;
}

```
---
Optimal

### Java
```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTTargetSum {

    public static void insertBST(TreeNode root, int val) {
        if (val < root.val) {
            if (root.left == null) root.left = new TreeNode(val);
            else insertBST(root.left, val);
        } else {
            if (root.right == null) root.right = new TreeNode(val);
            else insertBST(root.right, val);
        }
    }

    public static boolean hashFind(TreeNode root, int k, Set<Integer> seen) {
        if (root == null) return false;

        if (seen.contains(k - root.val)) return true;
        seen.add(root.val);

        return hashFind(root.left, k, seen) || hashFind(root.right, k, seen);
    }

    public static boolean findTarget(TreeNode root, int k) {
        Set<Integer> seen = new HashSet<>();
        return hashFind(root, k, seen);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter target sum k: ");
        int k = sc.nextInt();

        System.out.println("Enter values for BST (type non-integer to end):");

        TreeNode root = null;
        while (sc.hasNextInt()) {
            int val = sc.nextInt();
            if (root == null) root = new TreeNode(val);
            else insertBST(root, val);
        }

        if (findTarget(root, k))
            System.out.println("True: A pair exists with the given sum.");
        else
            System.out.println("False: No such pair exists.");
    }
}

```

### Python 
```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

def hash_find(root, k, seen):
    if not root:
        return False
    if (k - root.val) in seen:
        return True
    seen.add(root.val)
    return hash_find(root.left, k, seen) or hash_find(root.right, k, seen)

def find_target(root, k):
    return hash_find(root, k, set())

if __name__ == "__main__":
    k = int(input("Enter target sum k: "))
    print("Enter values for BST (press Ctrl+D or Ctrl+Z to end):")

    root = None
    try:
        while True:
            n = input()
            if not n.strip():
                break
            val = int(n)
            root = insert_bst(root, val)
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")
```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertBST(TreeNode*& root, int val) {
    if (!root) { // if the tree is empty, create a new node
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) insertBST(root->left, val);// if the value is less than the root, insert in the left subtree
    else insertBST(root->right, val);// if the value is greater than or equal to the root, insert in the right subtree
}

bool hash_find(TreeNode* root,int k,set<int>& s) {
    if (!root) return false;
    if (s.find(k-root->val)!=s.end()) return true; // Check if the complement exists in the set
    s.insert(root->val); // Insert current node's value into the set
    return hash_find(root->left, k, s) || hash_find(root->right, k, s); // Recur for left and right subtrees
}
bool find_target(TreeNode* root, int k) {
    set<int> s;
    return hash_find(root, k, s);
}



int main() {
    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    cout << "Enter values for BST :" << endl;

    int n;
    TreeNode* root = nullptr;

    while (cin >> n) {
        insertBST(root, n);
    }

    if (find_target(root, k))
        cout << "True: A pair exists with the given sum." << endl;
    else
        cout << "False: No such pair exists." << endl;

    return 0;
}

```
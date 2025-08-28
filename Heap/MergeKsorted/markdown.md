# Merge k Sorted Lists

## Problem Statement  
You are given an array of `k` linked-lists, each linked-list is sorted in **ascending order**.  

**Merge all the linked-lists into one sorted linked-list and return it.**

---

### Example 1:
**Input:**  
lists = [[1,4,5],[1,3,4],[2,6]]

**Output:**  
[1,1,2,3,4,4,5,6]   

**Explanation:**  
The linked-lists are:  
1 -> 4 -> 5
1 -> 3 -> 4
2 -> 6
Merging them into one sorted list:  
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6


---

### Example 2:
**Input:** 
lists = []

**Output:** 
[]

---

### Example 3:
**Input:** 
lists = [[]]

**Output:**
[]

---

## Constraints:
- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- The lists are **sorted** in **non-decreasing** order.

---

# Approaches

## **Approach 1: Brute Force**
### **Idea**  
1. Traverse all the linked lists and collect all the node values.  
2. Sort all the values.  
3. Build a new sorted linked list from these sorted values.  

---

### **C++ Solution (Brute Force)**

```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nums;
    for (auto list : lists) {
        while (list) {
            nums.push_back(list->val);
            list = list->next;
        }
    }
    
    sort(nums.begin(), nums.end());
    
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy.next;
}

int main() {
    // Example: [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = mergeKLists(lists);

    cout << "Merged List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
```

### **Java Solution (Brute Force)**
```java 
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class MergeKListsBruteForce {
    public static ListNode mergeKLists(ListNode[] lists) {
        List<Integer> nums = new ArrayList<>();
        
        for (ListNode list : lists) {
            while (list != null) {
                nums.add(list.val);
                list = list.next;
            }
        }
        
        Collections.sort(nums);
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        for (int num : nums) {
            curr.next = new ListNode(num);
            curr = curr.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        // Example: [[1,4,5],[1,3,4],[2,6]]
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(5);

        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        ListNode l3 = new ListNode(2);
        l3.next = new ListNode(6);

        ListNode[] lists = { l1, l2, l3 };
        ListNode result = mergeKLists(lists);

        System.out.print("Merged List: ");
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
```

## Complexity Analysis (Brute Force)

**Time Complexity:** O(N log N)

N = total number of nodes across all lists.

Collecting all values → O(N)

Sorting → O(N log N)

Building linked list → O(N)

**Space Complexity:** O(N) for storing node values.

## Approach 2: Optimized (Min-Heap / Priority Queue)
**Idea**

- Use a min-heap to always extract the smallest node among the k lists.

- Push the first node of each list into the heap.

- Pop the smallest node, attach it to the result list, and push its next node into the heap.

## **C++ Solution (Optimized)**
```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
    for (auto list : lists) {
        if (list) pq.push(list);
    }
    
    ListNode dummy(0);
    ListNode* curr = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        curr->next = node;
        curr = curr->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

int main() {
    // Example: [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = mergeKLists(lists);

    cout << "Merged List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
```

## **Java Solution (Optimized)**   
```java 
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class MergeKListsOptimized {
    public static ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));
        
        for (ListNode list : lists) {
            if (list != null) pq.add(list);
        }
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            curr.next = node;
            curr = curr.next;
            if (node.next != null) pq.add(node.next);
        }
        
        return dummy.next;
    }

    public static void main(String[] args) {
        // Example: [[1,4,5],[1,3,4],[2,6]]
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(5);

        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        ListNode l3 = new ListNode(2);
        l3.next = new ListNode(6);

        ListNode[] lists = { l1, l2, l3 };
        ListNode result = mergeKLists(lists);

        System.out.print("Merged List: ");
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
```

## Complexity Analysis (Optimized)

Time Complexity: O(N log k)

N = total number of nodes

k = number of lists

Each insertion & extraction from heap → O(log k)

Space Complexity: O(k) for the heap. 

## Summary Table
| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute Force | `O(N log N)`    | `O(N)`           |
| Min-Heap    | `O(N log k)`    | `O(k)`           |

**Problem Link:** [LeetCode - Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)

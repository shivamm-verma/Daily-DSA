# 121. Best Time to Buy and Sell Stock

## Problem Statement

**Difficulty:** Easy  
**Topics:** Array, Dynamic Programming  
**Companies:** Amazon, Microsoft, Apple, Google, Facebook

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

## Examples

### Example 1

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

### Example 3

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
```

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Solutions

### Approach 1: Brute Force (Not Recommended)

**Intuition:** Check every possible pair of buy and sell days.

**Algorithm:**
- For each day i, consider buying on day i
- For each day j > i, consider selling on day j
- Track the maximum profit

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

### Approach 2: One Pass (Optimal Solution)

**Intuition:** We need to find the maximum difference between any two prices where the selling price comes after the buying price. The key insight is to keep track of the minimum price seen so far and calculate profit at each step.

**Algorithm:**

1. Keep track of the minimum price seen so far
2. For each price, calculate the profit if we sell at that price  
3. Update the maximum profit if current profit is greater

**Time Complexity:** O(n) - Single pass through the array  
**Space Complexity:** O(1) - Only using constant extra space

### Step-by-Step Walkthrough

1. **Initialize:**
   - `minPrice` = first price
   - `maxProfit` = 0

2. **For each subsequent price:**
   - Update `minPrice` to be the minimum of current `minPrice` and current price
   - Calculate profit = current price - `minPrice`
   - Update `maxProfit` if current profit is greater

3. **Return** `maxProfit`

### Dry Run Example

For `prices = [7,1,5,3,6,4]`:

| Day | Price | Min Price | Profit | Max Profit |
|-----|-------|-----------|--------|------------|
| 0   | 7     | 7         | 0      | 0          |
| 1   | 1     | 1         | 0      | 0          |
| 2   | 5     | 1         | 4      | 4          |
| 3   | 3     | 1         | 2      | 4          |
| 4   | 6     | 1         | 5      | 5          |
| 5   | 4     | 1         | 3      | 5          |

Result: Maximum profit = 5

## LeetCode-Style Solutions

### C++ Solution

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};
```

### Java Solution

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.length; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
}
```

### Python Solution

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        min_price = prices[0]
        max_profit = 0
        
        for price in prices[1:]:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)
        
        return max_profit
```

## Implementation Files

- **C++:** `C++_code.cpp` - Complete implementation with test cases
- **Java:** `Java_code.java` - Complete implementation with test cases  
- **Python:** `Python_code.py` - Complete implementation with test cases

## Key Insights

- **Core Concept:** Find maximum difference between two array elements where the larger element comes after the smaller one
- **Optimization:** Instead of checking all pairs O(n²), track minimum price seen so far O(n)
- **Edge Cases:** Empty array, single element, decreasing prices (no profit possible)
- **Real-world Application:** This problem models optimal trading strategy with single transaction

## Common Mistakes

1. **Selling before buying:** Remember you must buy before you sell
2. **Multiple transactions:** This problem allows only ONE buy and ONE sell
3. **Negative profit:** If no profit is possible, return 0 (not negative values)

## Follow-up Questions

1. **What if you could complete multiple transactions?** → Best Time to Buy and Sell Stock II
2. **What if you could complete at most 2 transactions?** → Best Time to Buy and Sell Stock III  
3. **What if there was a cooldown period?** → Best Time to Buy and Sell Stock with Cooldown
4. **What if there was a transaction fee?** → Best Time to Buy and Sell Stock with Transaction Fee

## Related LeetCode Problems

- [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) (Medium)
- [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) (Hard)
- [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) (Hard)
- [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) (Medium)
- [714. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) (Medium)

---

**Tags:** `Array` `Dynamic Programming` `Greedy` `Two Pointers`  
**Difficulty:** Easy  
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

# LeetCode Solution - Ready to submit
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

"""
# Alternative solution with more explicit comments
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) < 2:
            return 0
        
        min_price = prices[0]   # Track minimum price seen so far
        max_profit = 0          # Track maximum profit achievable
        
        for i in range(1, len(prices)):
            # Update minimum price seen so far
            min_price = min(min_price, prices[i])
            
            # Calculate profit if we sell at current price
            current_profit = prices[i] - min_price
            
            # Update maximum profit
            max_profit = max(max_profit, current_profit)
        
        return max_profit
"""

# For local testing
if __name__ == "__main__":
    from typing import List
    
    def main():
        """Test the solution with different test cases"""
        solution = Solution()
        
        # Test case 1
        prices1 = [7, 1, 5, 3, 6, 4]
        print("Test case 1: [7,1,5,3,6,4]")
        print(f"Maximum profit: {solution.maxProfit(prices1)}")
        
        # Test case 2
        prices2 = [7, 6, 4, 3, 1]
        print("\nTest case 2: [7,6,4,3,1]")
        print(f"Maximum profit: {solution.maxProfit(prices2)}")
        
        # Test case 3
        prices3 = [1, 2, 3, 4, 5]
        print("\nTest case 3: [1,2,3,4,5]")
        print(f"Maximum profit: {solution.maxProfit(prices3)}")
        
        # Test case 4 - Edge case
        prices4 = [1]
        print("\nTest case 4: [1]")
        print(f"Maximum profit: {solution.maxProfit(prices4)}")
        
        # Test case 5 - Empty array
        prices5 = []
        print("\nTest case 5: []")
        print(f"Maximum profit: {solution.maxProfit(prices5)}")
    
    main()

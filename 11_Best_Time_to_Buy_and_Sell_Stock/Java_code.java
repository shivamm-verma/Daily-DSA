// LeetCode Solution - Ready to submit
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

/*
// Alternative solution with more explicit comments
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        
        int minPrice = prices[0];  // Track minimum price seen so far
        int maxProfit = 0;         // Track maximum profit achievable
        
        for (int i = 1; i < prices.length; i++) {
            // Update minimum price seen so far
            minPrice = Math.min(minPrice, prices[i]);
            
            // Calculate profit if we sell at current price
            int currentProfit = prices[i] - minPrice;
            
            // Update maximum profit
            maxProfit = Math.max(maxProfit, currentProfit);
        }
        
        return maxProfit;
    }
}
*/

// For local testing (separate file: BestTimeToBuyAndSellStock.java)
/*
public class BestTimeToBuyAndSellStock {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test case 1
        int[] prices1 = {7, 1, 5, 3, 6, 4};
        System.out.println("Test case 1: [7,1,5,3,6,4]");
        System.out.println("Maximum profit: " + solution.maxProfit(prices1));
        
        // Test case 2
        int[] prices2 = {7, 6, 4, 3, 1};
        System.out.println("\nTest case 2: [7,6,4,3,1]");
        System.out.println("Maximum profit: " + solution.maxProfit(prices2));
        
        // Test case 3
        int[] prices3 = {1, 2, 3, 4, 5};
        System.out.println("\nTest case 3: [1,2,3,4,5]");
        System.out.println("Maximum profit: " + solution.maxProfit(prices3));
    }
}
*/

// LeetCode Solution - Ready to submit
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

/*
// Alternative solution with more explicit comments
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];  // Track minimum price seen so far
        int maxProfit = 0;         // Track maximum profit achievable
        
        for (int i = 1; i < prices.size(); i++) {
            // Update minimum price seen so far
            minPrice = min(minPrice, prices[i]);
            
            // Calculate profit if we sell at current price
            int currentProfit = prices[i] - minPrice;
            
            // Update maximum profit
            maxProfit = max(maxProfit, currentProfit);
        }
        
        return maxProfit;
    }
};
*/

// For local testing (not part of LeetCode submission)
#ifdef LOCAL_TEST
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test case 1: [7,1,5,3,6,4]" << endl;
    cout << "Maximum profit: " << solution.maxProfit(prices1) << endl;
    
    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "\nTest case 2: [7,6,4,3,1]" << endl;
    cout << "Maximum profit: " << solution.maxProfit(prices2) << endl;
    
    // Test case 3
    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "\nTest case 3: [1,2,3,4,5]" << endl;
    cout << "Maximum profit: " << solution.maxProfit(prices3) << endl;
    
    return 0;
}
#endif

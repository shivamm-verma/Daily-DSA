#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collecting_Water(vector<int>& heights) {
        int n = heights.size();
        if (n <= 2) {
            return 0;
        }
        
        int totalWater = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int leftMax = 0;
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, heights[j]);
            }
            
            int rightMax = 0;
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, heights[j]);
            }
            
            int waterLevel = min(leftMax, rightMax);
            
            if (waterLevel > heights[i]) {
                totalWater += waterLevel - heights[i];
            }
        }
        
        return totalWater;
    }
};
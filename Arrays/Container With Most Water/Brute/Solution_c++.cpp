#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxm = 0;        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = (j - i) * min(height[i], height[j]);
                maxm = max(maxm, area);
            }
        }
        return maxm;
    }
};

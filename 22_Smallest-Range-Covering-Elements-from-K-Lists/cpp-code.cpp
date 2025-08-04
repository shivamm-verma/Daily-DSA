#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int value;
    int list_idx;
    int elem_idx;
};
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.value > b.value;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, Compare> min_heap;
        int max_val = INT_MIN;
        int k = nums.size();
        for (int i = 0; i < k; ++i) {
            if (!nums[i].empty()) {
                min_heap.push({nums[i][0], i, 0});
                max_val = max(max_val, nums[i][0]);
            }
        }
        int range_start = -1;
        int min_range_size = INT_MAX;
        while (min_heap.size() == k) {
            Node current = min_heap.top();
            min_heap.pop();
            
            int min_val = current.value;
            int list_idx = current.list_idx;
            int elem_idx = current.elem_idx;

            if (max_val - min_val < min_range_size) {
                min_range_size = max_val - min_val;
                range_start = min_val;
            }

            if (elem_idx + 1 >= nums[list_idx].size()) {
                break;
            }

            int next_val = nums[list_idx][elem_idx + 1];
            min_heap.push({next_val, list_idx, elem_idx + 1});
            max_val = max(max_val, next_val);
        }
        return {range_start, range_start + min_range_size};
    }
};
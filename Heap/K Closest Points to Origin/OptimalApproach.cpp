#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxheap;
        for (int i=0;i<points.size();i++)
            {
                int x = points[i][0];
                int y = points[i][1];
                int dist = x*x + y*y;
                maxheap.push({dist, points[i]});
                if(maxheap.size()> k)
                {
                    maxheap.pop();
                }
            }
        vector<vector<int>> result;
        while (!maxheap.empty()) {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return result;
    }
};

int main() {
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2,4}};
    int k =2;
    Solution sol;
    vector<vector<int>> ans= sol.kClosest(points, k);

    cout<<"K Closest Points:";
    for (int i=0;i<ans.size();i++) {
        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"]";
    }
    cout<<endl;

    return 0;
}

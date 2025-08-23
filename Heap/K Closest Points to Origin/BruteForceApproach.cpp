#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> distPoints;
        for (int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y; // squared distance
            distPoints.push_back({dist, points[i]});
        }
        // Step 2: Sort by distance
        sort(distPoints.begin(), distPoints.end());

        // Step 3: Take first k points
        vector<vector<int>> result;
        for (int i=0;i<k;i++) {
            result.push_back(distPoints[i].second);
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

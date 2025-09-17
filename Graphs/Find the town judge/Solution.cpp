#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n + 1, 0);
        vector<int> indegree(n + 1, 0);

        for (auto &t : trust) {
            int a = t[0], b = t[1];
            outdegree[a]++;
            indegree[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << sol.findJudge(n, trust) << endl;  // Output: 3
    return 0;
}

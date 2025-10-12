#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b)
         { return a[0] < b[0]; });
    vector<vector<int>> new_intervals;
    vector<int> singleton;
    int start = intervals[0][0];
    int end = intervals[0][1];
    int n = intervals.size();
    if (n == 1)
    {
        new_intervals.push_back(intervals[0]);
        return new_intervals;
    }
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= end)
        {
            singleton.push_back(min(start, intervals[i][0]));
            singleton.push_back(max(intervals[i][1], end));
            start = min(start, intervals[i][0]);
            end = max(intervals[i][1], end);
        }
        else
        {
            if (new_intervals.empty())
            {
                new_intervals.push_back(intervals[0]);
            }
            singleton.push_back(intervals[i][0]);
            singleton.push_back(intervals[i][1]);
            start = intervals[i][0];
            end = intervals[i][1];
        }
        new_intervals.push_back(singleton);
        singleton.clear();
    }
    return new_intervals;
}

int main(){
    vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    vector<vector<int>> result = merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
    }   
    return 0;
}
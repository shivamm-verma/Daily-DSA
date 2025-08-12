#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;

    vector<pair<int,int>> freqList(freq.begin(), freq.end());
    sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(freqList[i].first);
    return result;
}


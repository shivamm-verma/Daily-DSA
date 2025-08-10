#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int i = 0, n = stations.size();
    long long curr = startFuel;
    int stops = 0;
    while (curr < target) {
        while (i < n && stations[i][0] <= curr) {
            pq.push(stations[i][1]);
            i++;
        }
        if (pq.empty()) return -1;
        curr += pq.top(); pq.pop();
        stops++;
    }
    return stops;
}

int main(){
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    cout<<minRefuelStops(100,10,stations)<<"\n"; // 2
}
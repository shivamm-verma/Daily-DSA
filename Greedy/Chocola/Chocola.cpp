#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> costVer = {2, 1, 3, 1, 4};  // vertical cuts
    vector<int> costHor = {4, 1, 2};     // horizontal cuts

    // sort in descending order
    sort(costVer.rbegin(), costVer.rend());
    sort(costHor.rbegin(), costHor.rend());

    int h = 0, v = 0;  
    int hp = 1, vp = 1; 
    int cost = 0;

    while (h < costHor.size() && v < costVer.size()) {
        if (costHor[h] >= costVer[v]) {
            cost += costHor[h] * vp;
            h++;
            hp++;
        } else {
            cost += costVer[v] * hp;
            v++;
            vp++;
        }
    }

    while (h < costHor.size()) {
        cost += costHor[h] * vp;
        h++;
        hp++;
    }

    while (v < costVer.size()) {
        cost += costVer[v] * hp;
        v++;
        vp++;
    }

    cout << "Total minimum cost: " << cost << endl;
    return 0;
}

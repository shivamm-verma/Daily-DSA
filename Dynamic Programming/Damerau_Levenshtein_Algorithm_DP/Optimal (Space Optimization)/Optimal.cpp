#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct OperationCosts {
    int insert_cost, delete_cost, replace_cost, transpose_cost;  
    OperationCosts(int ins=1, int del=1, int rep=1, int trans=1) 
        : insert_cost(ins), delete_cost(del), replace_cost(rep), transpose_cost(trans) {}
};

class DamerauLevenshtein {  
    int min3(int a, int b, int c) { return min(min(a, b), c); }
    int min4(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }

public:
    int distance(const string& s1, const string& s2, const OperationCosts& costs) {
        int m = s1.size(), n = s2.size();
        if (!m) return n * costs.insert_cost;
        if (!n) return m * costs.delete_cost;
        if (m > n) {
            OperationCosts swapped(costs.delete_cost, costs.insert_cost, costs.replace_cost, costs.transpose_cost);
            return distance(s2, s1, swapped);
        }
        vector<int> prev_prev(m+1), prev(m+1), curr(m+1);
        for (int i=0; i<=m; i++) prev[i] = i * costs.delete_cost;
        for (int j=1; j<=n; j++) {
            curr[0] = j * costs.insert_cost;
            for (int i=1; i<=m; i++) {
                if (s1[i-1] == s2[j-1]) curr[i] = prev[i-1];
                else {
                    int sub = prev[i-1] + costs.replace_cost;
                    int ins = curr[i-1] + costs.insert_cost;
                    int del = prev[i] + costs.delete_cost;
                    if (i>1 && j>1 && s1[i-1]==s2[j-2] && s1[i-2]==s2[j-1]) {
                        int trans = prev_prev[i-2] + costs.transpose_cost;
                        curr[i] = min4(sub, ins, del, trans);
                    } else curr[i] = min3(sub, ins, del);
                }
            }
            prev_prev = prev;
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    DamerauLevenshtein d;
    OperationCosts costs(1,1,1,1);
    cout << d.distance("kitten", "sitting", costs) << endl; // Output: 3
    cout << d.distance("martha", "marhta", costs) << endl;  // Output: 1
}

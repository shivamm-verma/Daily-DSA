#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DL_Result {
    int cost;
    vector<string> operations;
};

struct OperationCosts {
    int insert_cost, delete_cost, replace_cost, transpose_cost;
    OperationCosts(int ins=1, int del=1, int rep=1, int trans=1) : insert_cost(ins), delete_cost(del), replace_cost(rep), transpose_cost(trans) {}
};

int minimum_cost(int a, int b, int c) { return min(a, min(b, c)); }
int minimum_cost(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }

int damerauLevenshtein_Weighted_Cost_Only(const string& str1, const string& str2, const OperationCosts& costs) {
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) dp[i][0] = i * costs.delete_cost;
    for (int j = 0; j <= n; j++) dp[0][j] = j * costs.insert_cost;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int ins = dp[i][j - 1] + costs.insert_cost;
                int del = dp[i - 1][j] + costs.delete_cost;
                int rep = dp[i - 1][j - 1] + costs.replace_cost;
                if (i > 1 && j > 1 && str1[i - 1] == str2[j - 2] && str1[i - 2] == str2[j - 1]) {
                    int trans = dp[i - 2][j - 2] + costs.transpose_cost;
                    dp[i][j] = minimum_cost(ins, del, rep, trans);
                } else dp[i][j] = minimum_cost(ins, del, rep);
            }
        }
    }
    return dp[m][n];
}

DL_Result damerauLevenshtein_Weighted_Cost_And_Operation(const string& str1, const string& str2, const OperationCosts& costs) {
    int m = str1.length(), n = str2.length();
    vector<vector<DL_Result>> dp(m + 1, vector<DL_Result>(n + 1));
    for (int i = 0; i <= m; i++) {
        dp[i][0].cost = i * costs.delete_cost;
        for (int k = 0; k < i; k++) dp[i][0].operations.push_back("DELETE '" + string(1, str1[k]) + "'");
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j].cost = j * costs.insert_cost;
        for (int k = 0; k < j; k++) dp[0][j].operations.push_back("INSERT '" + string(1, str2[k]) + "'");
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].operations.push_back("MATCH '" + string(1, str1[i - 1]) + "'");
            } else {
                int ins = dp[i][j - 1].cost + costs.insert_cost;
                int del = dp[i - 1][j].cost + costs.delete_cost;
                int rep = dp[i - 1][j - 1].cost + costs.replace_cost;
                bool canTranspose = (i > 1 && j > 1 && str1[i - 1] == str2[j - 2] && str1[i - 2] == str2[j - 1]);
                if (canTranspose) {
                    int trans = dp[i - 2][j - 2].cost + costs.transpose_cost;
                    int minVal = minimum_cost(ins, del, rep, trans);
                    dp[i][j].cost = minVal;
                    if (minVal == trans) {
                        dp[i][j].operations = dp[i - 2][j - 2].operations;
                        dp[i][j].operations.push_back("TRANSPOSE");
                    } else if (minVal == rep) {
                        dp[i][j].operations = dp[i - 1][j - 1].operations;
                        dp[i][j].operations.push_back("REPLACE");
                    } else if (minVal == del) {
                        dp[i][j].operations = dp[i - 1][j].operations;
                        dp[i][j].operations.push_back("DELETE");
                    } else {
                        dp[i][j].operations = dp[i][j - 1].operations;
                        dp[i][j].operations.push_back("INSERT");
                    }
                } else {
                    int minVal = minimum_cost(ins, del, rep);
                    dp[i][j].cost = minVal;
                    if (minVal == rep) {
                        dp[i][j].operations = dp[i - 1][j - 1].operations;
                        dp[i][j].operations.push_back("REPLACE");
                    } else if (minVal == del) {
                        dp[i][j].operations = dp[i - 1][j].operations;
                        dp[i][j].operations.push_back("DELETE");
                    } else {
                        dp[i][j].operations = dp[i][j - 1].operations;
                        dp[i][j].operations.push_back("INSERT");
                    }
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "kitten", s2 = "sitting";
    OperationCosts costs;
    cout << "Distance: " << damerauLevenshtein_Weighted_Cost_Only(s1, s2, costs) << endl;
    DL_Result res = damerauLevenshtein_Weighted_Cost_And_Operation(s1, s2, costs);
    cout << "Detailed distance: " << res.cost << endl;
    for (auto& op : res.operations) cout << op << " ";
    cout << endl;
}

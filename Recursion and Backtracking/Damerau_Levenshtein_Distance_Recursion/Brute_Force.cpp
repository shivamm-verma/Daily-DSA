#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct DL_Result {
    int cost;
    vector<string> operations;
    DL_Result() : cost(0), operations({}) {}
    DL_Result(int c, vector<string> ops) : cost(c), operations(ops) {}
};

struct OperationCosts {
    int insert_cost, delete_cost, replace_cost, transpose_cost; 
    OperationCosts(int ins=1, int del=1, int rep=1, int trans=1) 
        : insert_cost(ins), delete_cost(del), replace_cost(rep), transpose_cost(trans) {}
};

int minimum_cost(int a, int b, int c) { return min(a, min(b, c)); }
int minimum_cost(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }

int damerauLevenshtein_Cost_Only(const string &str1, const string &str2, int i, int j, const OperationCosts &costs) {
    if (i == str1.length()) return (str2.length() - j) * costs.insert_cost;
    if (j == str2.length()) return (str1.length() - i) * costs.delete_cost;
    if (str1[i] == str2[j]) return damerauLevenshtein_Cost_Only(str1, str2, i + 1, j + 1, costs);
    int insertCost = costs.insert_cost + damerauLevenshtein_Cost_Only(str1, str2, i, j + 1, costs);
    int deleteCost = costs.delete_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 1, j, costs);
    int replaceCost = costs.replace_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 1, j + 1, costs);
    if (i + 1 < str1.length() && j + 1 < str2.length() && str1[i] == str2[j + 1] && str1[i + 1] == str2[j]) {
        int transposeCost = costs.transpose_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 2, j + 2, costs);
        return minimum_cost(insertCost, deleteCost, replaceCost, transposeCost);
    }
    return minimum_cost(insertCost, deleteCost, replaceCost);
}

DL_Result damerauLevenshtein_Cost_And_Operation(string str1, string str2, int i, int j, const OperationCosts &costs) {
    if (i == str1.length()) {
        vector<string> ops; int total_cost = 0;
        for (int k = j; k < str2.length(); k++) {
            ops.push_back("Insert '" + string(1, str2[k]) + "'");
            total_cost += costs.insert_cost;
        }
        return DL_Result(total_cost, ops);
    }
    if (j == str2.length()) {
        vector<string> ops; int total_cost = 0;
        for (int k = i; k < str1.length(); k++) {
            ops.push_back("Delete '" + string(1, str1[k]) + "'");
            total_cost += costs.delete_cost;
        }
        return DL_Result(total_cost, ops);
    }
    if (str1[i] == str2[j]) {
        DL_Result res = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j + 1, costs);
        res.operations.insert(res.operations.begin(), "Match '" + string(1, str1[i]) + "'");
        return res;
    }
    DL_Result insert_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i, j + 1, costs);
    insert_Op.cost += costs.insert_cost;
    insert_Op.operations.insert(insert_Op.operations.begin(), "Insert '" + string(1, str2[j]) + "'");
    DL_Result delete_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j, costs);
    delete_Op.cost += costs.delete_cost;
    delete_Op.operations.insert(delete_Op.operations.begin(), "Delete '" + string(1, str1[i]) + "'");
    DL_Result replace_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j + 1, costs);
    replace_Op.cost += costs.replace_cost;
    replace_Op.operations.insert(replace_Op.operations.begin(), "Replace '" + string(1, str1[i]) + "' with '" + string(1, str2[j]) + "'");
    if (i + 1 < str1.length() && j + 1 < str2.length() && str1[i] == str2[j + 1] && str1[i + 1] == str2[j]) {
        DL_Result transpose_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 2, j + 2, costs);
        transpose_Op.cost += costs.transpose_cost;
        transpose_Op.operations.insert(transpose_Op.operations.begin(), "Transpose '" + string(1, str1[i]) + string(1, str1[i + 1]) + "'");
        if (insert_Op.cost <= delete_Op.cost && insert_Op.cost <= replace_Op.cost && insert_Op.cost <= transpose_Op.cost) return insert_Op;
        else if (delete_Op.cost <= insert_Op.cost && delete_Op.cost <= replace_Op.cost && delete_Op.cost <= transpose_Op.cost) return delete_Op;
        else if (replace_Op.cost <= insert_Op.cost && replace_Op.cost <= delete_Op.cost && replace_Op.cost <= transpose_Op.cost) return replace_Op;
        else return transpose_Op;
    }
    if (insert_Op.cost <= delete_Op.cost && insert_Op.cost <= replace_Op.cost) return insert_Op;
    else if (delete_Op.cost <= insert_Op.cost && delete_Op.cost <= replace_Op.cost) return delete_Op;
    else return replace_Op;
}

int main() {
    OperationCosts costs(1,2,3,1);
    string s1 = "kitten", s2 = "sitting";
    cout << "Edit Distance: " << damerauLevenshtein_Cost_Only(s1, s2, 0, 0, costs) << "\n";
    DL_Result res = damerauLevenshtein_Cost_And_Operation(s1, s2, 0, 0, costs);
    cout << "Operations:\n"; 
    for (auto &op : res.operations) cout << op << "\n";
}

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
    int insert_cost;
    int delete_cost;
    int replace_cost;
    int transpose_cost; 
    
    OperationCosts() : insert_cost(1), delete_cost(1), replace_cost(1), transpose_cost(1) {}
    OperationCosts(int ins, int del, int rep, int trans) : insert_cost(ins), delete_cost(del), replace_cost(rep), transpose_cost(trans) {}
};


int minimum_cost(int a, int b, int c) {
    return min(a, min(b, c));
}

int minimum_cost(int a, int b, int c, int d) {  
    return min(min(a, b), min(c, d));
}


// Recursion Method - Return only the cost
// Time Complexity: O(4^N) - now includes transposition
// Space Complexity: O(N) {stack}
int damerauLevenshtein_Cost_Only(const string &str1, const string &str2, int i, int j, const OperationCosts &costs) {
    
    if (i == str1.length()) return (str2.length() - j) * costs.insert_cost;           
    if (j == str2.length()) return (str1.length() - i) * costs.delete_cost;           

    if (str1[i] == str2[j]) {              
        return damerauLevenshtein_Cost_Only(str1, str2, i + 1, j + 1, costs);
    }

    int insertCost = costs.insert_cost + damerauLevenshtein_Cost_Only(str1, str2, i, j + 1, costs);               
    int deleteCost = costs.delete_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 1, j, costs);               
    int replaceCost = costs.replace_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 1, j + 1, costs);          

    // Check for transposition (adjacent character swap)
    if (i + 1 < str1.length() && j + 1 < str2.length() && 
        str1[i] == str2[j + 1] && str1[i + 1] == str2[j]) {
        int transposeCost = costs.transpose_cost + damerauLevenshtein_Cost_Only(str1, str2, i + 2, j + 2, costs);
        return minimum_cost(insertCost, deleteCost, replaceCost, transposeCost);
    }

    return minimum_cost(insertCost, deleteCost, replaceCost);
}


// Recursion Method - Return cost + operations
// Time Complexity: O(4^N)
// Space Complexity: O(N^2) {stack + operations}
DL_Result damerauLevenshtein_Cost_And_Operation(string str1, string str2, int i, int j, const OperationCosts &costs) {

    if (i == str1.length()) {
        vector<string> ops;
        int total_cost = 0;
        for (int k = j; k < str2.length(); k++) {
            ops.push_back("Insert '" + string(1, str2[k]) + "' (cost: " + to_string(costs.insert_cost) + ")");
            total_cost += costs.insert_cost;
        }
        return DL_Result(total_cost, ops);
    }

    if (j == str2.length()) {
        vector<string> ops;
        int total_cost = 0;
        for (int k = i; k < str1.length(); k++) {
            ops.push_back("Delete '" + string(1, str1[k]) + "' (cost: " + to_string(costs.delete_cost) + ")");
            total_cost += costs.delete_cost;
        }
        return DL_Result(total_cost, ops);
    }

    if (str1[i] == str2[j]) {
        DL_Result res = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j + 1, costs);   
        res.operations.insert(res.operations.begin(), "Match '" + string(1, str1[i]) + "' (cost: 0)");
        return res;
    }

    DL_Result insert_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i, j + 1, costs);
    insert_Op.cost += costs.insert_cost;
    insert_Op.operations.insert(insert_Op.operations.begin(), "Insert '" + string(1, str2[j]) + "' (cost: " + to_string(costs.insert_cost) + ")");

    DL_Result delete_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j, costs);
    delete_Op.cost += costs.delete_cost;
    delete_Op.operations.insert(delete_Op.operations.begin(), "Delete '" + string(1, str1[i]) + "' (cost: " + to_string(costs.delete_cost) + ")");

    DL_Result replace_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 1, j + 1, costs);
    replace_Op.cost += costs.replace_cost;
    replace_Op.operations.insert(replace_Op.operations.begin(), "Replace '" + string(1, str1[i]) + "' with '" + string(1, str2[j]) + "' (cost: " + to_string(costs.replace_cost) + ")");

    // Check for transposition
    if (i + 1 < str1.length() && j + 1 < str2.length() && 
        str1[i] == str2[j + 1] && str1[i + 1] == str2[j]) {
        
        DL_Result transpose_Op = damerauLevenshtein_Cost_And_Operation(str1, str2, i + 2, j + 2, costs);
        transpose_Op.cost += costs.transpose_cost;
        transpose_Op.operations.insert(transpose_Op.operations.begin(), 
            "Transpose '" + string(1, str1[i]) + string(1, str1[i + 1]) + 
            "' to '" + string(1, str2[j]) + string(1, str2[j + 1]) + 
            "' (cost: " + to_string(costs.transpose_cost) + ")");

        // Find minimum among all four operations
        if (insert_Op.cost <= delete_Op.cost && insert_Op.cost <= replace_Op.cost && insert_Op.cost <= transpose_Op.cost)
            return insert_Op;
        else if (delete_Op.cost <= insert_Op.cost && delete_Op.cost <= replace_Op.cost && delete_Op.cost <= transpose_Op.cost)
            return delete_Op;
        else if (replace_Op.cost <= insert_Op.cost && replace_Op.cost <= delete_Op.cost && replace_Op.cost <= transpose_Op.cost)
            return replace_Op;
        else
            return transpose_Op;
    }

    // No transposition possible, choose among three operations
    if (insert_Op.cost <= delete_Op.cost && insert_Op.cost <= replace_Op.cost)
        return insert_Op;
    else if (delete_Op.cost <= insert_Op.cost && delete_Op.cost <= replace_Op.cost)
        return delete_Op;
    else
        return replace_Op;
}

OperationCosts getCosts() {
    int same_cost_choice;
    cout << "\n--- Operation Cost Configuration ---" << endl;
    cout << "Do all operations have the same cost? (yes=1 / no=0): ";
    cin >> same_cost_choice;
    
    if (same_cost_choice == 1) {
        int uniform_cost;
        cout << "Enter the cost for all operations (insert, delete, replace, transpose): ";
        cin >> uniform_cost;
        cout << "All operations will have cost: " << uniform_cost << "\n" << endl;
        return OperationCosts(uniform_cost, uniform_cost, uniform_cost, uniform_cost);
    } else {
        int insert_cost, delete_cost, replace_cost, transpose_cost;
        cout << "Enter the cost for insert operation: ";
        cin >> insert_cost;
        cout << "Enter the cost for delete operation: ";
        cin >> delete_cost;
        cout << "Enter the cost for replace operation: ";
        cin >> replace_cost;
        cout << "Enter the cost for transpose operation: ";  
        cin >> transpose_cost;
        
        return OperationCosts(insert_cost, delete_cost, replace_cost, transpose_cost);
    }
}

int EditDistance(string s1, string s2, const OperationCosts &costs) {
    int flag = 0;
    cout << "Do you want detailed operations? (yes=1 / no=0)" << endl;
    cout << "Enter your choice (1/0): ";
    cin >> flag;

    if (flag == 1) {
        DL_Result result = damerauLevenshtein_Cost_And_Operation(s1, s2, 0, 0, costs);
        cout << "\nOperations to convert '" << s1 << "' to '" << s2 << "':\n";
        for (const auto& op : result.operations)
            cout << " - " << op << "\n";
        cout << "\n";
        return result.cost;
    }

    return damerauLevenshtein_Cost_Only(s1, s2, 0, 0, costs);      
}


int main() {
    
    cout << "This is a C++ program to calculate the Damerau-Levenshtein distance with custom operation costs.\n\n\n";
    
    int numInputs;
    cout << "Enter the number of string pairs you want to process: ";
    cin >> numInputs;
    cout << "\n";

    for (int i = 1; i <= numInputs; i++) {
        string str1, str2;
        
        cout << "\n\n\n ***** ***** ***** ***** Pair " << i << " ***** ***** ***** ***** \n" << endl;
        
        // Get operation costs configuration
        OperationCosts costs = getCosts();
        cout << "Enter the first string (The original string): ";
        cin >> str1;
        cout << "Enter the second string (String to convert to): ";
        cin >> str2;
        cout << "\nResults for { Pair " << i << "}\n";
        int res = EditDistance(str1, str2, costs);
        cout << "Total Edit Distance for Pair " << i << ": " << res << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct LA_Result {
    int cost;
    vector<string> operations;
};

struct OperationCosts {
    int insert_cost;
    int delete_cost;
    int replace_cost;
    
    OperationCosts(): insert_cost(1), delete_cost(1), replace_cost(1) {}
    OperationCosts(int ins, int del, int rep) : insert_cost(ins), delete_cost(del), replace_cost(rep) {}
};

int minimum_cost(int a, int b, int c) {
    return min(a, min(b, c));
} 



OperationCosts getCosts() {
    int same_cost_choice;
    cout << "\n--- Operation Cost Configuration ---" << endl;
    cout << "Do all operations have the same cost? (yes=1 / no=0): ";
    cin >> same_cost_choice;
    
    if (same_cost_choice == 1) {
        int uniform_cost;
        cout << "Enter the cost for all operations (insert, delete, replace): ";
        cin >> uniform_cost;
        cout << "All operations will have cost: " << uniform_cost << "\n" << endl;
        return OperationCosts(uniform_cost, uniform_cost, uniform_cost);
    } else {
        int insert_cost, delete_cost, replace_cost;
        cout << "Enter the cost for insert operation: ";
        cin >> insert_cost;
        cout << "Enter the cost for delete operation: ";
        cin >> delete_cost;
        cout << "Enter the cost for replace operation: ";
        cin >> replace_cost;
        return OperationCosts(insert_cost, delete_cost, replace_cost);
    }
}



// DP Matrix Method with different operational costs - Return only the cost
// Time Complexity: O(M * N)    - traversing the matrix
// Space Complexity: O(M * N)   - 2D matrix
int levenshtein_Weighted_Cost_Only(const string& str1, const string& str2, const OperationCosts& costs) {

    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp_Matrix(m + 1, vector<int>(n + 1));   // Space Complexity: O(M * N)

    for (int i = 0; i <= m; i++) {
        dp_Matrix[i][0] = i * costs.delete_cost;
    }

    for (int j = 0; j <= n; j++) {
        dp_Matrix[0][j] = j * costs.insert_cost;
    }

    // Fill the dp matrix
    for (int i = 1; i <= m; i++) {              // Time Complexity: O(M)
        for (int j = 1; j <= n; j++) {              // Time Complexity: O(M*N)    
            if (str1[i - 1] == str2[j - 1]) {
                dp_Matrix[i][j] = dp_Matrix[i - 1][j - 1];
            } else {
                int ins = dp_Matrix[i][j - 1] + costs.insert_cost;
                int del = dp_Matrix[i - 1][j] + costs.delete_cost;
                int rep = dp_Matrix[i - 1][j - 1] + costs.replace_cost;

                dp_Matrix[i][j] = minimum_cost(ins, del, rep);
            }
        }
    }

    return dp_Matrix[m][n];
}

// Overloaded version for backward compatibility
int levenshtein_Weighted_Cost_Only(const string& str1, const string& str2, int insert_Cost, int delete_Cost, int replace_Cost) {
    OperationCosts costs(insert_Cost, delete_Cost, replace_Cost);
    return levenshtein_Weighted_Cost_Only(str1, str2, costs);
}



// DP Matrix Method with different operational costs - Return the cost and operations
// Time Complexity: O(M * N)            Traversing the matrix
// Space Complexity: O(2(M * N))       2D matrix + operations vector 
LA_Result levenshtein_Weighted_Cost_And_Operation(const string& str1, const string& str2, const OperationCosts& costs) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<LA_Result>> dp_Matrix(m + 1, vector<LA_Result>(n + 1));

    for (int i = 0; i <= m; i++) {
        dp_Matrix[i][0].cost = i * costs.delete_cost;
        for (int k = 0; k < i; k++)
            dp_Matrix[i][0].operations.push_back("DELETE '" + string(1, str1[k]) + "'");
    }

    for (int j = 0; j <= n; j++) {
        dp_Matrix[0][j].cost = j * costs.insert_cost;
        for (int k = 0; k < j; k++)
            dp_Matrix[0][j].operations.push_back("INSERT '" + string(1, str2[k]) + "'");
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp_Matrix[i][j] = dp_Matrix[i - 1][j - 1];
                dp_Matrix[i][j].cost = dp_Matrix[i - 1][j - 1].cost;
                dp_Matrix[i][j].operations.push_back("MATCH '" + string(1, str1[i - 1]) + "'");
            } else {
                int ins = dp_Matrix[i][j - 1].cost + costs.insert_cost;
                int del = dp_Matrix[i - 1][j].cost + costs.delete_cost;
                int rep = dp_Matrix[i - 1][j - 1].cost + costs.replace_cost;

                int minVal = minimum_cost(ins, del, rep);
                dp_Matrix[i][j].cost = minVal;

                if (minVal == rep) {
                    dp_Matrix[i][j].operations = dp_Matrix[i - 1][j - 1].operations;
                    dp_Matrix[i][j].operations.push_back("REPLACE '" + string(1, str1[i - 1]) + "' with '" + string(1, str2[j - 1]) + "'");
                }
                else if (minVal == del) {
                    dp_Matrix[i][j].operations = dp_Matrix[i - 1][j].operations;
                    dp_Matrix[i][j].operations.push_back("DELETE '" + string(1, str1[i - 1]) + "'");
                }
                else {
                    dp_Matrix[i][j].operations = dp_Matrix[i][j - 1].operations;
                    dp_Matrix[i][j].operations.push_back("INSERT '" + string(1, str2[j - 1]) + "'");
                }
            }
        }
    }

    return dp_Matrix[m][n];
}

// Overloaded version for backward compatibility
LA_Result levenshtein_Weighted_Cost_And_Operation(const string& str1, const string& str2, int insert_Cost, int delete_Cost, int replace_Cost) {
    OperationCosts costs(insert_Cost, delete_Cost, replace_Cost);
    return levenshtein_Weighted_Cost_And_Operation(str1, str2, costs);
}



int EditDistance(const string& s1, const string& s2, const OperationCosts& costs) {
    int flag = 0;
    cout << "Do you want detailed operations? (yes=1 / no=0): ";
    cin >> flag;

    if (flag == 1) {
        LA_Result result = levenshtein_Weighted_Cost_And_Operation(s1, s2, costs);
        cout << "\nOperations to convert '" << s1 << "' to '" << s2 << "':\n";
        for (const auto& op : result.operations)
            cout << " - " << op << "\n";
        cout << "\n";
        return result.cost;
    }

    return levenshtein_Weighted_Cost_Only(s1, s2, costs);
}

// Overloaded version for backward compatibility
int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
    OperationCosts costs(Ci, Cd, Cs);
    return EditDistance(s1, s2, costs);
}



int main() {
    cout << "This is a C++ program to calculate the Weighted Levenshtein distance.";

    int numInputs;
    cout << "\n\nEnter the number of string pairs you want to process: ";
    cin >> numInputs;
    cout << "\n";

    for (int i = 1; i <= numInputs; i++) {
        string str1, str2;

        cout << "\n\n\n ***** ***** ***** ***** Pair " << i << " ***** ***** ***** ***** \n" << endl;
        cout << "Enter the first string (The original string): ";
        cin >> str1;
        cout << "Enter the second string (String to convert to): ";
        cin >> str2;
        
        OperationCosts costs = getCosts();
        
        cout << "\nResults for { Pair " << i << " }\n";
        int res = EditDistance(str1, str2, costs);
        cout << "Levenshtein Distance for Pair " << i << ": " << res << endl;
    }

    return 0;
}

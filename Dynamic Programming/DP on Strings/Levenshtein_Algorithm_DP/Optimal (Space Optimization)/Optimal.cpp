#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


struct OperationCosts {
    int insert_cost;
    int delete_cost;
    int replace_cost;
    
    OperationCosts(): insert_cost(1), delete_cost(1), replace_cost(1) {}
    OperationCosts(int ins, int del, int rep) : insert_cost(ins), delete_cost(del), replace_cost(rep) {}
};

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



class Levenshtein_Distance {

    int minimum_Cost(int a, int b) {
        return (a <= b) ? a : b;
    }

    int minimum_Cost(int a, int b, int c) {
        return min(min(a, b), c);
    }
    
    void print_Vector(const vector<int>& vec, const string& label) {
        cout << label << ": [";
        for (int i = 0; i < vec.size(); i++) {
            cout << setw(3) << vec[i];
            if (i < vec.size() - 1) cout << ",";
        }
        cout << " ]" << endl;
    }
    

public:

    // DP Vector Method with different operational costs - Return only the cost
    // Time Complexity: O(M * N)    - traversing over str1 for each letter in str2

    // Space Complexity: O(2(min(M,N)))   - 2 vectors 
    
    // {As in the task_2 (DP Matrix), only last 2 rows were needed, previous one and current one to perform the calculations}
    // Time Comp can't be reduced further, as we need to traverse both the strings and compare characters of one with other.
    // 2 loops are needed, for such traversal.

    int levenshtein_Space_Optimized_Cost(const string& str1, const string& str2, const OperationCosts& costs) {
        
        int m = str1.length();
        int n = str2.length();
        
        if (m == 0) return n * costs.insert_cost;
        if (n == 0) return m * costs.delete_cost;

        cout << "\nString 1: \"" << str1 << "\" (length: " << m << ")" << endl;
        cout << "String 2: \"" << str2 << "\" (length: " << n << ")" << endl;
        cout << "Costs - Insert: " << costs.insert_cost << ", Delete: " << costs.delete_cost << ", Replace: " << costs.replace_cost << endl;
        
        // str1 should be the shorter string for space optimization
        if (m > n) {
            cout << "\nSwapping strings for space optimization..." << endl;
            OperationCosts swapped_costs(costs.delete_cost, costs.insert_cost, costs.replace_cost);
            return levenshtein_Space_Optimized_Cost(str2, str1, swapped_costs);
        }
        
        vector<int> prev(m + 1);
        vector<int> curr(m + 1, 0);
    
        cout << "\n\nInitializing base cases for deletions:" << endl;
        for (int i = 0; i <= m; i++) {
            prev[i] = i * costs.delete_cost;
        }
        
        cout << "prev[i] (cost of deleting 'i' characters)" << endl;
        print_Vector(prev, "Initial prev vector");
        
        for (int j = 1; j <= n; j++) {
            cout << "\n**** Processing column " << j << " (character '" << str2[j-1] << "') ****" << endl;
            
            curr[0] = j * costs.insert_cost;
            cout << "curr[0] = " << curr[0] << " (cost of inserting " << j << " characters)" << endl;
            
            for (int i = 1; i <= m; i++) {
                cout << "Comparing " << str1[i-1] << " with "<< str2[j-1] << "':";
                
                if (str1[i-1] == str2[j-1]) {
                    curr[i] = prev[i-1];
                    cout << "  MATCH! No cost added. curr[" << i << "] = prev[" << (i-1) << "] = " << curr[i] << endl;
                } else {
                    int substitute_OP = prev[i-1] + costs.replace_cost;
                    int insert_OP = curr[i-1] + costs.insert_cost;
                    int del_OP = prev[i] + costs.delete_cost;
                    
                    cout << "  NO MATCH.";
                    
                    curr[i] = minimum_Cost(substitute_OP, insert_OP, del_OP);
                    cout << "    Minimum cost: " << curr[i];
                    
                    if (curr[i] == substitute_OP) cout << " (substitute_OP)";
                    else if (curr[i] == insert_OP) cout << " (insert_OP)";
                    else cout << " (delete)";
                    cout << endl;
                }
            }
            
            print_Vector(curr, "Current curr vector");
            
            prev = curr;
        }
        
        return prev[m];
    }

    // Overloaded version with individual cost parameters for backward compatibility
    int levenshtein_Space_Optimized_Cost(const string& str1, const string& str2, int insert_Cost = 1, int delete_Cost = 1, int substitute_Cost = 1) {
        OperationCosts costs(insert_Cost, delete_Cost, substitute_Cost);
        return levenshtein_Space_Optimized_Cost(str1, str2, costs);
    }

};



int main() {

    cout << "This is a C++ program to calculate the Weighted Levenshtein distance, with space optimisation and detailed logging.\n\n\n";
    Levenshtein_Distance temp;

    int num_Inputs;
    cout << "Enter the number of string pairs you want to process: ";
    cin >> num_Inputs;
    cout << "\n";

    for (int i = 1; i <= num_Inputs; i++) {
        string str1, str2;

        cout << "\n\n\n ***** ***** ***** ***** Pair " << i << " ***** ***** ***** ***** \n" << endl;
        cout << "Enter the first string (The original string): ";
        cin >> str1;
        cout << "Enter the second string (String to convert to): ";
        cin >> str2;
        
        OperationCosts costs = getCosts();
        
        int res = temp.levenshtein_Space_Optimized_Cost(str1, str2, costs);
        
        cout << "\n\nMinimum edit distance: " << res << endl;
    }

    return 0;
}
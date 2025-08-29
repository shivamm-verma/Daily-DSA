from typing import List, Tuple

class LAResult:
    def __init__(self, cost: int = 0, operations: List[str] = None):
        self.cost = cost
        self.operations = operations if operations is not None else []

class OperationCosts:
    def __init__(self, insert_cost: int = 1, delete_cost: int = 1, replace_cost: int = 1):
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost

def minimum_cost(a: int, b: int, c: int) -> int:
    return min(a, b, c)

def get_costs() -> OperationCosts:
    print("\n--- Operation Cost Configuration ---")
    same_cost_choice = int(input("Do all operations have the same cost? (yes=1 / no=0): "))
    
    if same_cost_choice == 1:
        uniform_cost = int(input("Enter the cost for all operations (insert, delete, replace): "))
        print(f"All operations will have cost: {uniform_cost}\n")
        return OperationCosts(uniform_cost, uniform_cost, uniform_cost)
    else:
        insert_cost = int(input("Enter the cost for insert operation: "))
        delete_cost = int(input("Enter the cost for delete operation: "))
        replace_cost = int(input("Enter the cost for replace operation: "))
        return OperationCosts(insert_cost, delete_cost, replace_cost)

def levenshtein_weighted_cost_only(str1: str, str2: str, costs: OperationCosts) -> int:
    """
    DP Matrix Method with different operational costs - Return only the cost
    Time Complexity: O(M * N)    - traversing the matrix
    Space Complexity: O(M * N)   - 2D matrix
    """
    m = len(str1)
    n = len(str2)
    
    # Initialize DP matrix
    dp_matrix = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Initialize first column
    for i in range(m + 1):
        dp_matrix[i][0] = i * costs.delete_cost
    
    # Initialize first row
    for j in range(n + 1):
        dp_matrix[0][j] = j * costs.insert_cost
    
    # Fill the dp matrix
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                dp_matrix[i][j] = dp_matrix[i - 1][j - 1]
            else:
                ins = dp_matrix[i][j - 1] + costs.insert_cost
                delete = dp_matrix[i - 1][j] + costs.delete_cost
                replace = dp_matrix[i - 1][j - 1] + costs.replace_cost
                
                dp_matrix[i][j] = minimum_cost(ins, delete, replace)
    
    return dp_matrix[m][n]

def levenshtein_weighted_cost_and_operation(str1: str, str2: str, costs: OperationCosts) -> LAResult:
    """
    DP Matrix Method with different operational costs - Return the cost and operations
    Time Complexity: O(M * N)            Traversing the matrix
    Space Complexity: O(2(M * N))       2D matrix + operations vector
    """
    m = len(str1)
    n = len(str2)
    
    # Initialize DP matrix with LAResult objects
    dp_matrix = [[LAResult() for _ in range(n + 1)] for _ in range(m + 1)]
    
    # Initialize first column
    for i in range(m + 1):
        dp_matrix[i][0].cost = i * costs.delete_cost
        for k in range(i):
            dp_matrix[i][0].operations.append(f"DELETE '{str1[k]}'")
    
    # Initialize first row
    for j in range(n + 1):
        dp_matrix[0][j].cost = j * costs.insert_cost
        for k in range(j):
            dp_matrix[0][j].operations.append(f"INSERT '{str2[k]}'")
    
    # Fill the dp matrix
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                dp_matrix[i][j].cost = dp_matrix[i - 1][j - 1].cost
                dp_matrix[i][j].operations = dp_matrix[i - 1][j - 1].operations.copy()
                dp_matrix[i][j].operations.append(f"MATCH '{str1[i - 1]}'")
            else:
                ins = dp_matrix[i][j - 1].cost + costs.insert_cost
                delete = dp_matrix[i - 1][j].cost + costs.delete_cost
                replace = dp_matrix[i - 1][j - 1].cost + costs.replace_cost
                
                min_val = minimum_cost(ins, delete, replace)
                dp_matrix[i][j].cost = min_val
                
                if min_val == replace:
                    dp_matrix[i][j].operations = dp_matrix[i - 1][j - 1].operations.copy()
                    dp_matrix[i][j].operations.append(f"REPLACE '{str1[i - 1]}' with '{str2[j - 1]}'")
                elif min_val == delete:
                    dp_matrix[i][j].operations = dp_matrix[i - 1][j].operations.copy()
                    dp_matrix[i][j].operations.append(f"DELETE '{str1[i - 1]}'")
                else:
                    dp_matrix[i][j].operations = dp_matrix[i][j - 1].operations.copy()
                    dp_matrix[i][j].operations.append(f"INSERT '{str2[j - 1]}'")
    
    return dp_matrix[m][n]

def edit_distance(s1: str, s2: str, costs: OperationCosts) -> int:
    flag = int(input("Do you want detailed operations? (yes=1 / no=0): "))
    
    if flag == 1:
        result = levenshtein_weighted_cost_and_operation(s1, s2, costs)
        print(f"\nOperations to convert '{s1}' to '{s2}':")
        for op in result.operations:
            print(f" - {op}")
        print()
        return result.cost
    
    return levenshtein_weighted_cost_only(s1, s2, costs)

def main():
    print("This is a Python program to calculate the Weighted Levenshtein distance.")
    
    num_inputs = int(input("\n\nEnter the number of string pairs you want to process: "))
    print()
    
    for i in range(1, num_inputs + 1):
        print(f"\n\n\n ***** ***** ***** ***** Pair {i} ***** ***** ***** ***** \n")
        str1 = input("Enter the first string (The original string): ")
        str2 = input("Enter the second string (String to convert to): ")
        
        costs = get_costs()
        
        print(f"\nResults for {{ Pair {i} }}")
        res = edit_distance(str1, str2, costs)
        print(f"Levenshtein Distance for Pair {i}: {res}")

if __name__ == "__main__":
    main()
class LAResult:
    def __init__(self, cost=0, operations=None):
        self.cost = cost
        self.operations = operations if operations is not None else []


class OperationCosts:
    def __init__(self, insert_cost=1, delete_cost=1, replace_cost=1):
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost


def minimum_cost(a, b, c):
    return min(a, b, c)


# Recursion Method - Return only the cost
# Time Complexity: O(3^N)
# Space Complexity: O(N) {stack}
def levenshtein_cost_only(str1, str2, i, j, costs):
    
    if i == len(str1):
        return (len(str2) - j) * costs.insert_cost
    if j == len(str2):
        return (len(str1) - i) * costs.delete_cost
    
    if str1[i] == str2[j]:
        return levenshtein_cost_only(str1, str2, i + 1, j + 1, costs)
    
    insert_cost = costs.insert_cost + levenshtein_cost_only(str1, str2, i, j + 1, costs)
    delete_cost = costs.delete_cost + levenshtein_cost_only(str1, str2, i + 1, j, costs)
    replace_cost = costs.replace_cost + levenshtein_cost_only(str1, str2, i + 1, j + 1, costs)
    
    return minimum_cost(insert_cost, delete_cost, replace_cost)


# Recursion Method - Return cost + operations
# Time Complexity: O(3^N)
# Space Complexity: O(N^2) {stack + operations}
def levenshtein_cost_and_operation(str1, str2, i, j, costs):
    
    if i == len(str1):
        ops = []
        total_cost = 0
        for k in range(j, len(str2)):
            ops.append(f"Insert '{str2[k]}' (cost: {costs.insert_cost})")
            total_cost += costs.insert_cost
        return LAResult(total_cost, ops)
    
    if j == len(str2):
        ops = []
        total_cost = 0
        for k in range(i, len(str1)):
            ops.append(f"Delete '{str1[k]}' (cost: {costs.delete_cost})")
            total_cost += costs.delete_cost
        return LAResult(total_cost, ops)
    
    if str1[i] == str2[j]:
        result = levenshtein_cost_and_operation(str1, str2, i + 1, j + 1, costs)
        result.operations.insert(0, f"Match '{str1[i]}' (cost: 0)")
        return result
    
    insert_op = levenshtein_cost_and_operation(str1, str2, i, j + 1, costs)
    insert_op.cost += costs.insert_cost
    insert_op.operations.insert(0, f"Insert '{str2[j]}' (cost: {costs.insert_cost})")
    
    delete_op = levenshtein_cost_and_operation(str1, str2, i + 1, j, costs)
    delete_op.cost += costs.delete_cost
    delete_op.operations.insert(0, f"Delete '{str1[i]}' (cost: {costs.delete_cost})")
    
    replace_op = levenshtein_cost_and_operation(str1, str2, i + 1, j + 1, costs)
    replace_op.cost += costs.replace_cost
    replace_op.operations.insert(0, f"Replace '{str1[i]}' with '{str2[j]}' (cost: {costs.replace_cost})")
    
    if insert_op.cost <= delete_op.cost and insert_op.cost <= replace_op.cost:
        return insert_op
    elif delete_op.cost <= insert_op.cost and delete_op.cost <= replace_op.cost:
        return delete_op
    else:
        return replace_op


def get_costs():
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


def edit_distance(s1, s2, costs):
    print("Do you want detailed operations? (yes=1 / no=0)")
    flag = int(input("Enter your choice (1/0): "))
    
    if flag == 1:
        result = levenshtein_cost_and_operation(s1, s2, 0, 0, costs)
        print(f"\nOperations to convert '{s1}' to '{s2}':")
        for op in result.operations:
            print(f" - {op}")
        print()
        return result.cost
    
    return levenshtein_cost_only(s1, s2, 0, 0, costs)


def main():
    print("This is a Python program to calculate the Levenshtein distance with custom operation costs.\n\n")
    
    num_inputs = int(input("Enter the number of string pairs you want to process: "))
    print()
    
    for i in range(1, num_inputs + 1):
        print(f"\n\n\n ***** ***** ***** ***** Pair {i} ***** ***** ***** ***** \n")
        
        # Get operation costs configuration
        costs = get_costs()
        
        str1 = input("Enter the first string (The original string): ")
        str2 = input("Enter the second string (String to convert to): ")
        
        print(f"\nResults for {{ Pair {i} }}")
        res = edit_distance(str1, str2, costs)
        print(f"Total Edit Distance for Pair {i}: {res}")


if __name__ == "__main__":
    main()
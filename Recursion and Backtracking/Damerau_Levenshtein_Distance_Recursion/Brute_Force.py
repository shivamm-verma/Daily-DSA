class DLResult:
    def __init__(self, cost=0, operations=None):
        self.cost = cost
        self.operations = operations if operations is not None else []

class OperationCosts:
    def __init__(self, insert_cost=1, delete_cost=1, replace_cost=1, transpose_cost=1):
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost
        self.transpose_cost = transpose_cost

def minimum_cost(a, b, c): return min(a, b, c)
def minimum_cost_four(a, b, c, d): return min(a, b, c, d)

def damerau_levenshtein_cost_only(str1, str2, i, j, costs):
    if i == len(str1): return (len(str2) - j) * costs.insert_cost
    if j == len(str2): return (len(str1) - i) * costs.delete_cost
    if str1[i] == str2[j]: return damerau_levenshtein_cost_only(str1, str2, i+1, j+1, costs)
    insert_cost = costs.insert_cost + damerau_levenshtein_cost_only(str1, str2, i, j+1, costs)
    delete_cost = costs.delete_cost + damerau_levenshtein_cost_only(str1, str2, i+1, j, costs)
    replace_cost = costs.replace_cost + damerau_levenshtein_cost_only(str1, str2, i+1, j+1, costs)
    if i+1 < len(str1) and j+1 < len(str2) and str1[i] == str2[j+1] and str1[i+1] == str2[j]:
        transpose_cost = costs.transpose_cost + damerau_levenshtein_cost_only(str1, str2, i+2, j+2, costs)
        return minimum_cost_four(insert_cost, delete_cost, replace_cost, transpose_cost)
    return minimum_cost(insert_cost, delete_cost, replace_cost)

def damerau_levenshtein_cost_and_operation(str1, str2, i, j, costs):
    if i == len(str1):
        return DLResult((len(str2)-j)*costs.insert_cost, [f"Insert '{c}'" for c in str2[j:]])
    if j == len(str2):
        return DLResult((len(str1)-i)*costs.delete_cost, [f"Delete '{c}'" for c in str1[i:]])
    if str1[i] == str2[j]:
        res = damerau_levenshtein_cost_and_operation(str1, str2, i+1, j+1, costs)
        res.operations.insert(0, f"Match '{str1[i]}'")
        return res
    insert_op = damerau_levenshtein_cost_and_operation(str1, str2, i, j+1, costs)
    insert_op.cost += costs.insert_cost; insert_op.operations.insert(0, f"Insert '{str2[j]}'")
    delete_op = damerau_levenshtein_cost_and_operation(str1, str2, i+1, j, costs)
    delete_op.cost += costs.delete_cost; delete_op.operations.insert(0, f"Delete '{str1[i]}'")
    replace_op = damerau_levenshtein_cost_and_operation(str1, str2, i+1, j+1, costs)
    replace_op.cost += costs.replace_cost; replace_op.operations.insert(0, f"Replace '{str1[i]}' with '{str2[j]}'")
    if i+1 < len(str1) and j+1 < len(str2) and str1[i] == str2[j+1] and str1[i+1] == str2[j]:
        transpose_op = damerau_levenshtein_cost_and_operation(str1, str2, i+2, j+2, costs)
        transpose_op.cost += costs.transpose_cost; transpose_op.operations.insert(0, f"Transpose '{str1[i]}{str1[i+1]}'")
        return min([insert_op, delete_op, replace_op, transpose_op], key=lambda x: x.cost)
    return min([insert_op, delete_op, replace_op], key=lambda x: x.cost)

def edit_distance(s1, s2, costs, detailed=False):
    if detailed:
        return damerau_levenshtein_cost_and_operation(s1, s2, 0, 0, costs)
    return DLResult(damerau_levenshtein_cost_only(s1, s2, 0, 0, costs))

def main():
    costs = OperationCosts()
    res = edit_distance("kitten", "sitting", costs, detailed=True)
    print("Cost:", res.cost)
    print("Operations:", res.operations)

if __name__ == "__main__":
    main()

from typing import List

class DLResult:
    def __init__(self, cost: int = 0, operations: List[str] = None):
        self.cost = cost
        self.operations = operations if operations else []

class OperationCosts:
    def __init__(self, insert_cost=1, delete_cost=1, replace_cost=1, transpose_cost=1):
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost
        self.transpose_cost = transpose_cost

def minimum_cost(a, b, c): return min(a, b, c)
def minimum_cost_four(a, b, c, d): return min(a, b, c, d)

def damerau_levenshtein_weighted_cost_only(str1: str, str2: str, costs: OperationCosts) -> int:
    m, n = len(str1), len(str2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1): dp[i][0] = i * costs.delete_cost
    for j in range(n + 1): dp[0][j] = j * costs.insert_cost
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                ins = dp[i][j - 1] + costs.insert_cost
                delete = dp[i - 1][j] + costs.delete_cost
                replace = dp[i - 1][j - 1] + costs.replace_cost
                if i > 1 and j > 1 and str1[i - 1] == str2[j - 2] and str1[i - 2] == str2[j - 1]:
                    transpose = dp[i - 2][j - 2] + costs.transpose_cost
                    dp[i][j] = minimum_cost_four(ins, delete, replace, transpose)
                else:
                    dp[i][j] = minimum_cost(ins, delete, replace)
    return dp[m][n]

def damerau_levenshtein_weighted_cost_and_operation(str1: str, str2: str, costs: OperationCosts) -> DLResult:
    m, n = len(str1), len(str2)
    dp = [[DLResult() for _ in range(n + 1)] for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0].cost = i * costs.delete_cost
        for k in range(i): dp[i][0].operations.append(f"DELETE '{str1[k]}'")
    for j in range(n + 1):
        dp[0][j].cost = j * costs.insert_cost
        for k in range(j): dp[0][j].operations.append(f"INSERT '{str2[k]}'")
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j].cost = dp[i - 1][j - 1].cost
                dp[i][j].operations = dp[i - 1][j - 1].operations.copy()
                dp[i][j].operations.append(f"MATCH '{str1[i - 1]}'")
            else:
                ins = dp[i][j - 1].cost + costs.insert_cost
                delete = dp[i - 1][j].cost + costs.delete_cost
                replace = dp[i - 1][j - 1].cost + costs.replace_cost
                if i > 1 and j > 1 and str1[i - 1] == str2[j - 2] and str1[i - 2] == str2[j - 1]:
                    transpose = dp[i - 2][j - 2].cost + costs.transpose_cost
                    min_val = minimum_cost_four(ins, delete, replace, transpose)
                    if min_val == transpose:
                        dp[i][j].cost, dp[i][j].operations = transpose, dp[i - 2][j - 2].operations.copy()
                        dp[i][j].operations.append(f"TRANSPOSE")
                    elif min_val == replace:
                        dp[i][j].cost, dp[i][j].operations = replace, dp[i - 1][j - 1].operations.copy()
                        dp[i][j].operations.append(f"REPLACE")
                    elif min_val == delete:
                        dp[i][j].cost, dp[i][j].operations = delete, dp[i - 1][j].operations.copy()
                        dp[i][j].operations.append(f"DELETE")
                    else:
                        dp[i][j].cost, dp[i][j].operations = ins, dp[i][j - 1].operations.copy()
                        dp[i][j].operations.append(f"INSERT")
                else:
                    min_val = minimum_cost(ins, delete, replace)
                    if min_val == replace:
                        dp[i][j].cost, dp[i][j].operations = replace, dp[i - 1][j - 1].operations.copy()
                        dp[i][j].operations.append(f"REPLACE")
                    elif min_val == delete:
                        dp[i][j].cost, dp[i][j].operations = delete, dp[i - 1][j].operations.copy()
                        dp[i][j].operations.append(f"DELETE")
                    else:
                        dp[i][j].cost, dp[i][j].operations = ins, dp[i][j - 1].operations.copy()
                        dp[i][j].operations.append(f"INSERT")
    return dp[m][n]

if __name__ == "__main__":
    s1, s2 = "kitten", "sitting"
    costs = OperationCosts()
    print("Distance:", damerau_levenshtein_weighted_cost_only(s1, s2, costs))
    res = damerau_levenshtein_weighted_cost_and_operation(s1, s2, costs)
    print("Detailed distance:", res.cost)
    for op in res.operations: print(op)

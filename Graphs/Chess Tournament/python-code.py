from collections import defaultdict

def dfs(node, visited, graph, gold):
    visited[node] = True
    total = gold[node]
    for nei in graph[node]:
        if not visited[nei]:
            total += dfs(nei, visited, graph, gold)
    return total

def maxGold(N, gold, tunnels):
    graph = defaultdict(list)
    for u, v in tunnels:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * N
    max_gold = 0

    for i in range(N):
        if not visited[i]:
            total = dfs(i, visited, graph, gold)
            max_gold = max(max_gold, total)
    return max_gold

# Example
N = 5
gold = [2, 5, 7, 1, 3]
tunnels = [[0, 1], [1, 2], [2, 3], [3, 4]]
print(maxGold(N, gold, tunnels))  # Output: 18

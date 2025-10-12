def dfs(node, adj, gold, visited):
    """Depth-First Search to sum up gold in a connected component."""
    visited[node] = True
    total = gold[node]
    for nei in adj[node]:
        if not visited[nei]:
            total += dfs(nei, adj, gold, visited)
    return total


def max_gold_vault():
    """Main function to read input and calculate maximum gold."""
    n = int(input().strip())
    gold = list(map(int, input().strip().split()))
    e = int(input().strip())

    # Build adjacency list
    adj = [[] for _ in range(n)]
    for _ in range(e):
        u, v = map(int, input().strip().split())
        adj[u].append(v)
        adj[v].append(u)

    visited = [False] * n
    max_gold = 0

    for i in range(n):
        if not visited[i]:
            max_gold = max(max_gold, dfs(i, adj, gold, visited))

    print(max_gold)


# Run the program
if __name__ == "__main__":
    max_gold_vault()
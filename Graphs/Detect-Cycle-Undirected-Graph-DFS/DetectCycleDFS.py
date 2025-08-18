def dfs(node, parent, visited, graph):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            if dfs(neighbor, node, visited, graph):
                return True
        elif neighbor != parent:
            return True
    return False

def has_cycle(V, graph):
    visited = [False] * V
    for i in range(V):
        if not visited[i]:
            if dfs(i, -1, visited, graph):
                return True
    return False

if __name__ == "__main__":
    V = 4
    graph = [[] for _ in range(V)]

    # Example graph: 0-1, 1-2, 2-0
    graph[0].append(1)
    graph[1].append(0)

    graph[1].append(2)
    graph[2].append(1)

    graph[2].append(0)
    graph[0].append(2)

    print("Cycle exists" if has_cycle(V, graph) else "No cycle")

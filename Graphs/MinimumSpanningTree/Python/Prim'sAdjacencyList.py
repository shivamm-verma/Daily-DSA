import heapq

class PrimAdjacencyList:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))

    def mst(self):
        key = [float('inf')] * self.V
        parent = [-1] * self.V
        in_mst = [False] * self.V
        key[0] = 0

        pq = [(0, 0)]  # (weight, vertex)

        while pq:
            _, u = heapq.heappop(pq)
            if in_mst[u]:
                continue
            in_mst[u] = True

            for v, w in self.adj[u]:
                if not in_mst[v] and w < key[v]:
                    key[v] = w
                    parent[v] = u
                    heapq.heappush(pq, (key[v], v))

        return [(parent[v], v, key[v]) for v in range(1, self.V)]

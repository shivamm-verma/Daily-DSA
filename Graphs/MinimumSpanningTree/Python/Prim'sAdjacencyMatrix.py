class PrimAdjacencyMatrix:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u][v] = w
        self.graph[v][u] = w

    def mst(self):
        key = [float('inf')] * self.V
        parent = [-1] * self.V
        in_mst = [False] * self.V
        key[0] = 0

        for _ in range(self.V - 1):
            u = min((i for i in range(self.V) if not in_mst[i]), key=lambda x: key[x])
            in_mst[u] = True

            for v in range(self.V):
                if self.graph[u][v] and not in_mst[v] and self.graph[u][v] < key[v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u

        return [(parent[v], v, key[v]) for v in range(1, self.V)]

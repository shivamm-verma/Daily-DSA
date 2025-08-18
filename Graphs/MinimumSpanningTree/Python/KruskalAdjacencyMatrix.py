class KruskalAdjacencyMatrix:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = [[0] * vertices for _ in range(vertices)]
        self.parent = []
        self.rank = []

    def add_edge(self, u, v, w):
        self.adj[u][v] = w
        self.adj[v][u] = w

    def find(self, u):
        if u != self.parent[u]:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def unite(self, u, v):
        pu, pv = self.find(u), self.find(v)
        if pu != pv:
            if self.rank[pu] < self.rank[pv]:
                pu, pv = pv, pu
            self.parent[pv] = pu
            if self.rank[pu] == self.rank[pv]:
                self.rank[pu] += 1

    def mst(self):
        edges = []
        for i in range(self.V):
            for j in range(i + 1, self.V):
                if self.adj[i][j] != 0:
                    edges.append((self.adj[i][j], i, j))
        edges.sort()

        self.parent = [i for i in range(self.V)]
        self.rank = [0] * self.V

        mst_edges = []
        for w, u, v in edges:
            if self.find(u) != self.find(v):
                self.unite(u, v)
                mst_edges.append((u, v, w))
        return mst_edges

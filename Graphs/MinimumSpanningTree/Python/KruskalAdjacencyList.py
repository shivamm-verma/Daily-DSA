class KruskalAdjacencyList:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = [[] for _ in range(vertices)]
        self.parent = []
        self.rank = []

    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))

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
        for u in range(self.V):
            for v, w in self.adj[u]:
                if u < v:
                    edges.append((w, u, v))
        edges.sort()

        self.parent = [i for i in range(self.V)]
        self.rank = [0] * self.V

        mst_edges = []
        for w, u, v in edges:
            if self.find(u) != self.find(v):
                self.unite(u, v)
                mst_edges.append((u, v, w))
        return mst_edges

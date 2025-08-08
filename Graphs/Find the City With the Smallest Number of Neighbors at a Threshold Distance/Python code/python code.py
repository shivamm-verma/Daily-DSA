import sys

def findTheCity(n, edges, distanceThreshold):
    dist = [[sys.maxsize] * n for _ in range(n)]
    
    for u, v, wt in edges:
        dist[u][v] = wt
        dist[v][u] = wt

    for i in range(n):
        dist[i][i] = 0

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] == sys.maxsize or dist[k][j] == sys.maxsize:
                    continue
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    cityCnt = n + 1
    cityNo = -1

    for i in range(n):
        cnt = 0
        for j in range(n):
            if dist[i][j] <= distanceThreshold:
                cnt += 1
        if cnt <= cityCnt:
            cityCnt = cnt
            cityNo = i

    return cityNo

# Test
n = 4
edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]
distanceThreshold = 4
print(findTheCity(n, edges, distanceThreshold))

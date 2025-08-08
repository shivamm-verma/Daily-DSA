import collections

class Solution:
    def secureCity(self, grid):
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        protected = [[False for _ in range(n)] for _ in range(m)]
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 'B':
                    for i in range(r + 1, m):
                        if grid[i][c] == 'O': break
                        protected[i][c] = True
                    for i in range(r - 1, -1, -1):
                        if grid[i][c] == 'O': break
                        protected[i][c] = True
                    for j in range(c + 1, n):
                        if grid[r][j] == 'O': break
                        protected[r][j] = True
                    for j in range(c - 1, -1, -1):
                        if grid[r][j] == 'O': break
                        protected[r][j] = True
        visited = [[False for _ in range(n)] for _ in range(m)]
        regions = 0
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 'E' and not protected[r][c] and not visited[r][c]:
                    regions += 1
                    q = collections.deque([(r, c)])
                    visited[r][c] = True
                    while q:
                        row, col = q.popleft()
                        for dr, dc in directions:
                            nr, nc = row + dr, col + dc
                            if 0 <= nr < m and 0 <= nc < n and \
                               grid[nr][nc] == 'E' and not protected[nr][nc] and not visited[nr][nc]:
                                visited[nr][nc] = True
                                q.append((nr, nc))
        return regions

if __name__ == "__main__":
    m, n = map(int, input().split())
    grid = []
    for _ in range(m):
        grid.append(list(input().split()))
    sol = Solution()
    print(sol.secureCity(grid))
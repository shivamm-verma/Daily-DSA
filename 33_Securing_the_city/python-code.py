import sys

def secure_city(grid: list[str]) -> int:
    if not grid or not grid[0]:
        return 0
    rows, cols = len(grid), len(grid[0])
    buildings = []
    empty_cells = set()
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 'B':
                buildings.append((r, c))
            elif grid[r][c] == '.':
                empty_cells.add((r, c))
    if not empty_cells:
        return 0
    building_coverage = {}
    for r_b, c_b in buildings:
        coverage = set()
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r_b + dr, c_b + dc
            while 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] != 'O' and grid[nr][nc] != 'B':
                if grid[nr][nc] == '.':
                    coverage.add((nr, nc))
                nr += dr
                nc += dc
        building_coverage[(r_b, c_b)] = coverage
    uncovered_cells = empty_cells.copy()
    laser_count = 0
    while uncovered_cells:
        best_building = None
        max_coverage_count = 0
        cells_to_cover_by_best = set()
        for building, coverage_set in building_coverage.items():
            currently_covered = uncovered_cells.intersection(coverage_set)
            if len(currently_covered) > max_coverage_count:
                max_coverage_count = len(currently_covered)
                best_building = building
                cells_to_cover_by_best = currently_covered
        if max_coverage_count == 0:
            return -1
        laser_count += 1
        uncovered_cells -= cells_to_cover_by_best
        if best_building:
            del building_coverage[best_building]
    return laser_count

if __name__ == "__main__":
    try:
        rows, cols = map(int, sys.stdin.readline().split())
        grid = [sys.stdin.readline().strip() for _ in range(rows)]
        result = secure_city(grid)
        print(result)
    except (IOError, ValueError) as e:
        print(f"Invalid input: {e}")
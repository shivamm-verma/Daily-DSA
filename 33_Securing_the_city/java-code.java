import java.util.*;

public class Main {
    record Point(int r, int c) {}
    public int secureCity(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        List<Point> buildings = new ArrayList<>();
        Set<Point> emptyCells = new HashSet<>();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 'B') {
                    buildings.add(new Point(r, c));
                } else if (grid[r][c] == '.') {
                    emptyCells.add(new Point(r, c));
                }
            }
        }
        if (emptyCells.isEmpty()) {
            return 0;
        }
        Map<Point, Set<Point>> buildingCoverage = new HashMap<>();
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        for (Point building : buildings) {
            Set<Point> coverage = new HashSet<>();
            for (int i = 0; i < 4; i++) {
                int nr = building.r + dr[i];
                int nc = building.c + dc[i];
                while (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != 'O' && grid[nr][nc] != 'B') {
                    if (grid[nr][nc] == '.') {
                        coverage.add(new Point(nr, nc));
                    }
                    nr += dr[i];
                    nc += dc[i];
                }
            }
            buildingCoverage.put(building, coverage);
        }
        Set<Point> uncoveredCells = new HashSet<>(emptyCells);
        int laserCount = 0;
        while (!uncoveredCells.isEmpty()) {
            Point bestBuilding = null;
            Set<Point> cellsToCoverByBest = new HashSet<>();
            int maxCoverageCount = 0;
            for (Map.Entry<Point, Set<Point>> entry : buildingCoverage.entrySet()) {
                Point building = entry.getKey();
                Set<Point> coverageSet = entry.getValue();
                Set<Point> intersection = new HashSet<>(uncoveredCells);
                intersection.retainAll(coverageSet);
                if (intersection.size() > maxCoverageCount) {
                    maxCoverageCount = intersection.size();
                    bestBuilding = building;
                    cellsToCoverByBest = intersection;
                }
            }
            if (maxCoverageCount == 0) {
                return -1;
            }
            laserCount++;
            uncoveredCells.removeAll(cellsToCoverByBest);
            if (bestBuilding != null) {
                buildingCoverage.remove(bestBuilding);
            }
        }
        return laserCount;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        char[][] grid = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            grid[i] = scanner.next().toCharArray();
        }
        Main solution = new Main();
        int result = solution.secureCity(grid);
        System.out.println(result);
        scanner.close();
    }
}
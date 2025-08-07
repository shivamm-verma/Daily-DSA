#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Point {
    int r, c;
    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
};

class Solution {
public:
    int secureCity(const vector<string>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        vector<Point> buildings;
        set<Point> emptyCells;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 'B') {
                    buildings.push_back({r, c});
                } else if (grid[r][c] == '.') {
                    emptyCells.insert({r, c});
                }
            }
        }
        if (emptyCells.empty()) {
            return 0;
        }
        map<Point, set<Point>> buildingCoverage;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (const auto& building : buildings) {
            set<Point> coverage;
            for (int i = 0; i < 4; ++i) {
                int nr = building.r + dr[i];
                int nc = building.c + dc[i];
                while (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != 'O' && grid[nr][nc] != 'B') {
                    if (grid[nr][nc] == '.') {
                        coverage.insert({nr, nc});
                    }
                    nr += dr[i];
                    nc += dc[i];
                }
            }
            buildingCoverage[building] = coverage;
        }        
        set<Point> uncoveredCells = emptyCells;
        int laserCount = 0;
        while (!uncoveredCells.empty()) {
            auto best_building_it = buildingCoverage.end();
            size_t maxCoverageCount = 0;            
            for (auto it = buildingCoverage.begin(); it != buildingCoverage.end(); ++it) {
                vector<Point> intersection;
                set_intersection(it->second.begin(), it->second.end(),
                                 uncoveredCells.begin(), uncoveredCells.end(),
                                 back_inserter(intersection));
                if (intersection.size() > maxCoverageCount) {
                    maxCoverageCount = intersection.size();
                    best_building_it = it;
                }
            }
            if (maxCoverageCount == 0) {
                return -1;
            }
            laserCount++;
            const set<Point>& cellsToCover = best_building_it->second;
            for (const auto& p : cellsToCover) {
                uncoveredCells.erase(p);
            }            
            buildingCoverage.erase(best_building_it);
        }
        return laserCount;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    for (int i = 0; i < rows; ++i) {
        cin >> grid[i];
    }
    Solution sol;
    int result = sol.secureCity(grid);
    cout << result << endl;
    return 0;
}
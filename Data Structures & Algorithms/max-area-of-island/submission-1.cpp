class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxArea = 0, area = 0;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;

        if (grid[i][j] == 0) return;

        grid[i][j] = 0; area++;
        maxArea = max(maxArea, area);

        for (auto& dir : dirs) {
            dfs(grid, i + dir.first, j + dir.second);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                dfs(grid, i, j); area = 0;
            }
        }

        return maxArea;
    }
};

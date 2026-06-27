class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>>& q) {
        while (!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();

            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) continue;

            if (grid[i][j] < d) continue;

            grid[i][j] = d;

            for (auto& dir : dirs) {
                q.push({i + dir.first, j + dir.second, d + 1});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) continue;
                q.push({i, j, 0});
            }
        }

        bfs(grid, q);
    }
};

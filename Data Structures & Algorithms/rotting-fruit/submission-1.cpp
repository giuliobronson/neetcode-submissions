class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int fresh = 0;

    int bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>>& q) {
        while(!q.empty()) {
            auto [i, j, t] = q.front(); q.pop();

            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j]) continue;

            if (grid[i][j] == 1) fresh--;

            grid[i][j] = 0;

            if (!fresh) return t;

            for (auto dir : dirs) {
                q.push({i + dir.first, j + dir.second, t + 1});
            }
        }

        return -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }

        if (!fresh) return 0;

        return bfs(grid, q);
    }
};

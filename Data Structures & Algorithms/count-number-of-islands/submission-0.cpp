class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size()) return;

        if (visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        for (auto dir : dirs) {
            dfs(grid, visited, i + dir.first, j + dir.second);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;;
                dfs(grid, visited, i, j);
                count++;
            }
        }

        return count;
    }   
};

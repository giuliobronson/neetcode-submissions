class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;

        if (heights[i][j] < prev || ocean[i][j]) return;

        ocean[i][j] = true;

        for (auto& dir: dirs) {
            dfs(heights, ocean, i + dir.first, j + dir.second, heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>  pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> res;

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacific, i, 0, -INT_MAX);
            dfs(heights, atlantic, i, heights[0].size() - 1, -INT_MAX);
        } 

        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, pacific, 0, j, -INT_MAX);
            dfs(heights, atlantic, heights.size() - 1, j, -INT_MAX);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                cout << pacific[i][j] << " ";
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
            cout << '\n';
        }

        return res; 
    }
};

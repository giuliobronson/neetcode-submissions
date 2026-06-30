class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& edge, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

        if (board[i][j] == 'X' || edge[i][j]) return;

        edge[i][j] = true;

        for (auto& dir : dirs) {
            dfs(board, edge, i + dir.first, j + dir.second);
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> edge(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            dfs(board, edge, i, 0);
            dfs(board, edge, i, board[0].size() - 1);
        }

        for (int j = 0; j < board[0].size(); j++) {
            dfs(board, edge, 0, j);
            dfs(board, edge, board.size() - 1, j);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X' || edge[i][j]) continue;
                board[i][j] = 'X';
            }
        }
    }
};
